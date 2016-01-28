<?php
/**
 * @file
 * os2web_spotbox.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function os2web_spotbox_taxonomy_default_vocabularies() {
  return array(
    'os2web_base_tax_promoteto' => array(
      'name' => 'Forfrem til',
      'machine_name' => 'os2web_base_tax_promoteto',
      'description' => 'Forside og portalforsider',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_base_tax_site_structure' => array(
      'name' => 'Overordnet placering og sitestruktur',
      'machine_name' => 'os2web_base_tax_site_structure',
      'description' => 'Vælg de steder i hjemmesidens overordnede struktur hvor indholdet skal publiceres.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'os2web_taxonomies_tax_comittee' => array(
      'name' => 'AcadreMMComittee',
      'machine_name' => 'os2web_taxonomies_tax_comittee',
      'description' => 'Taxonomi indeholdende diverse udvalg med system-id fra Acadre MM. Bruges til mapning af dagsordensvisning på web.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_taxonomies_tax_editor_tag' => array(
      'name' => 'Stikord',
      'machine_name' => 'os2web_taxonomies_tax_editor_tag',
      'description' => 'Taksonomi til at opsamle redaktørers egne tags',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_taxonomies_tax_kle' => array(
      'name' => 'KLE',
      'machine_name' => 'os2web_taxonomies_tax_kle',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_taxonomies_tax_org' => array(
      'name' => 'Organisation',
      'machine_name' => 'os2web_taxonomies_tax_org',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_taxonomies_tax_places' => array(
      'name' => 'Egennavne/stednavne',
      'machine_name' => 'os2web_taxonomies_tax_places',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'os2web_taxonomies_tax_politics' => array(
      'name' => 'Politik',
      'machine_name' => 'os2web_taxonomies_tax_politics',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
