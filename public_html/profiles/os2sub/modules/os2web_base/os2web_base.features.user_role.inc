<?php
/**
 * @file
 * os2web_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function os2web_base_user_default_roles() {
  $roles = array();

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 3,
  );

  return $roles;
}
