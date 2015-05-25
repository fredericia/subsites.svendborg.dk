<?php
/**
 * @file
 * svendborg_gallery.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function svendborg_gallery_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_galleri:gallery
  $menu_links['main-menu_galleri:gallery'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gallery',
    'router_path' => 'gallery',
    'link_title' => 'Galleri',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_galleri:gallery',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Galleri');


  return $menu_links;
}
