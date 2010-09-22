<?php
// $Id$
/**
 * Filter by secondary area
 */

class OSD_writing_competition_handler_filter_secondary_area extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('OSD secondary area');
      $secondary_areas = OSD_writing_competition_get_secondary_areas();
      foreach ($secondary_areas as $key => $secondary_area) {
        $options[$key] = t($secondary_area);
      }
      $this->value_options = $options;
    }
  }
}
