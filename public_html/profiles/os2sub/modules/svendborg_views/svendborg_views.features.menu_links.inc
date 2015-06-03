<?php
/**
 * @file
 * svendborg_views.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function svendborg_views_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_blog:nyheder
  $menu_links['main-menu_blog:nyheder'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nyheder',
    'router_path' => 'nyheder',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:nyheder',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_calendar:calendar/upcoming
  $menu_links['main-menu_calendar:calendar/upcoming'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'calendar/upcoming',
    'router_path' => 'calendar/upcoming',
    'link_title' => 'Calendar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_calendar:calendar/upcoming',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_forside:<front>
  $menu_links['main-menu_forside:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_forside:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
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
  // Exported menu link: main-menu_gallery:gallery
  $menu_links['main-menu_gallery:gallery'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gallery',
    'router_path' => 'gallery',
    'link_title' => 'Gallery',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_gallery:gallery',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_kalender:calendar/upcoming
  $menu_links['main-menu_kalender:calendar/upcoming'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'calendar/upcoming',
    'router_path' => 'calendar/upcoming',
    'link_title' => 'Kalender',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_kalender:calendar/upcoming',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_search:search
  $menu_links['main-menu_search:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_sg:search
  $menu_links['main-menu_sg:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Søg',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_sg:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Calendar');
  t('Forside');
  t('Galleri');
  t('Gallery');
  t('Home');
  t('Kalender');
  t('Search');
  t('Søg');


  return $menu_links;
}
