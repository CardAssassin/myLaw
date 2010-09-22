<?php
/**
 * Lovely filter handler which restricts posts to the current group. Useful for group related blocks.
 **/
class og_views_handler_filter_og_author_picg extends views_handler_filter {
  function query() {
    $table = $this->ensure_my_table();
    $this->query->add_where($this->options['group'], "$table.author_group_nid  = ***CURRENT_GID***");
  }
}
