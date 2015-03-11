<?php
/**
 * @file
 * os2web_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function os2web_base_image_default_styles() {
  $styles = array();

  // Exported image style: os2web_base_style_content.
  $styles['os2web_base_style_content'] = array(
    'name' => 'os2web_base_style_content',
    'effects' => array(
      1 => array(
        'label' => 'Skalér',
        'help' => 'Skalering bevarer billedets højde-bredde-forhold. Hvis kun den ene dimension angives vil den anden blive beregnet.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'label' => 'Beskær',
        'help' => 'Beskæring fjerner dele af billedet for at give det de angivne dimensioner.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'os2web_base_style_content',
  );

  // Exported image style: os2web_base_style_image.
  $styles['os2web_base_style_image'] = array(
    'name' => 'os2web_base_style_image',
    'effects' => array(
      1 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 470,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_image',
  );

  // Exported image style: os2web_base_style_medium.
  $styles['os2web_base_style_medium'] = array(
    'name' => 'os2web_base_style_medium',
    'effects' => array(
      5 => array(
        'label' => 'Skalér',
        'help' => 'Skalering bevarer billedets højde-bredde-forhold. Hvis kun den ene dimension angives vil den anden blive beregnet.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      6 => array(
        'label' => 'Beskær',
        'help' => 'Beskæring fjerner dele af billedet for at give det de angivne dimensioner.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'os2web_base_style_medium',
  );

  // Exported image style: os2web_base_style_news_big.
  $styles['os2web_base_style_news_big'] = array(
    'name' => 'os2web_base_style_news_big',
    'effects' => array(
      2 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 214,
          'height' => 116,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_big',
  );

  // Exported image style: os2web_base_style_news_medium.
  $styles['os2web_base_style_news_medium'] = array(
    'name' => 'os2web_base_style_news_medium',
    'effects' => array(
      4 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_medium',
  );

  // Exported image style: os2web_base_style_news_small.
  $styles['os2web_base_style_news_small'] = array(
    'name' => 'os2web_base_style_news_small',
    'effects' => array(
      3 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 69,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_news_small',
  );

  // Exported image style: os2web_base_style_rotating.
  $styles['os2web_base_style_rotating'] = array(
    'name' => 'os2web_base_style_rotating',
    'effects' => array(
      1 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_rotating',
  );

  // Exported image style: os2web_base_style_rotating_small.
  $styles['os2web_base_style_rotating_small'] = array(
    'name' => 'os2web_base_style_rotating_small',
    'effects' => array(
      2 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 161,
          'height' => 65,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'os2web_base_style_rotating_small',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function os2web_base_node_info() {
  $items = array(
    'media' => array(
      'name' => t('Medier'),
      'base' => 'node_content',
      'description' => t('Video og audio.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'os2web_base_contentpage' => array(
      'name' => t('Indholdsside'),
      'base' => 'node_content',
      'description' => t('Almindelig webside til generel brug på sitet.'),
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
    'os2web_base_news' => array(
      'name' => t('Nyhed'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
    'os2web_base_selfservice_link' => array(
      'name' => t('Selvbetjening'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
  );
  return $items;
}
