<?php
// $Id:  $
/**
 * @file
 * Contains the block display plugin.
 */

/**
 * The plugin that handles a block.
 *
 * @ingroup views_display_plugins
 */
class views_plugin_display_block_link_title extends views_plugin_display_block {
  function option_definition() {
    $options = parent::option_definition();

    $options['subject_link'] = array('default' => '');

    return $options;
  }

  /**
   * The display block handler returns the structure necessary for a block.
   */
  function execute() {
    $info = parent::execute();

    if (!is_array($info)) {
      return;
    }

    // Now check to see if we have a link to add:
    $subject_link = $this->get_option('subject_link');
    if (!empty($subject_link)) {
      $displays = $this->_get_displays($this->view);
      if (isset($displays[$subject_link])) {
        $this_display = $this->display->id;
        $this->view->set_display($subject_link);
        if ($this->view->access($subject_link)) {
          $info['subject'] = l($info['subject'], $this->view->get_url(), array('html' => TRUE));
        }
        $this->view->set_display($this_display);
      }
    }

    return $info;

  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    $subject_link = $this->get_option('subject_link');
    if (empty($subject_link)) {
      $subject_link = t('No link');
    }
    else {
      $displays = $this->_get_displays($this->view);
      if (isset($displays[$subject_link])) {
        $subject_link = $displays[$subject_link];
      }
    }

    if (strlen($subject_link) > 16) {
      $subject_link = substr($subject_link, 0, 16) . '...';
    }

    $options['subject_link'] = array(
      'category' => 'block',
      'title' => t('Block title link'),
      'value' => $subject_link,
    );


  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'subject_link':
        $form['#title'] .= t('Block title link');

        $options = array_merge(array('' => t('No link'), ' ' => '-'), $this->_get_displays($this->view));
        $form['subject_link'] = array(
          '#type' => 'select',
          '#description' => t('Select a page display to link this block\'s title to.'),
          '#default_value' => $this->get_option('subject_link'),
          '#options' => $options,
          // TODO add the options
        );
        break;
    }
    //dpm($this);
  }

  function _get_displays($view) {
    $displays = array();
    foreach ($view->display as $display) {
      $displays[$display->id] = $display->display_title;
    }
    return $displays;
  }

  /**
   * Perform any necessary changes to the form values prior to storage.
   * There is no need for this function to actually store the data.
   */
  function options_submit($form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    switch ($form_state['section']) {
      case 'subject_link':
        $this->set_option('subject_link', trim($form_state['values']['subject_link']));
        break;
    }
  }
}
