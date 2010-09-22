<?php
// $Id$
/**
 * @file
 * Views-enables the event module.
 */

/**
 *  Implementation of hook_views_data().
 *  Expose event fields and filters to the views module.
 */
function OSD_writing_competition_views_data() {
  $data['OSD_writing_competition']['table']['group']  = t('OSD Writing Competition');
  $data['OSD_writing_competition_primary_area']['table']['group']  = t('OSD Writing Competition');
  $data['OSD_writing_competition_secondary_area']['table']['group']  = t('OSD Writing Competition');
  
  $data['OSD_writing_competition']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',  
    ),
  );
  $data['OSD_writing_competition_primary_area']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',  
    ),
  );

  $data['OSD_writing_competition_secondary_area']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',  
    ),
  );

    
  $data['OSD_writing_competition']['sponsor'] = array(
    'title' => t('Sponsor'),
    'help' => t('Sponsor field'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['OSD_writing_competition_primary_area']['primary_area'] = array(
    'title' => t('Primary Areas'),
    'help'  => t('Primary Area for OSD Writing Competition'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'OSD_writing_competition_handler_filter_primary_area',
    ),
  );

  $data['OSD_writing_competition_secondary_area']['secondary_area'] = array(
    'title' => t('Secondary Areas'),
    'help'  => t('Secondary Area for OSD Writing Competition'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'OSD_writing_competition_handler_filter_secondary_area',
    ),
  );

  return $data;
}


/**
 * Implementation of hook_views_handlers().
 */
function OSD_writing_competition_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'OSD_writing_competition') .'/handlers',
    ),
    'handlers' => array(
      // filter
      'OSD_writing_competition_handler_filter_primary_area' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'OSD_writing_competition_handler_filter_secondary_area' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

