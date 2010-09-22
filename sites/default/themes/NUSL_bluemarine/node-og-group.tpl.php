<H1><?php print $title; ?></H1>


        <?php print $content; ?>



      <? if ($links): ?>
        <div class="links">
          <?php print $links; ?>
        </div>
      <?php endif; ?>

 <p>       <span class='submitted'>
        <?php print format_date($node->changed, 'custom', "F jS, Y"); ?>
        </span>
