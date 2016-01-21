<?php
/**
 * @param $menu_name
 * @param null $link
 * @param null $max_depth
 *
 * @return array
 */

function _svendborg_top_menu_get_menu_tree($menu_name, $link = NULL, $depth = NULL) {
  $menu_location = theme_get_setting('menu_location_setting', 'svendborg_subsitetheme');
  if ($menu_location) {
    $menu = menu_tree_all_data($menu_name);
    $menu_layout = array();
    foreach ($menu as $item) {
      $children = $item['below'];
      $menu_layout[] = $children;
    }
    // Attach the CSS and JavaScript assets.
    $path = drupal_get_path('theme', 'svendborg_subsitetheme');
    drupal_add_js($path . '/js/svendborg_top_menu.js');
    return $menu_layout;
  }
  return FALSE;
}