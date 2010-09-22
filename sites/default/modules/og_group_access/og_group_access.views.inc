<?php
//$Id



/**
 * Implementation of hook_views_data().
 */
function og_group_access_views_data() {
  /*$data = array();
  $tables = array('og', 'og_ancestry', 'og_uid');
  foreach ($tables as $table) {
    $function = "og_views_data_$table";
    $data += $function();
  }
  */
  $filterhelp = t('<strong>Posts</strong> are filtered for specified organic groups. The page context (if Display is a page) will be set to the first listed group. That means that blocks and breadcrumbs (and theme and locale, if applicable) will be based upon the first specified node id.');

  $data = array();
  $data['og_author']['table']['group'] = t('Organic Groups');
  $data['og_author']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
/*  $data['og_author']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Group authored posts'),
    'help' => t('Posts made by the group.'),
  );
*/
  $data['og_author']['author_group_nid'] = array(
    'title' => t('Authoring group'),
    'help' => t('The group authoring a post.'),
    'field' => array(
      'handler' => 'og_views_handler_field_og_group_nids',
    ),
    'relationship' => array(
      'title' => t('Group node (post)'),
      'help' => t("Bring in information about the group node based on a post's groups."),
      'base' => 'node',
      'field' => 'author_group_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Group node (post)'),
    ),
    'filter' => array(
      'handler' => 'og_views_handler_filter_og_group_nid',
      'numeric' => TRUE,
      'help' => $filterhelp,
    ),
    'argument' => array(
      'name' => t('Post: in specified group (by number)'),
      'name field' => 'title', // the field to display in the summary.
      'validate type' => 'nid',
      'handler' => 'og_views_handler_argument_og_group_nid',
      'help' => $filterhelp,
    ),
  );
  $data['og_author']['nid'] = array(
    'title' => t('Post: Nid'),
    'help' => t('The node ID of the node.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),    
  );
  $data['og_author']['author_picg'] = array(
    'title' => t('OG: Posts where current group is the author'),
    'help' => t('Posts where the current group is the author.'),
    'filter' => array(
      'handler' => 'og_views_handler_filter_og_author_picg',
    ),
  );

  return $data; 
}


/**
 * Implementation of hook_views_handlers().
 */
function og_group_access_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'og_group_access'),
    ),
    'handlers' => array(
      // filter
      'og_views_handler_filter_og_author_picg' => array(
        'parent' => 'views_handler_filter',
      ),
    ),
  );
}
