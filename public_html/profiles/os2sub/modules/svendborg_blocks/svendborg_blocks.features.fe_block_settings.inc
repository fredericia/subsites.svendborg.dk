<?php
/**
 * @file
 * svendborg_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function svendborg_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-login_sitemap_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'da',
      1 => 'en',
    ),
    'i18n_mode' => 1,
    'machine_name' => 'login_sitemap_links',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'os2web_bootstrap_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'os2web_bootstrap_theme',
        'weight' => 0,
      ),
      'svendborg_subsitetheme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'svendborg_subsitetheme',
        'weight' => -23,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-svendborg_footer_text'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(
      0 => 'da',
      1 => 'en',
    ),
    'i18n_mode' => 1,
    'machine_name' => 'svendborg_footer_text',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'os2web_bootstrap_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'os2web_bootstrap_theme',
        'weight' => 0,
      ),
      'svendborg_subsitetheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'svendborg_subsitetheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(
      0 => 'da',
      1 => 'en',
    ),
    'i18n_mode' => 1,
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'os2web_bootstrap_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'os2web_bootstrap_theme',
        'weight' => 0,
      ),
      'svendborg_subsitetheme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'svendborg_subsitetheme',
        'weight' => -24,
      ),
    ),
    'title' => 'Vælg sprog: ',
    'visibility' => 0,
  );

  return $export;
}
