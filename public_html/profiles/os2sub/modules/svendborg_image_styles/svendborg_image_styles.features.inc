<?php
/**
 * @file
 * svendborg_image_styles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function svendborg_image_styles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function svendborg_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: full_width.
  $styles['full_width'] = array(
    'label' => 'Full width',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1098,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full_width_medium.
  $styles['full_width_medium'] = array(
    'label' => 'Full width medium',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 898,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: svendborg_content_image.
  $styles['svendborg_content_image'] = array(
    'label' => 'svendborg_content_image',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 918,
          'height' => 432,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'white',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => -10,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 918,
          'height' => 432,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: svendborg_spotbox.
  $styles['svendborg_spotbox'] = array(
    'label' => 'svendborg_spotbox',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 367,
          'height' => 170,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => 2.15,
            'bgcolor' => 'white',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 367,
          'height' => 170,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
