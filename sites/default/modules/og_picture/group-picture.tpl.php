<?php
// $Id

/**
 * @file group-picture.tpl.php
 * Default theme implementation to present an picture configured for the
 * user's account.
 *
 * Available variables:
 * - $group_picture: Image set by the group or the site's default. Will be linked
 *   depending on the viewer's permission to view the users profile page.
 * - $group: Array of group information. Potentially unsafe. Be sure to
 *   check_plain() before use.
 *
 * @see template_preprocess_user_picture()
 */
?>
<div class="picture">
  <?php print $group_picture; ?>
</div>
