<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$node = node_load($row->nid);

if (isset($node->field_event_calendar_image['und'][0]['uri'])){
$style = 'medium';
$public_filename = image_style_url($style, $node->field_event_calendar_image['und'][0]['uri']);
global $language ;

}
                
?>
<div class="views-row row">

   <div class="col-sm-3 col-xs-12  ">
        <div class="event-date">
            <span class="day"> <?php print date("j.", strtotime($node->event_calendar_date['und'][0]['value']));?> </span>
            <span class="month"><?php print date("M Y", strtotime($node->event_calendar_date['und'][0]['value']));?></span>
            <span class="time"><?php print date("H:i", strtotime($node->event_calendar_date['und'][0]['value']));?>  - <?php print date("H:i", strtotime($node->event_calendar_date['und'][0]['value2']));?> </span>
        </div>
    </div>
    <div class="col-sm-9 col-xs-12 ">
        <div class="event-content">
            <div class="short-aktivity">
                <div class="col-sm-9 col-xs-12 title"><?php print $node->title?></div> 
                <div class="col-sm-3 col-xs-12 open-link"><a class='open-activity' href="/" ><?php print t('Show more')?></a></div> 
            </div>
        <div class="full-aktivity">
            <div class="event-description">
                <?php if(isset($public_filename)):?>
                    <div class="col-sm-3 col-xs-12 image"><img src="<?php print  $public_filename?>"></div> 
                    <div class="col-sm-9 col-xs-12"><h1><?php print $node->title?></h1> <?php print $node->body['und'][0]['value']?></div> 
                <?php else:?>
                    <div class="col-xs-12 "><h1><?php print $node->title?></h1> <?php print $node->body['und'][0]['value']?></div> 
                <?php endif;?>
            </div> 
            <div class="event-contact">
                <div class="col-sm-3 col-xs-12">
                    <label> <?php print t('Address');?></label>
                    <div><?php print $node->field_event_calendar_field_org['und'][0]['value']?></div>
                    <div><?php print $node->field_event_calendar_addr['und'][0]['value']?></div>
                    <div><?php print $node->field_event_calendar_zip['und'][0]['value']?>, <?php print $node->field_event_calendar_by['und'][0]['value']?></div>
                </div> 
                 <div class="col-sm-5 col-xs-12">
                    <label> <?php print t('Contact');?></label>
                    <div><?php print $node->field_event_calendar_kontakt_per['und'][0]['value']?></div>
                    <div><?php print $node->field_event_calendar_phone['und'][0]['value']?></div>
                    <?php if (isset($node->field_event_calendar_email['und'][0]['value'])): ?>
                    <div><a href="mailto:<?php print $node->field_event_calendar_email['und'][0]['value']?>"> <?php print t('Send en mail');?></a></div>
                   <?php endif; ?>
                 </div>
                 <div class="col-sm-3 col-xs-12 col-sm-offset-1">
                     <?php global $language; ?>
                     <a class="btn-back gradient-lightgreen" href="<?php print url(drupal_get_path_alias('node/' . $node->nid));?>"><?php print t('Book your place'); ?></a>
                </div>
            </div>
       </div>      
      </div>
    </div>
</div>