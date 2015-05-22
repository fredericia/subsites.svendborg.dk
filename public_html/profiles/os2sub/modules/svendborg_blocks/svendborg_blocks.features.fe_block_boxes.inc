<?php
/**
 * @file
 * svendborg_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function svendborg_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Login/Sitemap links';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'login_sitemap_links';
  $fe_block_boxes->body = '<div class="top-menu right-block">
	<a  class="login" href="/user">login </a>|<a href="/sitemap">sitemap</a>
</div>
';

  $export['login_sitemap_links'] = $fe_block_boxes;

  return $export;
}
