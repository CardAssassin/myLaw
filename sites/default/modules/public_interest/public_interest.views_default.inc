<?php
//$Id$

function public_interest_views_default_views(){


///////////////////////////////////////////////////////////
//        calendar_public_interest
///////////////////////////////////////////////////////////

$view = new view;
$view->name = 'calendar_public_interest';
$view->description = 'A multi-dimensional calendar view with back/next navigation.';
$view->tag = 'Public Interest Calendar';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'title' => array(
    'label' => '',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'field' => 'title',
    'table' => 'node',
    'relationship' => 'none',
  ),
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
    'custom_date_format' => 'g:i A',
    'exclude' => 0,
    'id' => 'start',
    'table' => 'calendar_event',
    'field' => 'start',
    'relationship' => 'none',
  ),
  'end' => array(
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
    'custom_date_format' => 'g:i A',
    'exclude' => 0,
    'id' => 'end',
    'table' => 'calendar_event',
    'field' => 'end',
    'relationship' => 'none',
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
$handler->override_option('arguments', array(
  'date_argument' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'date',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'date_fields' => array(
      'calendar_event.start' => 'calendar_event.start',
    ),
    'year_range' => '-3:+3',
    'date_method' => 'OR',
    'granularity' => 'month',
    'id' => 'date_argument',
    'table' => 'node',
    'field' => 'date_argument',
    'relationship' => 'none',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'announcement' => 0,
      'classifieds' => 0,
      'class_year' => 0,
      'course' => 0,
      'evaluation' => 0,
      'exam' => 0,
      'department' => 0,
      'discussion_topic' => 0,
      'group_book' => 0,
      'student_group' => 0,
      'book' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Override',
    ),
    'default_options_div_prefix' => '',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '8' => 0,
      '7' => 0,
      '4' => 0,
      '5' => 0,
      '6' => 0,
      '3' => 0,
    ),
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_is_member' => 0,
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
  'pi' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'pi',
    'table' => 'public_interest',
    'field' => 'pi',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
  'role' => array(),
  'perm' => '',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Public Interest Events');
$handler->override_option('header_empty', 1);
$handler->override_option('items_per_page', 0);
$handler->override_option('use_more', 0);
$handler->override_option('style_plugin', 'calendar_nav');
$handler = $view->new_display('calendar', 'Calendar page', 'calendar_1');
$handler->override_option('path', 'public-interest/calendar');
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
$handler->override_option('calendar_colors', array(
  '0' => array(),
));
$handler->override_option('calendar_colors_vocabulary', array());
$handler->override_option('calendar_colors_taxonomy', array());
$handler->override_option('calendar_popup', 0);
$handler->override_option('calendar_date_link', '');
$handler = $view->new_display('calendar_block', 'Calendar block', 'calendar_block_1');
$handler->override_option('block_description', 'Calendar - Public Interest');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('calendar_period', 'Year view', 'calendar_period_1');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'year',
  'name_size' => 1,
  'max_items' => 0,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'year');
$handler = $view->new_display('calendar_period', 'Month view', 'calendar_period_2');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'month',
  'name_size' => '99',
  'with_weekno' => '1',
  'date_fields' => NULL,
  'max_items' => 0,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'month');
$handler = $view->new_display('calendar_period', 'Day view', 'calendar_period_3');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'name_size' => '99',
  'with_weekno' => 0,
  'max_items' => 0,
  'max_items_behavior' => 'more',
  'groupby_times' => 'hour',
  'groupby_times_custom' => '',
  'groupby_field' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'day');
$handler = $view->new_display('calendar_period', 'Week view', 'calendar_period_4');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'name_size' => '99',
  'with_weekno' => 0,
  'max_items' => 0,
  'max_items_behavior' => 'more',
  'groupby_times' => 'hour',
  'groupby_times_custom' => '',
  'groupby_field' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
));
$handler->override_option('calendar_type', 'week');
$handler = $view->new_display('calendar_period', 'Block view', 'calendar_period_5');
$handler->override_option('style_plugin', 'calendar_style');
$handler->override_option('style_options', array(
  'display_type' => 'month',
  'name_size' => '1',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', TRUE);
$handler->override_option('displays', array(
  'calendar_1' => 0,
  'default' => 0,
  'calendar_block_1' => 'calendar_block_1',
));
$handler->override_option('calendar_type', 'month');
$handler = $view->new_display('calendar_ical', 'iCal feed', 'calendar_ical_1');
$handler->override_option('arguments', array());
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => 1,
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
  'date_filter' => array(
    'operator' => '>=',
    'value' => array(
      'value' => NULL,
      'min' => NULL,
      'max' => NULL,
      'default_date' => 'now',
      'default_to_date' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'date_fields' => array(
      'node.changed' => 'node.changed',
    ),
    'granularity' => 'day',
    'form_type' => 'date_select',
    'default_date' => 'now',
    'default_to_date' => '',
    'id' => 'date_filter',
    'table' => 'node',
    'field' => 'date_filter',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('style_plugin', 'ical');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
  'summary_field' => 'title',
  'description_field' => '',
  'location_field' => '',
));
$handler->override_option('row_plugin', '');
$handler->override_option('path', 'public-interest/calendar/ical');
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
  'calendar_1' => 'calendar_1',
  'default' => 0,
  'calendar_block_1' => 0,
  'block_1' => 0,
));
$handler->override_option('sitename_title', FALSE);




  $views[$view->name] = $view;


///////////////////////////////////////////////////////////
//        public_interest_matters
///////////////////////////////////////////////////////////
$view = new view;
$view->name = 'public_interest';
$view->description = '';
$view->tag = 'Public Interest';
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
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'created' => array(
    'order' => 'ASC',
    'granularity' => 'second',
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
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
  'pi' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'pi',
    'table' => 'public_interest',
    'field' => 'pi',
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
$handler->override_option('title', 'Public Interest Matters');
$handler->override_option('empty', 'There are no public interest matters to view.');
$handler->override_option('empty_format', '1');
$handler->override_option('row_plugin', 'node');
$handler->override_option('row_options', array(
  'relationship' => 'none',
  'build_mode' => 'teaser',
  'links' => 1,
  'comments' => 0,
));
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('use_pager', '1');
$handler->override_option('path', 'public-interest');
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
$handler->override_option('items_per_page', 5);
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(),
  'separator' => '',
));
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
$handler->override_option('subject_link', 'page_1');



  $views[$view->name] = $view;

  return $views;
}
