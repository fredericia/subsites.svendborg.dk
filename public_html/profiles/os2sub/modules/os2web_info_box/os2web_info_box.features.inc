<?php
/**
 * @file
 * os2web_info_box.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_info_box_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os2web_info_box_node_info() {
  $items = array(
    'os2web_info_box' => array(
      'name' => t('OS2web faktaboks'),
      'base' => 'node_content',
      'description' => t('Faktaboks til indholdsside'),
      'has_title' => '1',
      'title_label' => t('Kaldenavn'),
      'help' => '',
    ),
  );
  return $items;
}
