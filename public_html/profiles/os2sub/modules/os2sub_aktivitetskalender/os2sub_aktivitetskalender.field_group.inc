<?php
/**
 * @file
 * os2sub_aktivitetskalender.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2sub_aktivitetskalender_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_calendar_contact|node|event_calendar|form';
  $field_group->group_name = 'group_event_calendar_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event_calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kontakt',
    'weight' => '11',
    'children' => array(
      0 => 'field_event_calendar_field_org',
      1 => 'field_event_calendar_addr',
      2 => 'field_event_calendar_by',
      3 => 'field_event_calendar_kontakt_per',
      4 => 'field_event_calendar_email',
      5 => 'field_event_calendar_phone',
      6 => 'field_event_calendar_zip',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-calendar-contact field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_event_calendar_contact|node|event_calendar|form'] = $field_group;

  return $export;
}
