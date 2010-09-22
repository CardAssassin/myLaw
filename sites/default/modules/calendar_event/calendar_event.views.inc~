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
function calendar_event_views_data() {
  $data['calendar_event']['table']['group']  = t('Calendar Event');
  
  $data['calendar_event']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',  
    ),
  );
    
  $data['calendar_event']['start'] = array(
    'title' => t('Start Date'),
    'help' => t('The start Date of the Calendar Event.'), 
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['calendar_event']['end'] = array(
    'title' => t('End Date'),
    'help' => t('The end Date of the Calendar Event.'), 
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}





