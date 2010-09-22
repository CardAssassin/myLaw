<?php


function evaluation_finalize_form($form_state, $eval, $course){
  if(!og_group_access_get_access('finalize evaluation', $course)){
    return 'access denied';
  }

  $form['course_title'] = array(
    '#type' => 'hidden',
    '#value' => $course->title
  );
  $form['course_identification'] = array(
    '#type' => 'hidden',
    '#value' => $course->course_number
  );
  $form['registered_course_crn'] = array(
    '#type' => 'hidden',
    '#value' => $course->crn
  );
  $form['credits'] = array(
    '#type' => 'hidden',
    '#value' => $course->credits
  );
  $form['registration_term'] = array(
    '#type' => 'hidden',
    '#value' => $course->registration_term
  );
  $form['registration_term_desc'] = array(
    '#type' => 'hidden',
    '#value' => $course->registration_term_desc
  );
  $form['primary_instructor'] = array(
    '#type' => 'hidden',
    '#value' => theme('username', (object)array('name' => $course->primary_instructor_nuid), 'nolink'),
  );
  $form['secondary_instructor'] = array(
    '#type' => 'hidden',
    '#value' => $course->secondary_instructor_nuid ? theme('username', (object)array('name' => $course->secondary_instructor_nuid), 'nolink') : '',
  );
  $form['student'] = array(
    '#type' => 'hidden',
    '#value' => $eval->student,
  );
  $form['student_nuid'] = array(
    '#type' => 'hidden',
    '#value' => $eval->student_nuid,
  );
  $form['exam_number'] = array(
    '#type' => 'hidden',
    '#value' => $eval->exam_number
  );
  $form['course_desc'] = array(
    '#type' => 'hidden',
    '#value' => $course->body
  );
  
  $form['evaluation_desc'] = array(
    '#type' => 'hidden',
    '#value' => $course->evaluation_description
  );
  $form['evaluation'] = array(
    '#type' => 'hidden',
    '#value' => $eval->body
  );
  $form['eval_nid'] = array(
    '#type' => 'hidden',
    '#value' => $eval->nid,
  );

  $form['grade'] = array(
    '#type' => 'hidden',
    '#value' => $eval->grade,
  );

  $final_submissions_count = count($eval->final_submissions);
  $form['comment_field']['comment'] = array(
    '#type'   => 'textarea',
    '#title'  => 'Comment',
    '#rows'          => 4,
    '#default_value' => ($final_submissions_count > 0) ? $eval->log : '',
    '#required'      => TRUE,
    '#weight'        => -3
  );

  $form['comment_field']['format'] = filter_form($node->format);
  $form['comment_field']['#prefix'] = '<div class="body-field-wrapper">';
  $form['comment_field']['#suffix'] = '</div>';

  $form['#redirect'] = 'node/'.$course->nid.'/evaluations/list';

  return confirm_form(
    $form, 
    //t('Are you sure you want to submit a final copy of the exam for !name exam number %exam_number', array('!name' => 'theme(username, $account)', '%exam_number' => $eval->exam_number)),
    t('Are you sure you want to submit the final version of the evaluation'),
    'node/'. $course->nid."/evaluations/list", 
    t('Are you sure you want to submit the final version of the evaluation?'), 
    t('Yes'), 
    t('Cancel')
  );
}

//include print_pdf to produce final pdf to store in database
require_once(drupal_get_path('module', 'print') .'/print_pdf/print_pdf.pages.inc');

/**
 * Confirm evaluation_finalize_form submit handler
 */
function evaluation_finalize_form_submit($form, &$form_state) {
  global $user;
  $submission_name =  theme('username', $user, 'nolink');
  $submission_time = time();

  $print = array(
    'course_title'   => $form_state['values']['course_title'],
    'course_identification' => $form_state['values']['course_identification'],
    'credits'       => $form_state['values']['credits'],
    'registration_term_desc'      => $form_state['values']['registration_term_desc'],
    'primary_instructor'   => $form_state['values']['primary_instructor'],
    'secondary_instructor'   => $form_state['values']['secondary_instructor'],
    'student'       => $form_state['values']['student'],
    'exam_number'   => $form_state['values']['exam_number'],
    'course_desc' => $form_state['values']['course_desc'],
    'evaluation_desc'   => $form_state['values']['evaluation_desc'],
    'evaluation'    => $form_state['values']['evaluation'],
    'grade'         => $form_state['values']['grade'],
    'timestamp'     => $submission_time,
  );

  $evaluation_final_template = drupal_get_path('module', 'course') .'/evaluation-final.tpl.php';

  $pdf = print_pdf_custom_template($evaluation_final_template, $print);

  db_set_active('final_evaluations');
  $query = "INSERT INTO {final_evaluations} (
    course_title, 
    registered_course_crn, 
    registration_term, 
    registration_term_desc,
    primary_instructor,
    secondary_instructor,
    student_nuid,
    student,
    exam_number, 
    pdf,
    grade,
    submitted_name, 
    timestamp, 
    comment
    ) VALUES ('%s', %d, %d, '%s', '%s', '%s', '%s', '%s', '%s', %b, '%s', '%s', %d, '%s')"; 

  db_query($query, 
    $form_state['values']['course_title'],
    $form_state['values']['registered_course_crn'],
    $form_state['values']['registration_term'],
    $form_state['values']['registration_term_desc'],
    $form_state['values']['primary_instructor'],
    $form_state['values']['secondary_instructor'],
    $form_state['values']['student_nuid'],
    $form_state['values']['student'],
    $form_state['values']['exam_number'],
    $pdf,
    $form_state['values']['grade'],
    $submission_name,
    $submission_time,
    $form_state['values']['comment']
  );   
  db_set_active('default');

  evaluation_lock($form_state['values']['eval_nid']);

  $form_state['#redirect'] = 'node/'.$form_state['values']['exam_nid'];
  
}


/*
function evaluation_view_final($evaluation, $course){
  $course = node_load($node->author_group_nid);
  db_set_active('final_evaluations');
  $query = "SELECT student_nuid, student, course_title, pdf FROM {final_evaluations} WHERE registered_course_crn = %d and student_nuid = '%s' ORDER BY timestamp DESC";
  $data =  db_fetch_object(db_query($query, $course->crn, $node->student_nuid));
  db_set_active('default');

  $student_lastname = str_replace(' ', '', substr($data->student, 0, strpos($data->student, ', ')));  
  $filename = $data->student_nuid . "_" . $student_lastname . "_" . $data->course_title;  

  evaluation_show_pdf(db_decode_blob($data->pdf), $filename);

/* 
  header("Content-Type: application/pdf");
  header("Content-Disposition: attachment; filename=$filename.pdf");
  header("Content-Length: ".strlen($data->pdf));
  header("Accept-Ranges: bytes");
  header("Pragma: public");
  header("Expires: 0");
  header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
  header("Content-transfer-encoding: binary");
  
  echo db_decode_blob($data->pdf);
  die;
*/

//}

/*
function evaluation_show_pdf($pdf, $filename){
  header("Content-Type: application/pdf");
  header("Content-Disposition: attachment; filename=$filename.pdf");
  header("Content-Length: ".strlen($pdf));
  header("Accept-Ranges: bytes");
  header("Pragma: public");
  header("Expires: 0");
  header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
  header("Content-transfer-encoding: binary");

  echo($pdf);
  die;
}
*/
