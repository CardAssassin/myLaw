<div class="<?php print $node_classes ?>" id="node-<?php print $node->nid; ?>">

  <table class="node-table">
  <tr>
    <td  class="node-header">
      <h2 class="title">
      <a href="<?php print $node_url ?>"><?php print $title; ?></a>
      </h2>
    </td>
  </tr>

  <tr>
    <td  class="node-body">
      <div class="content" align='center'>
        <?php print $node->content['body']['#value']; ?>
      </div>
    </td>
  </tr>
  <tr>
    <td class="exam-evaluations" align="center">
    <?php print $node->content['exam_list_evaluations']['#value']; ?>
    <?php print $node->content['exam_complete_initialization']['#value']; ?>
    </td>
  </tr>
  
  <tr>
    <td  class="node-footer">
      <?php print $read_more_link; ?>
      <?php if ($closure) print $closure; ?>
    </td>
  </tr>
  </table>


</div>
