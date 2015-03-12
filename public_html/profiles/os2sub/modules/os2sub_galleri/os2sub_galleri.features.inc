<?php
/**
 * @file
 * os2sub_galleri.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2sub_galleri_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os2sub_galleri_node_info() {
  $items = array(
    'os2web_base_gallery' => array(
      'name' => t('Galleri'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
