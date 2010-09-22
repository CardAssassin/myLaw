<?php
// $Id$

/**
 * @file calendar-event.tpl.php
 * Default theme implementation of calendar event
 *
 * Available variables:
 * - $start_date: 
 * - $end_date: 
 */
?>
<?php if($start_date != NULL || $end_date != NULL): ?>
<div class='calendar-event'>
  <h3>Event Date</h3>
  <?php 
  if($start_date != NULL){
    print "Start: ".l(format_date($start_date), $start_link_path);
    print "<br>";
  }
  if($end_date != NULL){
    print "End:   ".l(format_date($end_date), $end_link_path);
  }
  ?>
<?php endif; ?>
    
</div>
