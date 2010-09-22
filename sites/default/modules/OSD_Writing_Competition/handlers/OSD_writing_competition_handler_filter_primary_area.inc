<?php
// $Id$
/**
 * Filter by primary area
 */

class OSD_writing_competition_handler_filter_primary_area extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('OSD primary area');
      $primary_areas = OSD_writing_competition_get_primary_areas();
      foreach ($primary_areas as $key => $primary_area) {
        $options[$key] = t($primary_area);
      }
      $this->value_options = $options;
    }
  }
}
