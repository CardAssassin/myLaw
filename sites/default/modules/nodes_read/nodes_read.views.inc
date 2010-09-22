<?php

/**
 * Implement hook_views_data
*/
function nodes_read_views_data() {
  $tables['nodes_read']['table']['group'] = t('Node');

  $tables['nodes_read']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

 $tables['nodes_read']['nid'] = array(
    'help' => t('The node ID of the node.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),
//    'notafield' => TRUE,
  );

  $tables['nodes_read']['uid'] = array(
    'help' => t('The user ID of whom read the node.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
//    'notafield' => TRUE,
  );

  $tables['nodes_read']['read_count'] = array(
    'title' => t('Read: Count'),
    'help' => t('Number of times this node was marked read by any user.'),
    'field' => array(
      'handler' => 'nodes_read_handler_field_read_count',
    ),
    'sortable' => FALSE,
  );

  return $tables;
}



/**
 * Implementation of hook_views_handlers().
 */
function nodes_read_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'nodes_read'),
    ),
    'handlers' => array(
      // field
      'nodes_read_handler_field_read_count' => array(
        'parent' => 'views_handler_field_numeric',
      ),
    ),
  );
}















/*



function views_handler_filter_node_read($op, $filter, $filterinfo, &$query) {
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

function node_read_views_arguments() {
  $args['user_id'] = array(
    'name'    => t("Read Nodes: User ID"),
    'handler' => 'node_read_handler_argument_uid',
    'help'    => t('User ID for Read node.'),
  );
  return $args;
}


function node_read_handler_argument_uid($op, &$query, $argtype, $arg = '') {
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


function node_read_handler_user_count($fieldinfo, $fielddata, $value, $data) {
  return db_result(db_query("SELECT COUNT(*) FROM {read_nodes} WHERE nid = %d", $data->nid));
}
*/
