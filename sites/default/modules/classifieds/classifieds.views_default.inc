<?php
//$Id$

function classifieds_views_default_views(){
$view = new view;
$view->name = 'classifieds';
$view->description = '';
$view->tag = 'Classifieds';
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
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'category' => array(
    'operator' => '=',
    'value' => '',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 1,
    'id' => 'category',
    'table' => 'classifieds',
    'field' => 'category',
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'classifieds' => 'classifieds',
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
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Classifieds');
$handler->override_option('footer', '<?php
  print l(\'Post Advertisement\', \'classifieds/post\');
?>');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 1);
$handler->override_option('use_pager', '1');
$handler->override_option('row_plugin', 'node');
$handler->override_option('row_options', array(
  'relationship' => 'none',
  'build_mode' => 'teaser',
  'links' => 1,
  'comments' => 0,
));
$handler = $view->new_display('page', 'Classifieds', 'page_1');
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
      'classifieds' => 'classifieds',
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
$handler->override_option('path', 'classifieds');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Classifieds',
  'description' => '',
  'weight' => '1',
  'name' => 'primary-links',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
$handler = $view->new_display('page', 'Apartments', 'page_2');
$handler->override_option('filters', array(
  'category' => array(
    'operator' => '=',
    'value' => 'Apartments',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 1,
    'id' => 'category',
    'table' => 'classifieds',
    'field' => 'category',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'classifieds' => 'classifieds',
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
$handler->override_option('title', 'Apartments');
$handler->override_option('path', 'classifieds/apartments');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Apartments',
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
$handler = $view->new_display('page', 'Books', 'page_3');
$handler->override_option('filters', array(
  'category' => array(
    'operator' => '=',
    'value' => 'Books',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 1,
    'id' => 'category',
    'table' => 'classifieds',
    'field' => 'category',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'classifieds' => 'classifieds',
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
$handler->override_option('title', 'Books');
$handler->override_option('path', 'classifieds/books');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Books',
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
$handler = $view->new_display('page', 'Lost & Found', 'page_4');
$handler->override_option('filters', array(
  'category' => array(
    'operator' => '=',
    'value' => 'Lost & Found',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 1,
    'id' => 'category',
    'table' => 'classifieds',
    'field' => 'category',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'classifieds' => 'classifieds',
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
$handler->override_option('title', 'Lost & Found');
$handler->override_option('path', 'classifieds/lost_and_found');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Lost & Found',
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
$handler = $view->new_display('page', 'Miscellaneous', 'page_5');
$handler->override_option('filters', array(
  'category' => array(
    'operator' => '=',
    'value' => 'Misc.',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 1,
    'id' => 'category',
    'table' => 'classifieds',
    'field' => 'category',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'classifieds' => 'classifieds',
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
$handler->override_option('title', 'Miscellaneous');
$handler->override_option('path', 'classifieds/miscelaneous');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'Miscellaneous',
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
