<?php
/**
 * @file
 * os2sub_banner.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function os2sub_banner_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_banner_billede'
  $field_bases['field_banner_billede'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_billede',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_banner_link'
  $field_bases['field_banner_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_link',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'banner' => 0,
        'event_calendar' => 'event_calendar',
        'media' => 0,
        'os2web_base_contentpage' => 'os2web_base_contentpage',
        'os2web_base_gallery' => 'os2web_base_gallery',
        'os2web_base_news' => 'os2web_base_news',
        'os2web_base_selfservice_link' => 0,
        'os2web_borger_dk_article' => 0,
        'os2web_contact_contact' => 0,
        'os2web_spotbox_box' => 0,
        'page' => 0,
        'subsite' => 0,
        'velkomst' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_banner_vis_paa_sider'
  $field_bases['field_banner_vis_paa_sider'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_banner_vis_paa_sider',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'banner' => 0,
        'event_calendar' => 'event_calendar',
        'media' => 0,
        'os2web_base_contentpage' => 'os2web_base_contentpage',
        'os2web_base_gallery' => 'os2web_base_gallery',
        'os2web_base_iframe' => 'os2web_base_iframe',
        'os2web_base_news' => 'os2web_base_news',
        'os2web_base_rotating_image' => 'os2web_base_rotating_image',
        'os2web_base_selfservice_link' => 0,
        'os2web_contact_contact' => 0,
        'os2web_spotbox_box' => 0,
        'webform' => 'webform',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
