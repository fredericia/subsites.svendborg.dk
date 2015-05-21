<?php
/**
 * @file
 * region--content_bottom.tpl.php
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $attributes: String of attributes that contain things like classes and ids.
 * - $content_attributes: The attributes used to wrap the content. If empty,
 *   the content will not be wrapped.
 * - $region: The name of the region variable as defined in the theme's .info
 *   file.
 * - $page: The page variables from bootstrap_process_page().
 *
 * Helper variables:
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see bootstrap_preprocess_region().
 * @see bootstrap_process_page().
 *
 * @ingroup themeable
 */
?>
jhikkjkj
<?php if ($content): ?>
  <div<?php print $attributes; ?>>
    <?php if ($content_attributes): ?><div<?php print $content_attributes; ?>><?php endif; ?>
    <?php print $content; ?>
    <?php if ($content_attributes): ?></div><?php endif; ?>
  </div>
<?php endif; ?>
<?php if(!empty($page['page']['related_links'])) : ?>
      <div class="panel panel-primary with-arrow">
        <div class="panel-heading">
          <h3 class="panel-title"><?php print t('Relaterede sider'); ?></h3>
        </div>
        <div class="panel-body">
          <ul class="nav">
          <?php foreach ($page['page']['related_links'] as $link) : ?>
            <li>
              <?php if (isset($link['url'])): ?>
                <?php print l($link['title'], $link['url'], array('attributes' => array('class' => $link['class']))); ?>
              <?php else: ?>
                <?php print l($link['title'], drupal_get_path_alias('node/' . $link['nid']), array('attributes' => array('class' => $link['class']))); ?>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
         </ul>
        </div>
      </div>
    <?php endif; ?>