<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
  <table class="node-table">
  <tr>
    <td class="node-header">
      <h2 class="title">
      <a href="<?php print $node_url ?>"><?php print $title; ?></a>
      </h2>
    </td>
  </tr>

  <tr>
    <td class="node-teaser">

    </td>
  </tr>
  <?php if ($teaser < 1) : ?>
  <tr>
    <td class="node-body">
      <div class="content">
        <?php print $content ?>
        <?php //print $node->content['book_navigation']['#value']; ?>
      </div>
    </td>
  </tr>
  <?php endif; ?>
  <tr>
    <td colspan=2 class="node-footer">
      <?php if ($teaser == 1): ?>
      <? elseif ($links): ?>
        <div class="links">
          <?php print $links; ?>
        </div>
      <?php endif; ?>
    </td>
  </tr>
  </table>

</div>
