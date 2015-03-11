<?php
/**
 * @file
 * os2web_news_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function os2web_news_page_taxonomy_default_vocabularies() {
  return array(
    'os2web_news_page_newstypes' => array(
      'name' => 'Nyhedstyper',
      'machine_name' => 'os2web_news_page_newstypes',
      'description' => 'Nyhedstyper til Nyheder',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
