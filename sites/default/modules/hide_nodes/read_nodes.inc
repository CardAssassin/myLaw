<?php

/**
 * Implement hook_views_tables
*/
function read_nodes_views_tables() {
  $tables['read_nodes'] = array(
    'name' => 'read_nodes',
    'join' => array(
      'type' => 'left',
      'left' => array(
        'table' => 'node',
        'field' => 'nid',
      ),
      'right' => array(
        'field' => 'nid',
      ),
    ),
    'fields' => array(
      'last' => array(
        'name' => t('Read Nodes: Time Marked'),
        'sortable' => true,
        'handler' => views_handler_field_dates(),
        'option' => 'string',
        'help' => t('Display the date/time the node was marked read.'),
      ),/*
      'count' => array(
        'name' => t('Read Nodes: Count'),
        'handler' => 'read_nodes_handler_user_count',
        'help' => t('Number of times this node was marked read by any user.'),
        'sortable' => FALSE,
        'notafield' => TRUE,
      ),*/
    ),
    'sorts' => array(/*
      'last' => array(
        'name' => t('Read Nodes: Time Added'),
        'help' => t('Sort by the date/time the node was marked read.'),
      ),*/
    ),
    'filters' => array(  
      'last' => array(
        'field'     => 'last',
        'name'      => t('Read Nodes'),
        'operator'  => 'views_handler_operator_eqneq',
        'handler'   => 'views_handler_filter_read_nodes',
        'list-type' => 'select',
        'list' => array(
          'read'  => t('Read'),
          'unread'      => t('Unread'),
        ),
      'help' => t('This allows you to filter based on nodes marked read.'),
      ),/*
      'last' => array(
        'name'     => t('Read Nodes: Time Added'),
        'operator' => 'views_handler_operator_gtlt',
        'value'    => views_handler_filter_date_value_form(),
        'handler'  => 'views_handler_filter_timestamp',
        'option'   => 'string',
        'help'     => t('This filter allows nodes to be filtered by the date and time the user marked them read. Enter dates in the format: CCYY-MM-DD HH:MM:SS. Enter \'now\' to use the current time. You may enter a delta (in seconds) to the option that will be added to the time; this is most useful when combined with now.'),
      ),*/
    ),
  );
  return $tables;
}



function views_handler_filter_read_nodes($op, $filter, $filterinfo, &$query) {
  global $user;

  
  


  switch($filter['value']) {
    case 'read':
      $query->ensure_table('read_nodes');
      $query->add_where("read_nodes.uid = $user->uid");
      $query->add_where("read_nodes.last > 0");
      break;

    case 'unread':
      $query->add_where("node.nid not in (Select nid from read_nodes where uid = $user->uid)");
      break;
  }
}

function read_nodes_views_arguments() {
  $args['user_id'] = array(
    'name'    => t("Read Nodes: User ID"),
    'handler' => 'read_nodes_handler_argument_uid',
    'help'    => t('User ID for Read node.'),
  );
  return $args;
}


function read_nodes_handler_argument_uid($op, &$query, $argtype, $arg = '') {
  switch ($op) {
    case 'sort':
      // no luck using add_orderby method.
      $query->orderby[] = ' num_nodes '. $argtype;
      break;
    case 'filter':
      list($and_or, $uids) = _views_break_phrase($arg);
      $and_or = strtoupper($and_or);
      // Similar to taxonomy AND/OR query.

      if ($and_or == 'OR') {
        $query->ensure_table('read_nodes');
        $cond = array_fill(0, count($uids), "read_nodes.uid = %d");
        $query->add_where(implode(" $and_or ", $cond), $uids);
      }
      else {
        foreach ((array)$uids as $uid) {
          $num = $query->add_table('read_nodes');
          $tablename = $query->get_table_name('read_nodes', $num);
          $query->add_where("$tablename.uid = %d", $uid);
        }
      }
      break;
  }
}


function read_nodes_handler_user_count($fieldinfo, $fielddata, $value, $data) {
  return db_result(db_query("SELECT COUNT(*) FROM {read_nodes} WHERE nid = %d", $data->nid));
}
