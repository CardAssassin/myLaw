<?php
// $Id: node-og-group-post.tpl.php,v 1.1 2008/04/25 04:21:45 weitzman Exp $

/**
 * @file node-og-group-post.tpl.php
 * 
 * Og has added a brief section at bottom for printing links to affiliated groups.
 * This template is used by default for non group nodes.
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_user().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

<table class="node-table">
  <tr>
    <?php if ($teaser == 1) : ?>
    <td rowspan=4 class="node-group-author-post-info">
    <?php else : ?>
    <td rowspan=3 class="node-group-author-post-info">
    <?php endif; ?> 
      <?php 
      if ($author_group){
        print $author_group_picture;
        print $author_group;
        print "<br>";
      }
      ?> 

      <?php if ($node->og_groups && $page) {
          print '<div class="groups">'. t('Groups'). ': ';
          print '<div class="links"'.  $og_links['view']. '</div></div>';
   } ?>

      <?php if ($submitted && $page): ?>
        Submitted by:
        <?php print theme('username', $node);?>
        <br>
        <span class='submitted'>
        <?php print format_date($node->created, 'custom', "F jS, Y"); ?>
        </span>
      <?php endif; ?>   
    </td>
  </tr>
  <tr>
    <td class="node-group-author-post-header">
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
    <td colspan=2 class="node-body">
      <div class="content">
        <?php print $content ?>
        <?php //print $node->content['body']['#value']; ?>
        <?php //print $node->content['book_navigation']['#value']; ?>
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
