<?php
// $Id$

/**
 * @file scheduler.tpl.php
 * Default theme implementation of calendar event
 *
 * Available variables:
 * - $publish_on: 
 * - $unpublish_on: 
 */
?>
<div class='scheduler'>
  <h3>Publishing Dates</h3>
  <?php 
  if($publish_on != NULL){
    print "Posted: ".format_date($publish_on);
    print "<br>";
  }
  if($unpublish_on != NULL){
    print "Expires:   ".format_date($unpublish_on);
  }
  ?>
    
</div>
