<?php

function display_block_link_title_views_plugins() {
  return array(
    'display' => array(
      'block_link' => array(
        'title' => t('Block (title link)'),
        'help' => t('Display the view as a block with a title linked to one of the other handlers.'),
        'handler' => 'views_plugin_display_block_link_title',
        'theme' => 'views_view',
        'uses hook block' => TRUE,
        'use ajax' => TRUE,
        'use pager' => TRUE,
        'use more' => TRUE,
        'accept attachments' => TRUE,
        'admin' => t('Block (title link)'),
        'help topic' => 'display-block',
        'parent' => 'block',
      ),
    ),
  );
}
