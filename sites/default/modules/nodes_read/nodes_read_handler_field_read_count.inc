<?php


class nodes_read_handler_field_read_count extends views_handler_field_numeric {
  function query() {
 //   $table = $this->ensure_my_table();
/*
    $this->field_alias = $this->query->add_field(NULL, "COUNT($table.nid)", $table . "_" . $this->field);
    $this->query->add_where($this->table_alias, "$table.uid = ***CURRENT_USER***");
*/
    $this->field_alias = $this->query->add_field(NULL, "(SELECT COUNT($this->table.nid) FROM $this->table WHERE $this->table.uid = ***CURRENT_USER*** AND $this->table.nid = node.nid)", $this->table . "_" . $this->field);
  }
}
