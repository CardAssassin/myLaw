<?php
// $id$

function favorites_views_data() {
  $tables['favorites']['table']['group'] = t('Node');
  
  // how is the scheduler table linked to the nodes
  $tables['favorites']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
  

  $tables['favorites']['uid'] = array(
    'title' => t('Marked Favorite: uid'),
    'help' => t('The user ID of whom marked the node favorite.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),    
 //   'filter' => array(
 //     'handler' => 'views_handler_filter_user',
 //     'label' => t('Publish on'),
 //   ),
  );

  // description of the fields (table columns)
  $tables['favorites']['timestamp'] = array(
    'title' => t('Time marked favorite'),
    'help' => t('Date/time on which the node was marked favorite'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $tables['favorites']['favs'] = array(
    'title' => t('Nodes marked favorite'),
    'help' => t('Nodes marked favorite by the current user'),
    'filter' => array(
      'handler' => 'favorites_handler_filter_favs',
      'label' => t('Favorite nodes'),
    ),
  );
  
  return $tables;
}


/**
 * Implementation of hook_views_handlers().
 */
function favorites_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'favorites'),
    ),
    'handlers' => array(
      // filter
      'favorites_handler_filter_favs' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}


