<?php
/**
 * @file
 * os2sub_projektside.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function os2sub_projektside_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_os2web_base_isproject'
  $field_bases['field_os2web_base_isproject'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_isproject',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'visikke',
        1 => 'vis',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_os2web_base_isproject_desc'
  $field_bases['field_os2web_base_isproject_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_isproject_desc',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_os2web_base_isproject_part'
  $field_bases['field_os2web_base_isproject_part'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_os2web_base_isproject_part',
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
        'event_calendar' => 0,
        'media' => 0,
        'os2web_base_contentpage' => 'os2web_base_contentpage',
        'os2web_base_gallery' => 'os2web_base_gallery',
        'os2web_base_news' => 0,
        'os2web_base_selfservice_link' => 0,
        'os2web_contact_contact' => 0,
        'velkomst' => 0,
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
