<?php
// $Id$


function og_delivery_views_tables(){
  $tables['og_delivery_author'] = array(
    'name' => "og_delivery_author",
    'join' => array(
      'left' => array('table'=>"node", 'field'=>"nid"),
      'right' => array('field'=>"nid"),
    ),
    'filters' => array(
      'gid' => array(
        'name' => "OG: authoring group",
        'operator' => 'views_handler_operator_eqneq',
        'list' => 'views_handler_filter_groupcurrent',
        'list-type' => 'select',
        'handler' => 'og_delivery_handler_filter_author',
      ),
    )
  ); 
  return $tables;   
}

function og_delivery_views_filters(){

}

function og_delivery_views_arguments() {
  $args = array(
    'gid' => array(
      'name' => t("Og Delivery: Author Group nid"), 
      'handler' => 'og_delivery_handler_argument_author_gid',
      'help' => t('Filter for a given organic group'),
      )
    );
  return $args;
}

/*
 * Custom argument for filtering by an og.
 */
function og_delivery_handler_argument_author_gid($op, &$query, $argtype, $arg = '') {
  switch ($op) {
    case 'summary':
      $query->ensure_table('og_delivery_author');
      $query->ensure_table('og_node_data');
      //$query->add_field('title', 'og_node_data');
      $query->add_field('gid', 'og_delivery_author');
      $fieldinfo['field'] = "og_node_data.nid";
      return $fieldinfo;
    case 'link':
      $name = ($query->title ? $query->title : t('Unaffiliated'));
      return l($name, "$arg/" . intval($query->group_nid));
    case 'filter':
      $query->ensure_table('og_delivery_author');

      if($arg == ''){
        print_r($query);die;
        //$query->add_where('og_delivery_author.gid = %d', 1);
        $query->add_where('og_delivery_author.gid = ***CURRENT_GID***');
      }
      else {
        $query->add_where('og_delivery_author.gid = %d', $arg);
      }

    //  $node = node_load((int)$arg);
     // og_set_group_context($node);
      break;
    case 'title':
      return db_result(db_query_range('SELECT title FROM {node} WHERE nid = %d', $query, 0, 1));;
  }
}
/**
 *
 * @return void
 **/
function og_delivery_handler_filter_author($op, $filter, $filterinfo, &$query) {
  $query->ensure_table('og_delivery_author');
  $query->add_where("og_delivery_author.gid = ***CURRENT_GID***");
}


/**
 * Provide a view for getting posts sent from a group
 */
function og_delivery_views_default_views() {
  $view = new stdClass();
  $view->name = 'og_delivery_sent';
  $view->description = t('Shows posts sent from group.');
  $view->access = array();
  $view->view_args_php = '';
  $view->block = TRUE;
  $view->block_title = 'Group posts sent';
  $view->block_header = '';
  $view->block_header_format = '1';
  $view->block_footer = '';
  $view->block_footer_format = '1';
  $view->block_empty = '';
  $view->block_empty_format = '1';
  $view->block_type = 'list';
  $view->nodes_per_block = '3';
  $view->block_more = FALSE;
  $view->block_use_page_header = FALSE;
  $view->block_use_page_footer = FALSE;
  $view->block_use_page_empty = FALSE;
  $view->page = TRUE;
  $view->page_title = t('Sent posts');
  $view->page_header = '';
  $view->page_header_format = '1';
  $view->page_footer = '';
  $view->page_footer_format = '1';
  $view->page_empty = t('No posts have been made.');
  $view->page_empty_format = '1';
  $view->page_type = 'table';
  $view->url = 'group/$arg/sent';
  $view->use_pager = TRUE;
  $view->nodes_per_page = '10';
  $view->menu = TRUE;
  $view->menu_title = t('Sent posts');
  $view->menu_tab = TRUE;
  $view->menu_tab_default = FALSE;
  $view->menu_weight = '';
  $view->sort = array (
  );
  $view->argument = array (
    array (
      'type' => 'gid',
      'argdefault' => '1',
      'title' => '',
      'options' => '',
      'wildcard' => '',
      'wildcard_substitution' => '',
    ),
  );
  $view->field = array (
    array (
      'tablename' => 'node',
      'field' => 'title',
   //   'label' => t('Title'),
      'sortable' => '1',
      'handler' => 'views_handler_field_nodelink',
    ),
    array (
      'tablename' => 'og_node_data',
      'field' => 'title',
   //   'label' => t('Group'),
      'sortable' => '1'
    ),
    array (
      'tablename' => 'node',
      'field' => 'type',
 //     'label' => t('Type'),
      'sortable' => '1',
    ),
    array (
      'tablename' => 'node',
      'field' => 'created',
   //   'label' => t('Created'),
      'sortable' => '1',
      'handler' => 'views_handler_field_date_small',
      'defaultsort' => 'DESC',
    ),
  );
  $view->filter = array (/*
    'gid' => array(
      'name' => t('Og Delivery: Sent from current group'),
      'handler' => 'og_delivery_handler_filter_author',
      'help' => 'filter'
    )*/
  );
  $view->exposed_filter = array();
  $view->requires = array(og_node_data, node);
  $views[$view->name] = $view;

  return $views;
}
