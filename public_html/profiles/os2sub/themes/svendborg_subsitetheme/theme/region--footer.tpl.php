<?php
/**
 * @file
 * region--sidebar.tpl.php
 *
 * Default theme implementation to display the "sidebar_first" and
 * "sidebar_second" regions.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $attributes: String of attributes that contain things like classes and ids.
 * - $content_attributes: The attributes used to wrap the content. If empty,
 *   the content will not be wrapped.
 * - $region: The name of the region variable as defined in the theme's .info
 *   file.
 * - $page: The page variables from bootstrap_process_page().
 *
 * Helper variables:
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see bootstrap_preprocess_region().
 * @see bootstrap_process_page().
 *
 * @ingroup themeable
 */
?>
  <footer class="region region_footer lcontainer-fluid">
    <div class="lcontainer-fluid clearfix"  id="footer-first-block">
      <div class="container footer-first-block">
        <div class="row-no-padding">
            <div class='footer-logo col-sm-2 col-xs-12'>
            <img id="footer-logo" src="/<?php print drupal_get_path('theme','svendborg_subsitetheme'); ?>/images/footer_logo.png" title="<?php print $page['site_name'] ?>" />

          </div>
          <div class="col-sm-10 col-sx-12">  
           <?php print _svendborg_subsitetheme_block_render('block', '2'); ?> 
          </div>    
      <?php /*
       $tree = menu_tree_all_data('menu-indholdsmenu', $link = NULL, $max_depth = 3);

        $count = 0;
        foreach ($tree as $key => $menu_item) {
          if (!$menu_item['link']['hidden']) {
            if ($count > 3) {
              continue;
            }
            $path = $alias = drupal_get_path_alias($menu_item['link']['link_path']);
            print "<div class='menu-". $menu_item['link']['mlid']. " footer-indholsdmenu col-xs-12 col-sm-6 col-md-3'>";
print "<h2 class='menu-footer " . $menu_item['link']['link_title']. "'>
            <a title='" . $menu_item['link']['link_title'] . "' href='/". $path ."' class='" . $menu_item['link']['link_title']. "'>" . $menu_item['link']['link_title'] . "</a></h2>";
            if($menu_item['link']['has_children'] && !$menu_item['link']['hidden']) {

              $tree_display =menu_tree_output($menu_item['below']);
              print render($tree_display);
            }
            print "</div>";
            $count += 1;
          }
        }
      */
      ?>
      <?php if ($content_attributes): ?><div<?php print $content_attributes; ?>><?php endif; ?>
      <?php //print $content; ?>
      <?php if ($content_attributes): ?></div><?php endif; ?>
      </div>
      </div>
    </div>
    <!--footer Tilmeld-->
    <div class="lcontainer-fluid clearfix"  id="footer-tilmeld-block">
      <div class="container footer-tilmeld-block">
        <div class="row">
            <?php print _svendborg_subsitetheme_block_render('block', '3'); ?> 
         </div>
      </div>  
    </div>    
    <!-- footer contacts social-icons -->
    <div class="lcontainer-fluid clearfix" id="footer-contacts">
      <div class="container">
        <div class="row">
        <div class="col-xs-12 social-icons">
          <a href="https://www.facebook.com/Svendborg" title="Svendborg Kommune Facebook" class="footer_fb" target="_blank">facebook</a>
          <a href="https://www.twitter.com/" title="Svendborg Kommune Twitter" class="footer_twitter" target="_blank">facebook</a>
          <a href="http://www.linkedin.com/company/svendborg-kommune" title="Svendborg Kommune Linkedin" class="footer_linkedin" target="_blank">linkedin</a>
          <a href="http://www.youtube.com/user/wwwsvendborgdk" title="Svendborg Kommune Youtube" class="footer_flickr" target="_blank">youtube</a>
        </div>
       
        <div class="col-xs-12 footer-address">
            Firmanavn | Layoutvej 12 | 5700 Svendborg | Tlf 00 00 00 00
        </div> 
         <div class="col-xs-12 footer-copyright">
          Copyright 2015® · Firmanavn</div>
        </div>
        </div>
      </div>
    </div>
   </footer>
