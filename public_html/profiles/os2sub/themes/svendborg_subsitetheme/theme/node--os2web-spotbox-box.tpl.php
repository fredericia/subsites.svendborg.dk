
<div id="node-<?php print $node->nid; ?>" class="panel panel-spotbox <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_suffix); ?>
  <?php $spotbox_url = (isset($variables['elements']['#spotbox_url'])) ? $variables['elements']['#spotbox_url'] : $spotbox_url; ?>
    <?php if(!empty($spotbox_url)) : ?>
      <a href="<?php print $spotbox_url ?>">
      <div class="table">

    <?php endif; ?>
    <?php if(!empty($content['field_os2web_spotbox_big_image'])) : 
      print render($content['field_os2web_spotbox_big_image']);
      else: ?>
      
        <div class="table-row body-tekst" style="height: 170px;">
          <div class="table-cell gradient-lightgreen">
                  <?php print render($content['body']); ?>
          </div>
        </div>
      
          

      <?php endif; ?>
    <?php if(!empty($content['field_os2web_spotbox_video'])) : ?>
    <?php print render($content['field_os2web_spotbox_video']); ?>
    <?php endif; ?>
    
    <?php if(!empty($content['field_os2web_spotbox_text'])) : ?>
        <div class="table-row titel-tekst">
          <div class="table-cell gradient-lightgreen">

              <h3 class="panel-title "><?php print render($content['field_os2web_spotbox_text']); ?></h3>
              <h4><?php print render($content['field_os2web_spotbox_subtitel']); ?></h4>
          </div>
        </div>

    <?php endif; ?>
    
    <?php if(!empty($spotbox_url)) : ?>
      </div>
      </a>
    <?php endif; ?>

</div> <!-- /.node -->




