<?php
// $Id: views_handler_filter_node_status.inc,v 1.1 2008/09/03 19:21:29 merlinofchaos Exp $
/**
 * Filter by published status
 */
class favorites_handler_filter_favs extends views_handler_filter_boolean_operator {
 // function admin_summary() { }
  //function operator_form() { }

  function query() {
    if($this->value){
      $table = $this->ensure_my_table();
      $this->query->add_where($this->options['group'], "$table.uid = ***CURRENT_USER***");
    }
    else{
      $this->query->add_where($this->options['group'], "node.nid not in (Select nid from favorites where uid = ***CURRENT_USER***)");
    }
  }
}
