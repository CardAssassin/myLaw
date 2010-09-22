<?php
// $Id$


/**
 *  Implementation of hook_views_data().
 */
function classifieds_views_data() {
  $data['classifieds']['table']['group']  = t('Classifieds');
  
  $data['classifieds']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',  
    ),
  );
    
  $data['classifieds']['category'] = array(
    'title' => t('Category'),
    'help' => t('Category the classified post is listed under.'), 
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
/*    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
 //   'sort' => array(
 //     'handler' => 'views_handler_sort_string',
//    ),
*/    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  return $data;
}





