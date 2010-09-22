<?php
// $id$

function hide_nodes_views_data() {
  $tables['hide_nodes']['table']['group'] = t('Node');
  
  // how is the scheduler table linked to the nodes
  $tables['hide_nodes']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
  
  $tables['hide_nodes']['nid'] = array(
    'title' => t('Marked: Nid'),
    'help' => t('The node ID of the node.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),    
  );

  $tables['hide_nodes']['uid'] = array(
    'title' => t('Marked: uid'),
    'help' => t('The user ID of whom marked the node hidden.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),    
 //   'filter' => array(
 //     'handler' => 'views_handler_filter_user',
 //     'label' => t('Publish on'),
 //   ),
  );

  // description of the fields (table columns)
  $tables['hide_nodes']['timestamp'] = array(
    'title' => t('Time marked hidden'),
    'help' => t('Date/time on which the node was marked hidden'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('Time marked hidden'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $tables['hide_nodes']['hide'] = array(
    'title' => t('Nodes marked hidden'),
    'help' => t('Nodes marked hidden by the current user'),
    'filter' => array(
      'handler' => 'hide_nodes_handler_filter_hide',
      'label' => t('Hidden nodes'),
    ),
  );
  
  return $tables;
}


/**
 * Implementation of hook_views_handlers().
 */
function hide_nodes_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'hide_nodes'),
    ),
    'handlers' => array(
      // filter
      'hide_nodes_handler_filter_hide' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}


