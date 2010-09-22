<?php





//from http://www.disobey.com/node/1833
function phptemplate_preprocess_node(&$variables) {
 // print_r($variables);die;
  // we like to display teasers on the node view pages in a different style,
  // but only if they were NOT set to "show summary on full view" (which seems
  // backward, but the implication with that checkbox is that the teaser is
  // PART of the node's body, instead of an actual summary of the entire
  // node's body). if a node's unbuilt body starts with <!--break-->, then
  // a teaser has been manually set, and "show summary" is not checked.
  $node = $variables['node'];


  if ($variables['teaser'] && $node->teaser && !empty($node->readmore)) {
      $read_more = array(
        'title' => t('Read more'),
        'href' => "node/$node->nid",
        // The title attribute gets escaped when the links are processed, so
        // there is no need to escape here.
        'attributes' => array('title' => t('Read the rest of !title.', array('!title' => $node->title)))
      );
      $variables['read_more_link'] = theme('links', array('read_more' => $read_more));
  }




  //if ($variables['page'] == TRUE) { // only do this on full page views.
    $node = node_load($variables['nid']); // we reload the node because
    // by the time it gets here <!--break--> has already been filtered out.
    // this if logic stolen from node.module's node_teaser_include_verify().
   // if (strpos($node->body, '<!--break-->') === 0) {
    //  $variables['style_teaser_differently'] = TRUE;
      $variables['teaser_content'] = check_markup($node->teaser, $node->format, FALSE);
   // }
  //}
  if($variables['teaser'] == TRUE){
   // print_r($variables);die;
    
  }
}
