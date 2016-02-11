<div id="node-<?php print $node->nid; ?>" class="panel panel-spotbox <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

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
      <div class="table">
        <div class="table-row">
          <div class="table-cell gradient-lightgreen">
            <h3 class="panel-title "><?php print render($content['field_os2web_spotbox_text']); ?></h3>
          </div>
        </div>
      </div>
    <?php endif; ?>
    
    <?php if(!empty($spotbox_url)) : ?>
      </a>
    <?php endif; ?>

</div> <!-- /.node -->




