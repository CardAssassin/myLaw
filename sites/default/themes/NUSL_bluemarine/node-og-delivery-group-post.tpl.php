
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
<table border=1 class="node-table">
  <tr>
    <td colspan=2 class="node-header">
      <h2 class="title">
      <a href="<?php print $node_url ?>"><?php print $title; ?></a>
      </h2>
    </td>
  </tr>
  <tr>
    <td class="node-info">
      <?php if ($picture) print $picture; ?>  

      <?php if ($submitted): ?>
        <span class="submitted"><?php print t('Posted ') . format_date($node->created, 'custom', "F jS, Y") . t(' by ') . theme('username', $node); ?></span> 
      <?php endif; ?>
      
      <?php if (count($taxonomy)): ?>
        <div class="taxonomy"><?php print t(' in ') . $terms ?></div>
      <?php endif; ?>
  
    </td>

    <?php if($page): ?>
    <td class="node-teaser">
      <div class="content">
        <?php print $teaser_content; ?>
      </div>
    </td>
    <?php endif; ?>

    <!-- ?php if($teaser): ?>
    <td class="node-teaser">
      <div class="content">
        <?php print $content; ?>
      </div>
    </td>
    <?php endif; ? -->

  </tr>

  <?php if ($page): ?>
  <tr>
    <td colspan=2 class="node-body">
      <div class="content">
        <?php print $content; ?>
      </div>
    </td>
  </tr>
  <?php endif; ?>

  <tr>
    <td colspan=2 class="node-footer">
      <?php if($readmore){
        print $links['read_more'];
      } ?>
      <?php if ($closure) print $closure; ?>
    </td>
  </tr>
  </table>
</div>
