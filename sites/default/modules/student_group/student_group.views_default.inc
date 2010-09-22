<?php
//$Id$

function student_group_views_default_views(){
$view = new view;
$view->name = 'student_groups';
$view->description = '';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
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
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'title' => array(
    'order' => 'ASC',
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'student_group' => 'student_group',
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
$handler->override_option('title', 'Student Groups');
$handler->override_option('footer', '<?php 
  if (user_access(\'administer site configuration\')){
    print \'<br><br>\';
    print l(\'Add Student Group\', \'node/add/student-group\');
    print \'<br>\';
    print l(\'Administer Student Groups\', \'admin/content/node-type/student-group\');

  }
?>');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 1);
$handler->override_option('items_per_page', 0);
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'student-groups');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Student Groups',
  'description' => '',
  'weight' => '0',
  'name' => 'primary-links',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));


  $views[$view->name] = $view;
  return $views;
}
