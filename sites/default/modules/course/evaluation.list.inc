<?php


function evaluation_edit_description($form_state, $node){
  if($node->type != 'course'){
    return;
  }

  $form['course_nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $form['body_field']['evaluation_description'] = array(
    '#type'   => 'textarea',
    '#title'  => t('Evaluation Description'),
    '#default_value' => $node->evaluation_description,
    '#rows'          => 4,
    '#required'      => FALSE,
    '#weight'        => -2,
    '#description'   => t('Changes will only be applied to evaluations in Draft state.  Final evaluations will have to be re-submitted in order to reflect changes in the evaluation description.'),
  );

  $form['body_field']['format'] = filter_form($node->format);
  $form['body_field']['#prefix'] = '<div class="body-field-wrapper">';
  $form['body_field']['#suffix'] = '</div>';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );


  return $form;
}


function evaluation_edit_description_submit($form, &$form_state) {
  $query = "UPDATE {courses} SET evaluation_description = '%s' WHERE nid = %d";
  db_query($query, $form_state['values']['evaluation_description'], $form_state['values']['course_nid']);
  $form_state['redirect'] = "node/" . $form_state['values']['course_nid']. "/evaluations/list";
}



function evaluation_list_evaluations($form_state, $node){
  if($node->type != 'course'){
    return theme('evaluation_list_evaluations',$form);
  }

  $can_complete_initialization = evaluation_can_complete_initialization($node);
  $can_submit_final = evaluation_can_submit_final($node);
  $can_view_student_names = evaluation_can_view_student_names($node);
  $can_unlock_evals = user_access('unlock evaluations');
  $can_view_exam_type = user_access('view exam types');
  $can_view_evaluations = evaluation_can_view_evaluations($node);
  $can_reset_grade = (user_access('can reset grade') && $node->evaluations_initialized);
  $current_registration_terms = course_get_current_banner_registration_terms();
  $can_drop_student = (user_access('can drop student') && !isset($current_registration_terms[$node->registration_term]));

  $evaluations = array();
  foreach(evaluation_get_evaluations($node->nid) as $eval_nid => $eval_data){
    $evaluation_node = node_load($eval_nid);
    $eval = array(
      'nid' => $eval_nid,
      'vid' => $evaluation_node->vid,
      'can_update'  => evaluation_can_update($evaluation_node),
      'is_locked'   => $evaluation_node->is_locked,
      'manual_entry' => $evaluation_node->manual_entry,
      'exam_number' => $evaluation_node->exam_number,
      'exam_type'   => $evaluation_node->exam_type,
      'grade' => '',
      'notes' => '',
      'last_edited_count'     => 0,
      'last_edited_timestamp' => 0,
      'last_edited_uid'       => -1,
      'final_timestamp'       => 0,
      'final_submitted_by'    => '',
      'final_count'           => 0,
    );

    if($can_view_student_names){
      $eval['student'] = $eval_data['student'];
    }
    

    if($evaluation_node->revision_count > 0){
      $eval['grade']                 = $evaluation_node->grade;
      $eval['notes']                 = $evaluation_node->notes;
      $eval['last_edited_count']     = $evaluation_node->revision_count;
      $eval['last_edited_timestamp'] = $evaluation_node->revision_timestamp;
      $eval['last_edited_uid']       = $evaluation_node->revision_uid;

      $eval['final_count'] = count($evaluation_node->final_submissions);
      if($eval['final_count'] == 0){
        //eval has not been submitted yet
        if($can_submit_final){
          $final_options[$eval_nid] = '';
        }    
      }
      else{
        $eval['final_timestamp'] = $evaluation_node->final_submissions[0]['timestamp'];
        $eval['final_submitted_name'] = $evaluation_node->final_submissions[0]['submitted_name'];

        //eval has been submitted, so it has the option to be unlocked
        if($can_unlock_evals){
          $lock_options[$eval_nid] = '';
          $lock_values[$eval_nid] = $evaluation_node->is_locked ? '' : $eval_nid;
        }
      }
    }
    $evaluations[] = $eval;
  }

  $form['can_view_student_names'] = array(
    '#type' => 'value',
    '#value' => $can_view_student_names,
  );

  
  $form['can_view_evaluations'] = array(
    '#type' => 'value',
    '#value' => $can_view_evaluations,
  );

  $form['can_view_exam_type'] = array(
    '#type' => 'value',
    '#value' => $can_view_exam_type,
  );

  $form['can_drop_student'] = array(
    '#type' => 'value',
    '#value' => $can_drop_student,
  );

  $form['can_reset_grade'] = array(
    '#type' => 'value',
    '#value' => $can_reset_grade,
  );

  $form['course_nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  $form['evaluations'] = array(
    '#type' => 'value',
    '#value' => $evaluations,
  );

  $form['evaluation_description_link'] = array(
    '#type' => 'item',
    '#value' => l(t('Edit Evaluation Description'),'node/'.$node->nid . '/evaluations/description'),
    '#weight' => -15,
  );

  if($can_submit_final && !empty($final_options)){
    $form['final_checkboxes'] = array(
      '#type' => 'checkboxes', 
      '#options' => $final_options,
    );

    $form['submit_final'] = array(
      '#type' => 'submit', 
      '#value' => t('Submit Final')
    );
  }

  if($can_unlock_evals && !empty($lock_options)){
    $form['lock_checkboxes'] = array(
      '#type' => 'checkboxes', 
      '#options' => $lock_options,
      '#default_value' => $lock_values,
    );

    $form['submit_locks'] = array(
      '#type' => 'submit', 
      '#value' => t('Set Locks')
    );
  }

  if($can_complete_initialization){
    $form['submit_initialize'] = array(
      '#type' => 'submit', 
      '#value' => t('Complete Initialization'),
    );
  }

  if($can_view_evaluations){
    $form['submit_view_all'] = array(
      '#type' => 'submit', 
      '#value' => t('View All Evaluations'),
    );
    $form['submit_view_all_notes'] = array(
      '#type' => 'submit',
      '#value' => t('View All Notes'),
    );
  }

  $form['submit_pdf_list'] = array(
    '#type' => 'submit',
    '#value' => t('PDF of List'),
  );


  $form['sort'] = array(
    '#type' => 'value',
    '#value' => _evaluation_list_get_sort(),
  );
  $form['order'] = array(
    '#type' => 'value',
    '#value' => _evaluation_list_get_order(),
  );

  
  return $form;
 // return theme('evaluation_list_evaluations',$form);
}


function evaluation_list_evaluations_submit($form, &$form_state) {
  if(isset($form_state['clicked_button']['#post']['final_checkboxes'])){
    module_load_include('inc', 'evaluation', 'evaluation.final');
    foreach($form_state['clicked_button']['#post']['final_checkboxes'] as $eval_nid){
      if($eval_nid != 0){
        $eval = node_load($eval_nid);
        $course = node_load($eval->author_group_nid);
        $form_state = array();
        $form_state['values'] = array(
          'comment'     => "[FIRST SUBMISSION]",
          'op'          => t('Submit')
        );
        drupal_execute('evaluation_finalize_form', $form_state, $eval, $course);
      }
    }
  }

  switch($form_state['values']['op']){
  case t('Set Locks'):
    foreach($form_state['values']['lock_checkboxes'] as $eval_nid => $val){
      if($val == 0){
        evaluation_lock($eval_nid);
      }
      else{
        evaluation_unlock($eval_nid);
      }
    }
    break;
  case t('Complete Initialization'):
    $form_state['redirect'] = "node/" . $form_state['values']['course_nid']. "/evaluations/initialize";
    break;
  case t('View All Evaluations'):
    $evaluations = $form_state['values']['evaluations'];
    $order = $form_state['values']['order'];
    $sort = $form_state['values']['sort'];
    _evaluation_sort_evaluations($evaluations, $sort, $order);

    evaluation_view_all_evaluations_pdf($evaluations);
    break; 
  case t('View All Notes'):
    $evaluations = $form_state['values']['evaluations'];
    $order = $form_state['values']['order'];
    $sort = $form_state['values']['sort'];
    _evaluation_sort_evaluations($evaluations, $sort, $order);

    evaluation_view_all_notes_pdf($evaluations);
    break;
  case t('PDF of List'):
    $node0 = node_load($form_state['values']['evaluations'][0]['nid']);
    if(isset($node0->author_group_nid)){
      $course = node_load($node0->author_group_nid);
    }
    $values = $form_state['values'];
    $values['course'] = $course;
    
    $order = $form_state['values']['order'];
    $sort = $form_state['values']['sort'];
  
    evaluation_list_pdf($course, $values, $order, $sort);
    break; 
  }
}


function evaluation_view_all_evaluations_pdf($evaluations){
  $i=0;
  
  foreach($evaluations as $eval){
    $add_file = FALSE;
    $node = node_load($eval['nid']);
    $course = node_load($node->author_group_nid);
    $i++;
    if($eval['final_count'] > 0){
      //view final
      $add_file = TRUE;
      $pdf = evaluation_get_final_pdf($node, $course);
/*
      db_set_active('final_evaluations');
      $query = "SELECT pdf FROM {final_evaluations} WHERE registered_course_crn = %d AND student_nuid = '%s' ORDER BY timestamp DESC";
      $pdf = db_decode_blob(db_result(db_query($query, $course->crn, $node->student_nuid)));
      db_set_active('default');
*/
    }
    else if($eval['last_edited_count'] > 0){
      //view draft
      $add_file = TRUE;
      $pdf = evaluation_get_draft_pdf($node, $course);
/*
      $values['timestamp'] = $eval['last_edited_timestamp'];
      $values['can_view_student_names'] = evaluation_can_view_student_names($course);
      $values['course'] = $course;
      $values['node'] = $node;
      $values['title'] = $eval['exam_number'];

      $evaluation_draft_template = drupal_get_path('module', 'print') . '/print_pdf.node-evaluation.tpl.php';
      $pdf = print_pdf_custom_template($evaluation_draft_template, $values);
*/
    }
    if($add_file){
      if($i < 10){
      $filename = $course->crn . '_0' . $i . '.pdf';
      }
      else{
        $filename = $course->crn . '_' . $i . '.pdf';
      }
      file_put_contents("/tmp/". $filename, $pdf);
    }
  }
  $filename = $course->crn;
  //exec('pdftk /tmp/' . $course->crn . '_*.pdf cat output -', $cat_pdf);
  exec('pdftk /tmp/' . $course->crn . '_*.pdf cat output /tmp/' . $filename . '.pdf');
  $cat_pdf = file_get_contents('/tmp/'.$course->crn . '.pdf');
  evaluation_show_pdf($cat_pdf, $filename);
  exec('rm -f /tmp/' .$course->crn . '*.pdf');

}


function evaluation_view_all_notes_pdf($evaluations){
  $i = 0;
  foreach($evaluations as $eval){
    $i++;
    $node = node_load($eval['nid']);
    $course = node_load($node->author_group_nid);
    if($eval['notes'] != '' && $eval['notes'] != '<p></p>'){
      $pdf = evaluation_view_notes_pdf($node, $course);
      $filename = $course->crn . '_notes_' . $i . '.pdf';
      file_put_contents("/tmp/". $filename, $pdf);
    }
  }
  $filename = $course->crn . '_notes';
  exec('pdftk /tmp/' . $course->crn . '_notes_*.pdf cat output /tmp/' . $filename . '.pdf');
  $cat_pdf = file_get_contents('/tmp/' . $filename . '.pdf');
  evaluation_show_pdf($cat_pdf, $filename);


}


function evaluation_list_pdf($course, $values, $order, $sort){
  _evaluation_sort_evaluations($values['evaluations'], $sort, $order);
  $evaluation_list_template = drupal_get_path('module', 'course') .'/evaluation-list.tpl.php';
  $pdf = print_pdf_custom_template($evaluation_list_template, $values);
  $filename = 'evaluation_list_' . $course->title;
  evaluation_show_pdf($pdf, $filename);
}


function theme_evaluation_list_evaluations($form){
  $headers = array();
  if($form['can_view_student_names']['#value']){
    $header[] = array(
      'data'  => 'Student',
      'field' => 'student'
    );
  }
  $header[] = array(
    'data'  => 'Exam Number',
    'field' => 'exam_number'
  );
  if($form['can_view_exam_type']['#value']){
    $header[] = 'Type';
  }
  if($form['can_view_evaluations']['#value']){
    $header[] = 'Grade';
  }
  $header[] = array(
    'data'  => 'Last Edited',
    'field' => 'last_edited'
  );
  $header[] = 'Final';
  if(isset($form['submit_locks'])){
    $header[] = 'Unlock';
  }
  if($form['can_view_evaluations']['#value']){
    $header[] = 'Operations';
  }
        
  $attributes = array(
    'border'      => 1,
    'cellspacing' => 0,
    'cellpadding' => 5,
  );


  $contains_manual_entry = FALSE;
  $rows = array();
  foreach($form['evaluations']['#value'] as $eval){
    if($eval['manual_entry']){
      $contains_manual_entry = TRUE;
    }
    if($eval['can_update']){
      $operations = l('Edit', 'node/'.$eval['nid'].'/edit');
    }
    else{
      $operations = '';
    }
    if($form['can_drop_student']['#value']){
      $operations .= "<br>" . l('Drop Student', 'node/' . $eval['nid'] . '/delete', array('query' => 'destination=node/' . $form['course_nid']['#value'] . '/evaluations/list'));
    }
    if($form['can_reset_grade']['#value']){
      $operations .= "<br>" . l('Reset Grade', 'node/' . $form['course_nid']['#value'] . '/og/evaluation/' . $eval['nid'] . '/reset_grade');
    } 
    if($eval['last_edited_count'] > 0 && $form['can_view_evaluations']['#value']){
      if($eval['notes'] != '' && $eval['notes'] != '<p></p>'){
        $operations.= "<br>".l('View Notes', 'node/'.$form['course_nid']['#value'].'/og/evaluation/'.$eval['nid'].'/view_notes');
      }
      //make sure that there is a draft to be viewed since the last submitted final, and the user can view evaluations
      if(!$eval['is_locked']){
        //$operations.= "<br>".l('View Draft', 'printpdf/'.$eval['nid'], array('attributes' => array('target' => '_BLANK')));
        $operations.= "<br>".l('View Draft', 'node/'. $form['course_nid']['#value'] . '/og/evaluation/' . $eval['nid'] . '/view_draft', array('attributes' => array('target' => '_BLANK')));
      }
    }

    $row = array();
    if($form['can_view_student_names']['#value']){
      $row['student'] = $eval['manual_entry'] ? '*' . $eval['student'] : $eval['student'];
    }
    $row['exam_number'] = $eval['manual_entry'] ? '*' . $eval['exam_number'] : $eval['exam_number'];

    if($form['can_view_exam_type']['#value']){
      $row['type'] = $eval['exam_type'];
    }

    if($form['can_view_evaluations']['#value']){
      $row['grade'] = $eval['grade'];
    }

    if($eval['last_edited_count'] == 0){
      $row['last_edited'] = '';
      $row['Final'] = '';
      if(isset($form['submit_locks'])){
        $row['Unlock'] = '';
      }
    }
    else{
      $row['last_edited'] = array(
        "data" => l($eval['last_edited_count'] . " revisions", '/node/'.$eval['nid'] .'/revisions') . "<br>" . format_date($eval['last_edited_timestamp'], "small") ."<br>" . theme('username', user_load($eval['last_edited_uid']), 'normal', 1), 
        "timestamp" => $eval['last_edited_timestamp'],
      );

      //if(isset($form['final_checkboxes'][$eval['nid']])){
      if($eval['final_count'] == 0){
        $row['Final'] = drupal_render($form['final_checkboxes'][$eval['nid']]);
        if(isset($form['submit_locks'])){
          $row['Unlock'] = '';
        }
      }
      else{
        if($form['can_view_evaluations']['#value']){
          $operations.= "<br>".l('View Final', 'node/'.$form['course_nid']['#value'].'/og/evaluation/'.$eval['nid'].'/view_final');
        }
        if($eval['final_count'] == 1){
          $row['Final'] = '1 submission' .'<br>';
        }
        else{
          $row['Final'] = $eval['final_count'] .' submissions' .'<br>';
        }
        $row['Final'] .= format_date($eval['final_timestamp'], "small") . '<br>';
        $row['Final'] .= $eval['final_submitted_name'];

        if(isset($form['submit_locks'])){
          $row['Unlock'] = drupal_render($form['lock_checkboxes'][$eval['nid']]); 
        }

      }
    }
    if($form['can_view_evaluations']['#value']){
      $row['Operations'] = $operations;
    }
    
    $rows[] = $row;
  }
  
  $sort = tablesort_get_sort($header);
  $order = tablesort_get_order($header);

 
  _evaluation_sort_evaluations($rows, $sort, $order);

  $row = array('&nbsp', '&nbsp');

  if($form['can_view_student_names']['#value']){
    //student name column
    $row[] = '&nbsp';
  }
  if($form['can_view_exam_type']['#value']){
    //type column
    $row[] = '&nbsp';
  }
  if($form['can_view_evaluations']['#value']){
    //grade column
    $row[] = '&nbsp';
  }
  if(isset($form['submit_final'])){
    $row[] = drupal_render($form['submit_final']);
  }
  else{
    $row[] = '&nbsp';
  }
  if(isset($form['submit_locks'])){
    $row[] = drupal_render($form['submit_locks']);
  }
  if($form['can_view_evaluations']['#value']){
    //operations column
    $row[] = '&nbsp';
  }
  $rows[] = $row;

  $output = drupal_render($form);
  $output .= theme('table', $header, $rows, $attributes);
  if($contains_manual_entry){
    $output .= "<br>*Evaluation was entered manually";
  }

  return $output;
}


//include print_pdf to produce final pdf to store in database
require_once(drupal_get_path('module', 'print') .'/print_pdf/print_pdf.pages.inc');

function evaluation_list_evaluations_pdf($course){
  $can_view_student_names = evaluation_can_view_student_names($course);
  $can_view_exam_type = user_access('view exam types');
  $can_view_evaluations = evaluation_can_view_evaluations($course);

  $evaluations = array();
  foreach(evaluation_get_evaluations($course->nid) as $eval_nid => $eval_data){
    $evaluation_node = node_load($eval_nid);
    $eval = array(
      'nid' => $eval_nid,
      'vid' => $evaluation_node->vid,
      'can_update'  => evaluation_can_update($evaluation_node),
      'exam_number' => $evaluation_node->exam_number,
      'exam_type'   => $evaluation_node->exam_type,
      'grade' => '',
      'last_edited_count'     => 0,
      'last_edited_date'      => '',
      'last_edited_user'      => '',
      'final_date'            => '',
      'final_user'            => '',
      'final_count'           => 0,
    );

    if($can_view_student_names){
      $eval['student'] = $eval_data['student'];
    }

    if($evaluation_node->revision_count > 0){
      $eval['grade']                 = $evaluation_node->grade;
      $eval['last_edited_count']     = $evaluation_node->revision_count;
      $eval['last_edited_date']      = format_date($evaluation_node->revision_timestamp, "small");
      $eval['last_edited_user']       = theme('username', user_load($evaluation_node->revision_uid), 'nolink', 1);

      $eval['final_count'] = count($evaluation_node->final_submissions);
      if($eval['final_count'] != 0){
        $eval['final_date'] = format_date($evaluation_node->final_submissions[0]['timestamp'], "small");
        $eval['final_submitted_name'] = $evaluation_node->final_submissions[0]['submitted_name'];
      }
    }
    $evaluations[] = $eval;
  }

  $print = array(
    'course_name' => $course->title, 
    'course_identification' => $course->course_identification, 
    'registration_term_desc' => $course->registration_term_desc,
    'can_view_student_names' => $can_view_student_names,
    'can_view_exam_type' => $can_view_exam_type,
    'can_view_evaluations' => $can_view_evaluations,
    'evaluations' => $evaluations,
  );

  $evaluation_list_template = drupal_get_path('module', 'course') .'/evaluation-list.tpl.php';
  $filename = str_replace(" ", "", $course->registration_term_desc) . "_" . $course->course_identification;
  
  print_pdf_custom_template($evaluation_list_template, $print, $filename);
}

function _evaluation_list_get_order(){
  $header = array();
  $header[] = array(
    'data'  => 'Student',
    'field' => 'student'
  );
  $header[] = array(
    'data'  => 'Exam Number',
    'field' => 'exam_number'
  );
  $header[] = array(
    'data'  => 'Last Edited',
    'field' => 'last_edited'
  );
  return tablesort_get_order($header); 
}

function _evaluation_list_get_sort(){
  return isset($_GET['sort']) ? $_GET['sort'] : 'asc';
}




//sorting function for the exam_list_evaluations
function _evaluation_sort_evaluations(&$rows, $sort, $order){
  switch($order['sql']){
  case 'student':
  case 'exam_number':
  case 'last_edited':
    usort($rows, "_evaluation_sort_evaluations_".$order['sql']."_".$sort);
  }
}

//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_student_asc($a, $b){
  return strcmp($a['student'],  $b['student']);
}


//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_student_desc($a, $b){
  return _evaluation_sort_evaluations_student_asc($a, $b) * -1;
 // return($a['student'] < $b['student']);
}



//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_exam_number_asc($a, $b){
  return($a['exam_number'] > $b['exam_number']);
}



//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_exam_number_desc($a, $b){
  return($a['exam_number'] < $b['exam_number']);
}


//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_last_edited_asc($a, $b){
  return($a['last_edited']['timestamp'] > $b['last_edited']['timestamp']);
}


//helper function for _exam_sort_evaluations()
function _evaluation_sort_evaluations_last_edited_desc($a, $b){
  return($a['last_edited']['timestamp'] < $b['last_edited']['timestamp']);
}


function evaluation_can_view_evaluations($course){
  if(user_access('view all evaluations')){
    return TRUE;
  }
  if(og_group_access_get_access('view evaluation', $course)){
    return TRUE;
  }
  return FALSE;
}









function evaluation_complete_initialization_confirm($form_state, $course){
  $form['course_nid'] = array(
    '#type' => 'value',
    '#value' => $course->nid,
  );

  return confirm_form($form, 
    t('Are you sure you want to complete the initialization?  By doing so you will not be able to reduce any of the grades you have entered.'),
    "node/" .$course->nid."/evaluations/list", 
    t('Are you sure you want to complete the initialization?  By doing so you will not be able to reduce any of the grades you have entered.'),
    t('Confirm'), 
    t('Cancel')
  );
}


function evaluation_complete_initialization_confirm_submit($form, &$form_state) {
  $query = "UPDATE {courses} set evaluations_initialized = 1 WHERE nid = %d";
  db_query($query, $form_state['values']['course_nid']);
  $form_state['redirect'] = "node/" . $form_state['values']['course_nid']."/evaluations/list";
}












