<?php
//$Id$

function important_announcement_views_default_views(){
$view = new view;
$view->name = 'important_announcements';
$view->description = '';
$view->tag = 'Important Announcements';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('sorts', array(
  'created' => array(
    'order' => 'DESC',
    'granularity' => 'second',
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'important_announcement' => 'important_announcement',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('footer', '<?php
if(user_access(\'create important announcement\')){
  print l(\'Create Important Announcement\', \'node/add/important-announcement\');
}
?>');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 1);
$handler->override_option('empty', '<?php
if(user_access(\'create important announcement\')){
  print \' \';
}
?>');
$handler->override_option('empty_format', '3');
$handler->override_option('row_plugin', 'node');
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'important-announcements');
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
$handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
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
$handler->override_option('link_to_view', 0);
$handler->override_option('inherit_panels_path', 0);

  $views[$view->name] = $view;
  return $views;
}
