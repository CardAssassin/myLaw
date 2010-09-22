<?php
//$Id$

function calendar_event_views_default_views(){
  $view = new view;
$view->name = 'upcoming_events';
$view->description = '';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'start' => array(
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
  ),
  'title' => array(
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
  ),
));
$handler->override_option('sorts', array(
  'start' => array(
    'order' => 'ASC',
    'granularity' => 'second',
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'moderate' => array(
    'operator' => '=',
    'value' => '0',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'moderate',
    'table' => 'node',
    'field' => 'moderate',
    'relationship' => 'none',
  ),
  'hide' => array(
    'operator' => '=',
    'value' => '0',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'hide',
    'table' => 'hide_nodes',
    'field' => 'hide',
    'relationship' => 'none',
  ),
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'start' => array(
    'operator' => '>',
    'value' => array(
      'type' => 'date',
      'value' => '1970-01-01',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Upcoming Events');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 0);
$handler->override_option('use_pager', '1');
$handler->override_option('row_plugin', 'node');
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'upcoming-events');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
$handler = $view->new_display('block_link', 'Block (title link)', 'block_link_1');
$handler->override_option('fields', array(
  'start' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'date_format' => 'custom',
    'custom_date_format' => 'm/d/y',
    'exclude' => 0,
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('items_per_page', 5);
$handler->override_option('use_pager', '0');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'asc',
  'columns' => array(
    'start' => 'start',
    'title' => 'title',
  ),
  'info' => array(
    'start' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  ),
  'default' => '-1',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(),
  'separator' => '',
));
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
$handler->override_option('subject_link', 'page_1');
$handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
$handler->override_option('fields', array(
  'start' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'date_format' => 'custom',
    'custom_date_format' => 'm/d/y',
    'exclude' => 0,
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('items_per_page', 5);
$handler->override_option('use_pager', '0');
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'start' => 'start',
    'title' => 'title',
  ),
  'separator' => '  ',
));
$handler->override_option('pane_title', '');
$handler->override_option('pane_description', '');
$handler->override_option('pane_category', array(
  'name' => 'View panes',
  'weight' => 0,
));
$handler->override_option('allow', array(
  'use_pager' => FALSE,
  'items_per_page' => FALSE,
  'offset' => FALSE,
  'link_to_view' => FALSE,
  'more_link' => FALSE,
  'path_override' => FALSE,
  'title_override' => FALSE,
  'exposed_form' => FALSE,
));
$handler->override_option('argument_input', array());
$handler->override_option('link_to_view', '1');
$handler->override_option('inherit_panels_path', 0);
$handler = $view->new_display('feed', 'Feed', 'feed_1');
$handler->override_option('style_plugin', 'rss');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
));
$handler->override_option('row_plugin', 'node_rss');
$handler->override_option('row_options', array(
  'relationship' => 'none',
  'item_length' => 'default',
));
$handler->override_option('path', 'upcoming-events/feed');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
$handler->override_option('displays', array(
  'page_1' => 'page_1',
  'default' => 0,
  'block_link_1' => 0,
  'panel_pane_1' => 0,
));
$handler->override_option('sitename_title', FALSE);

  $views[$view->name] = $view;
  return $views;
}
