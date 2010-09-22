<?php
// $id$

function public_interest_views_data() {
  $tables['public_interest']['table']['group'] = t('Node');
  
  // how is the scheduler table linked to the nodes
  $tables['public_interest']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
  


  $tables['public_interest']['pi'] = array(
    'title' => t('Nodes marked as public interest'),
    'help' => t('Nodes marked as public interest'),
    'filter' => array(
      'handler' => 'public_interest_handler_filter_pi',
      'label' => t('Public Interest nodes'),
    ),
  );
  
  return $tables;
}


/**
 * Implementation of hook_views_handlers().
 */
function public_interest_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'public_interest'),
    ),
    'handlers' => array(
      // filter
      'public_interest_handler_filter_pi' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}


