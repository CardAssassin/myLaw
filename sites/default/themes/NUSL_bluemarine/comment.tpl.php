<?php
// $Id: comment.tpl.php,v 1.7 2008/01/04 19:24:23 goba Exp $
?>

  <table class="comment-table<?php print ' '. $status; ?>">
  <?php /*<tr>
    <td colspan=2 class="comment-header">
      <h3 class="comment-title">
        <?php print $title; 
          if ($new != '') { ?><span class="new"><?php print $new; ?></span><?php } ?>
      </h3>
    </td>
  </tr>
*/?>
  <tr>
    
    <td class="comment-content">
      <?php print $content; ?>
    </td>
    <td rowspan=2 class="comment-info">
      <?php if ($picture) print $picture; ?>  
      <?php print theme('username', $comment); ?>
      <div class="comment-submitted">
       <?php print format_date($comment->timestamp, 'custom', "m/d/y g:i a"); ?>
      </div>
      
    </td>
  </tr>
  <tr>
    <td class="comment-footer" >
      <div class="comment-links">&raquo; <?php print $links; ?></div>
    </td>
  </tr>
  </table>
