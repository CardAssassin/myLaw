<?php
// $Id$

/**
 * @file calendar-event.tpl.php
 * Default theme implementation of calendar event
 *
 * Available variables:
 * - $previous_nid: 
 * - $next_nid: 
 */
?>
<div class='calendar-event-repeat'>
  
  
  <?php 
  if($previous_nid != NULL || $next_nid != NULL){
    print "<h3>Repeated Events</h3>";
  }
  if($previous_nid != NULL){
    print l('Previous Event', 'node/' . $previous_nid);
    print "<br>";
  }
  if($next_nid != NULL){
     print l('Next Event', 'node/' . $next_nid);
  }
  ?>
    
</div>
