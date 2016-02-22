<?php
/**
 * @file
 * os2sub_projektside.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2sub_projektside_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_projekt|node|os2web_base_contentpage|form';
  $field_group->group_name = 'group_projekt';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'os2web_base_contentpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_os2web_base_group_content';
  $field_group->data = array(
    'label' => 'Projekt',
    'weight' => '10',
    'children' => array(
      0 => 'field_os2web_base_isproject_part',
      1 => 'field_os2web_base_isproject_desc',
      2 => 'field_os2web_base_field_banner',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-projekt field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_projekt|node|os2web_base_contentpage|form'] = $field_group;

  return $export;
}
