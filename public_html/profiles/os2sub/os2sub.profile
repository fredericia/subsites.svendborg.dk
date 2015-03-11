<?php

/**
 * @file
 * This file includes all hooks to proper set up profile during install
 */

/**
 * Name of profile; visible in profile selection form.
 */
define('PROFILE_NAME', 'OS2sub');

/**
 * Description of profile; visible in profile selection form.
 */
define('PROFILE_DESCRIPTION', 'Generisk Installation af OS2sub.');

/**
 * Implements hook_install_tasks().
 */
function os2sub_install_tasks() {
  $task = array(
   'os2sub_import_database' => array(
     'type' => 'normal',
     'display_name' => st('Import default database'),
   ),
//    'os2sub_profile_prepare' => array(
//      'type' => 'normal',
//      'display_name' => st('Prepare OS2web..'),
//    ),
   'os2sub_settings_form' => array(
     'display_name' => st('Setup OS2Web'),
     'type' => 'form',
   ),

  );
  return $task;
}

/**
 * Implements hook_profile_prepare().
 */
function os2sub_profile_prepare() {
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  // Menu rebuild neccesary to load xpath_parser
  menu_rebuild();
  drupal_get_form('os2sub_settings_form');
  drupal_set_message('Database import complete, please reload this form to continue.', 'ok');
}

/**
 * Implements hook_form().
 */
function os2sub_settings_form($install_state) {
  drupal_set_title(st('Settings'));

  // Theme setups.
  $form['os2sub_theme_group'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title' => t('Theme configuration'),
    '#weight' => 20,
  );
  $form['os2sub_theme_group']['os2sub_theme_logo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Upload Logo'),
    '#description' => t('The uploaded image will be used as the themes logo.'),
    '#upload_location' => 'public://',
  );
  $form['#submit'][] = 'os2sub_settings_form_submit';
  return system_settings_form($form);
}

/**
 * Form settings submit callback function.
 */
function os2sub_settings_form_submit(&$form, $form_state) {
  $theme_settings = variable_get('theme_os2sub_core_theme_settings', array());
  if ($theme_settings) {

    // If logo is uploaded, save it in os2web theme.
    if (!empty($form['os2sub_theme_group']['os2sub_theme_logo']['#file']->uri)) {

      $theme_settings['logo_path'] = $form['os2sub_theme_group']['os2sub_theme_logo']['#file']->uri;
      $theme_settings['default_logo'] = 0;

      variable_set('theme_os2sub_core_theme_settings', $theme_settings);
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function os2sub_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'OS2sub Test';
  $form['update_notifications']['update_status_module']['#default_value'] = array(0, 0);
  $form['server_settings']['site_default_country']['#default_value'] = 'DK';
  $form['server_settings']['#access'] = FALSE;
  $form['update_notifications']['#access'] = FALSE;
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
}

/**
 * Sets the default language to danish.
 */
function os2sub_profile_details() {
  return array(
    'name' => PROFILE_NAME,
    'description' => PROFILE_DESCRIPTION,
//    'language' => "da",
    'language' => "da",
  );
}
