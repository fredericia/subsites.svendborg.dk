<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>
  <div class="caption">
  <?php $spotbox_url = (isset($variables['elements']['#spotbox_url'])) ? $variables['elements']['#spotbox_url'] : $spotbox_url; ?>
    <?php if(!empty($spotbox_url)) : ?>
      <a href="<?php print $spotbox_url ?>">
    <?php endif; ?>

    <?php if(!empty($content['field_os2web_spotbox_big_image'])) : ?>
      <?php print render($content['field_os2web_spotbox_big_image']); ?>
    <?php endif; ?>
    <?php if(!empty($content['field_os2web_spotbox_video'])) : ?>
    <?php print render($content['field_os2web_spotbox_video']); ?>
    <?php endif; ?>
    
    <?php if(!empty($content['field_os2web_spotbox_text'])) : ?>
    <div class="item-text">
      <div class="bubble">
        <span>
          <h3><?php print render($content['field_os2web_spotbox_text']); ?></h3>
        </span>
      </div>
    </div>
    <?php endif; ?>

    <?php if(!empty($spotbox_url)) : ?>
      </a>
    <?php endif; ?>
  </div>

</div> <!-- /.node -->


<?php
$field_image_all = field_get_items('node',$node,'field_media');

$img_rendered = field_view_value('node',$node,'field_media',$field_image_all[0],
array('type' => 'file_rendered','settings'=>array('file_view_mode' => 'custom_view_mode')));

?>