<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function svendborg_subsitetheme_form_system_theme_settings_alter(&$form, &$form_state) {
 $form['svendborg_subsitetheme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Svendborg subsitetheme Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
 $form['svendborg_subsitetheme_setting']['frontpage_layout'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Frontpage Layout'),
    '#weight' => -2,
    '#description'   => t("Select a layout for the frontpage."),
  );
  $form['svendborg_subsitetheme_setting']['frontpage_layout']['welcome'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>welcome text</strong> in a frontpage'),
    '#default_value' => theme_get_setting('welcome','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show welcome text in page."),
  );
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['activites'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>Activites block</strong> in a frontpage'),
    '#default_value' => theme_get_setting('activites','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show Activites block in page."),
  );
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['large_news'] = array(
    '#type' => 'radios',
    '#title' => t('Show <strong>large news</strong> in a frontpage'),
    '#default_value' => theme_get_setting('large_news','svendborg_subsitetheme'),
     '#options' => array(0 => t('don\'t show'), 2 => t('2 large news'), 3 => t('3 large news'), 4 => t('4 large news')),
    '#description'   => t("Check this option to show 2 large news in page."),
  );/*
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['three_large_news'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>3 large news</strong> in a frontpage'),
    '#default_value' => theme_get_setting('three_large_news','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show 3 large news in page."),
  );
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['four_large_news'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>4 large news</strong> in a frontpage'),
    '#default_value' => theme_get_setting('four_large_news','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show 4 large news in page."),
  );*/
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['promoted_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong> nodes promoted to frontpage</strong>'),
    '#default_value' => theme_get_setting('promoted_nodes','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show nodes promoted to frontpage block."),
 );
 $form['svendborg_subsitetheme_setting']['frontpage_layout']['promoted_nodes_location'] = array(
    '#type' => 'select',
    '#title' => t('<strong>Nodes promoted to frontpage</strong> location'),
    '#options' => array(
         'front' => t('Front page (default)'),
         'slider' => t('Slider banner'),
    ),
    '#default_value' => theme_get_setting('promoted_nodes_location','svendborg_subsitetheme'),
    '#description'   => t("Where the promoted nodes block should be rendered.<br/><strong>Please note!</strong> If Slider banner option is selected, block will be only visible if Slider is set to be visible"),
 );
  $form['svendborg_subsitetheme_setting']['frontpage_layout']['latest_news'] = array(
    '#type' => 'radios',
    '#title' => t('Show <strong> latest news in frontpage</strong>'),
    '#default_value' => theme_get_setting('latest_news','svendborg_subsitetheme'),
    '#options' => array(0 => t('don\'t show'), 2 => t('2 columns block'), 3 => t('3 columns block')),
    
    '#description'   => t("Check this option to show latest news block."),
 );
 
 
 $form['svendborg_subsitetheme_setting']['slider_settings'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Slider banner settings'),
    '#weight' => -1,
    '#description'   => t("Specify the settings for the front page slider"),
 );
 $form['svendborg_subsitetheme_setting']['slider_settings']['slider_active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show <strong>slider</strong>'),
    '#default_value' => theme_get_setting('slider_active','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show slider banner on front page."),
 );
 $form['svendborg_subsitetheme_setting']['slider_settings']['slider_overlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show dark overlay on <strong>slider</strong>'),
    '#default_value' => theme_get_setting('slider_overlay','svendborg_subsitetheme'),
    '#description'   => t("Check this option to show dark overlay on the slider banner"),
 );
 $form['svendborg_subsitetheme_setting']['slider_settings']['calendar_page_slider_image'] = array(
   '#title' => t('Calendar page slider image'),
    '#description' => t('Image for calendar slider'),
     '#type' => 'managed_file',

    '#upload_location' => 'public://',
   '#upload_validators' => array(
   'file_validate_extensions' => array('gif png jpg jpeg'),
 ),
    '#default_value' => theme_get_setting('calendar_page_slider_image','svendborg_subsitetheme'),
  );
$form['svendborg_subsitetheme_setting']['slider_settings']['calendar_page_slider_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text for banner on calendar page '),
    '#default_value' => theme_get_setting('calendar_page_slider_text','svendborg_subsitetheme'),
    '#description'   => t("Text for banner on calendar page"),
 );
$form['#submit'][] = 'svendborg_subsitetheme_settings_form_submit';
$themes = list_themes();

$active_theme = $GLOBALS['theme_key'];

$form_state['build_info']['files'][] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';
}

function svendborg_subsitetheme_settings_form_submit(&$form, $form_state) {
   $image_fid = $form_state['values']['calendar_page_slider_image'];
  
  $image = file_load($image_fid);
  if (is_object($image)) {

    // Check to make sure that the file is set to be permanent.

    if ($image->status == 0) {
      $image->status = FILE_STATUS_PERMANENT;

      file_save($image);
    file_usage_add($image, 'svendborg_subsitetheme', 'theme', 1);

     }

  }

}
