<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
    $node = node_load($row->nid);
    $image_uri = file_create_url($node->field_banner_billede['und'][0]['uri']);
    $indicator_active_uri = drupal_get_path('theme', 'svendborg_subsitetheme') . '/images/slider_active.png';
    $indicator_inactive_uri = drupal_get_path('theme', 'svendborg_subsitetheme') . '/images/slider_inactive.png';
    $total_row = $view->total_rows;
    $current_row = 1;
    for ($i=0; $i < $view->total_rows; $i++) {
	if ($view->result[$i]->nid == $row->nid) {
	    $current_row = $i+1;
	}
    }
    //print_r('<pre>');
    //print_r($view->total_rows);
    //print_r($view->result);
    //print_r('</pre>');
    
    $indicators = '';
    //adding inactive indicators
    for ($i = 1; $i < $current_row; $i++){
	$indicators .= '<span class="indicator  inactive"> </span>' . '<img src="' . $indicator_inactive_uri. '" class="inactive">' . '</span>';
    }
    //adding active indicator
    $indicators .= '<span class="indicator  active"> </span>' . '<img src="' . $indicator_active_uri. '" class="active">' . '</span>';
    //adding inactive indicators
    for ($i = $current_row; $i < $view->total_rows; $i++){
	$indicators .= '<span class="indicator inactive"> </span>' . '<img src="' . $indicator_inactive_uri. '" class="inactive">' . '</span>';
    }

    $html = '<div class="slider-cover" style="background-image: url(' . $image_uri . ');">';
	$html .= '<div class="container">';
	    $html .= '<div class="title">';
		    $html .= '<a href="/node/' . $row->nid . '">';
			$html .= '<span class="indicators">';
			    $html .= $indicators;
			$html .= '</span>';
			$html .= $node->title;
		    $html .= '</a>';
	    $html .= '</div>';
	$html .= '</div>';
    $html .= '</div>';
    print $html;
?>