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
    $overlay_class = '';
    if (theme_get_setting('slider_overlay','svendborg_subsitetheme')) {
	$background = "background-image: url('" . $image_uri . "')"
	    . "background-image: -moz-linear-gradient(left, rgba(0,0,0,0.85) 0%, rgba(0,0,0,0.85) 100%), url('" . $image_uri . "');"
	    . "background-image: -webkit-gradient(left top, right top, color-stop(0%, rgba(0,0,0,0.85)), color-stop(100%, rgba(0,0,0,0.85))), url('" . $image_uri . "');"
	    . "background-image: -webkit-linear-gradient(left, rgba(0,0,0,0.85) 0%, rgba(0,0,0,0.85) 100%), url('" . $image_uri . "');"
	    . "background-image: -o-linear-gradient(left, rgba(0,0,0,0.85) 0%, rgba(0,0,0,0.85) 100%), url('" . $image_uri . "');"
	    . "background-image: -ms-linear-gradient(left, rgba(0,0,0,0.85) 0%, rgba(0,0,0,0.85) 100%), url('" . $image_uri . "');"
	    . "background-image: linear-gradient(to right, rgba(0,0,0,0.85) 0%, rgba(0,0,0,0.85) 100%), url('" . $image_uri . "');"
	    . "filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#000000', endColorstr='#000000', GradientType=1 );";
	$overlay_class = 'overlay';
    } else {
	$background = "background-image: url('" . $image_uri . "')";
    }

    $show_frontpage_nodes = (theme_get_setting('promoted_nodes','svendborg_subsitetheme') && theme_get_setting('promoted_nodes_location','svendborg_subsitetheme') === 'slider');

    $html = '<div class="slider-cover single ' . $overlay_class . '" style="' . $background .'">';
	$html .= '<div class="container">';
	    $html .= '<div class="row">';
		$html .= '<div class="' . ($show_frontpage_nodes? 'col-xs-7' : 'text-center') . '">';
		    $html .= '<div class="title">';
			    $html .= $node->title;
		    $html .= '</div>';
		    $html .= '<a href="/node/' . $row->nid . '" class="btn gradient-deepdarkgreen">Tag kontakt idag';
		    $html .= '</a>';
		$html .= '</div>';//class="col-xs-8"

		//printing frontpage_nodes block, if activated
		if ($show_frontpage_nodes) {
		    $html .= '<div class="col-xs-4 col-xs-offset-1">';
		    $html .= _svendborg_subsitetheme_block_render('views', 'frontpage_nodes-block');
		    $html .= '</div>';
		}
	    $html .= '</div>';//class="row"
	$html .= '</div>';//class="conteiner"
    $html .= '</div>';//class="slider-cover"
    print $html;
?>