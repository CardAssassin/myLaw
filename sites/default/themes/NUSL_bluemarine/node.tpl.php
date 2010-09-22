<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
  <table class="node-table">
  <tr>
    <?php if ($teaser == 1) : ?>
    <td rowspan=4 class="node-info">
    <?php else : ?>
    <td rowspan=4 class="node-info">
    <?php endif; ?> 
      <?php 
      if ($picture){
        print $picture;
      }   
      print theme('username', $node);
      print "<br>";
      ?> 
      <?php if ($submitted): ?>
        <span class='submitted'>
        <?php print format_date($node->created, 'custom', "F jS, Y"); ?>
        </span>
      <?php endif; ?>   
    </td>
  </tr>
  <tr>
    <td class="node-header">
      <h2 class="title">
      <a href="<?php print $node_url ?>"><?php print $title; ?></a>
      </h2>
    </td>
  </tr>

  <tr>
    <td class="node-teaser">
      <?php if (count($taxonomy)): ?>
        <div class="taxonomy"><?php print t(' in ') . $terms ?></div>
      <?php endif; ?>
      <div class="content">
        <?php print $teaser_content; ?>
      </div>
    </td>
  </tr>
  <?php if ($teaser < 1) : ?>
  <tr>
    <td class="node-body">
      <div class="content">
        <?php print $content; ?>
      </div>
    </td>
  </tr>
  <?php endif; ?>
  <tr>
    <td colspan=2 class="node-footer">
      <?php if ($teaser == 1): ?>
      <? //print $read_more_link; ?>
      <? elseif ($links): ?>
        <div class="links">
          <?php print $links; ?>
        </div>
      <?php endif; ?>

      <?php print $read_more_link; ?>
      <?php if ($closure) print $closure; ?>
    </td>
  </tr>
  </table>

</div>