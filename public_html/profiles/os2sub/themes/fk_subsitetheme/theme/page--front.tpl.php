<?php if ($page['navigation']): ?>
  <?php print render($page['navigation']); ?>
<?php endif; ?>

<div class='front-main-container-wrapper'>
  <div class='main-container container'>
    <?php 
      print render($page['header']); 

      if(module_exists(os2web_spotbox)) {
            if (theme_get_setting('spotbox','fk_subsitetheme')) :
            ?>
              <div class="spotboxes row">
                <?php 
                  $view = views_get_view('os2web_frontpage_spotboxes');
                  print $view->render('block');
                ?>
              </div>
            <?php endif;
          } ?>      

    <div class='row'>
      <!-- page--front.tpl.php-->
      <div class="col-sm-8  col-xs-12">          
          
        <?php if (theme_get_setting('welcome','fk_subsitetheme')) :?>
      <div class="welcome-text">
        <?php //$block_search_form = module_invoke('search', 'block_view', 'search'); ?>
        <?php $view = views_get_view('frontpage_welcome_text');
              print $view->render('fk_frontpage_welcome');
        ?>
      </div>
      <?php endif;?>
      <?php if (theme_get_setting('large_news','fk_subsitetheme')== 2) :?>
      <div class="news-block">
                <?php if (theme_get_setting('newstext','fk_subsitetheme')) :?>
            <h2 class="newstitle block-title 2-news"><?php print theme_get_setting('newstext', 'fk_subsitetheme') ?></h2>
        <?php endif;?>
        <?php //$block_search_form = module_invoke('search', 'block_view', 'search'); ?>
        <?php $view = views_get_view('fk_news_view');
              print $view->render('block_5');
        ?>
      </div>
      <?php endif;?>
      <?php if (theme_get_setting('latest_news','fk_subsitetheme')== 2) :?>
      <div class="latest-news-block">
        <?php 
        
      $view = views_get_view('fk_news_view');
      $view->set_display('fk_latest_news');
      $view->set_offset(theme_get_setting('large_news','fk_subsitetheme'));
      $view->pre_execute();
      $view->execute();
      //var_dump(views_get_view_result('fk_news_view', 'fk_latest_news'));
      if (count( $view->result)>0) 
       print '<h2 class="block-title">' . t($view->get_title()) . '</h2>' . $view->render();
              
        ?>
      </div>
     <?php endif;?>
      </div>
      <div class="region region-sidebar-second col-sm-4 col-xs-12">
          <?php if (theme_get_setting('promoted_nodes','fk_subsitetheme') ):?>
       <div class="frontpage-nodes-block <?php (theme_get_setting('promoted_nodes_location','fk_subsitetheme') === 'slider')?  print 'hidden-sm hidden-md hidden-lg' : print ''?>">
     
        <?php print _fk_subsitetheme_block_render('views', 'frontpage_nodes-block'); ?>
      </div>
      <?php endif;?>
     
          <?php if (theme_get_setting('facebookfeed','fk_subsitetheme')) :?>

            <div style="width: 100%">
             <div id="fb-root"></div>
                <script>(function(d, s, id) {
                  var js, fjs = d.getElementsByTagName(s)[0];
                  if (d.getElementById(id)) return;
                  js = d.createElement(s); js.id = id;
                  js.src = "//connect.facebook.net/da_DK/sdk.js#xfbml=1&version=v2.5&appId=198415943519297";
                  fjs.parentNode.insertBefore(js, fjs);
                }(document, 'script', 'facebook-jssdk'));</script>
                
                
                <div class="fb-page" style="margin-bottom: 20px;" 
                  <?php if (theme_get_setting('facebook_url', 'fk_subsitetheme')):?>
                    
                    data-href="<?php print theme_get_setting('facebook_url', 'fk_subsitetheme') ?>"
                    
                    <?php else : ?>
                    data-href="https://www.facebook.com/fk" 
                    <?php endif; ?>
                    
                  data-tabs="timeline,events" 
                  data-small-header="true" 
                  data-width="400" 
                  data-adapt-container-width="true" 
                  data-hide-cover="false"
                  data-show-facepile="false">
                    <div class="fb-xfbml-parse-ignore">
                      
                      <?php if (theme_get_setting('facebook_url', 'fk_subsitetheme')):?>

                      <blockquote cite="<?php print theme_get_setting('facebook_url', 'fk_subsitetheme') ?>">
                        <a href="<?php print theme_get_setting('facebook_url', 'fk_subsitetheme') ?>">
                          
                          <?php if (theme_get_setting('company-name', 'fk_subsitetheme')):?>
                              <?php print theme_get_setting('company-name', 'fk_subsitetheme') ?>
                          <?php else: 
                              print $site_name;
                          endif; ?>
                          </a>
                        
                      <?php else : ?>
                      <blockquote cite="https://www.facebook.com/fk">
                        <a href="https://www.facebook.com/fk">fk Kommune</a>
                      
                      <?php endif; ?>
                        
                      </blockquote>
                    </div>
                </div>
              </div>
     
          <?php endif;?>
          
          <?php if (!theme_get_setting('facebookfeed','fk_subsitetheme')) :?>
        
             <?php if (theme_get_setting('activites','fk_subsitetheme')) :?>
              <div class="activites-block">
                  <?php  print _fk_subsitetheme_block_render('views', 'aktiviteter-block_2'); ?>
              </div>
             <?php endif;?>
          
          <?php endif;?>   
      </div>
      
      <div class="clearfix"></div>
      <?php if (theme_get_setting('large_news','fk_subsitetheme')==3) :?>
      <div class="news-block col-xs-12">
         <?php if (theme_get_setting('newstext','fk_subsitetheme')) :?>
            <h2 class="newstitle block-title"><?php print theme_get_setting('newstext', 'fk_subsitetheme') ?></h2>
        <?php endif;?>
        <?php $view = views_get_view('fk_news_view');
              print $view->render('block_6');
        ?>
      </div>
     <?php endif;?>
      
      <div class="clearfix"></div>
      
      <?php if (theme_get_setting('large_news','fk_subsitetheme')==4) :?>
      <div class="news-block col-xs-12">
        <?php if (theme_get_setting('newstext','fk_subsitetheme')) :?>
            <h2 class="newstitle block-title"><?php print theme_get_setting('newstext', 'fk_subsitetheme') ?></h2>
        <?php endif;?>
        <?php $view = views_get_view('fk_news_view');
        
              print $view->render('block_7');
        ?>
      </div>
     <?php endif;?>
      <?php if (theme_get_setting('latest_news','fk_subsitetheme')== 3) :?>      
      <div class="col-xs-12 latest-news-block with-top-line">
        
        <?php 
         $view = views_get_view('fk_news_view');
      $view->set_display('fk_latest_news_three_col');
      $view->set_offset(theme_get_setting('large_news','fk_subsitetheme'));
      $view->pre_execute();
      $view->execute();
      if (count( $view->result)>0)

      if (theme_get_setting('newstext','fk_subsitetheme')) :      

            print '<h2 class="newstitle block-title">' . theme_get_setting('newstext', 'fk_subsitetheme')  . '</h2>' . $view->render();

        else: 
                  
            print '<h2 class="block-title">' . t($view->get_title()) . '</h2>' . $view->render();
        
        endif;
      
      
        ?>
      </div>
     <?php endif;?>
    </div>
    <div class="clearfix"></div>
    
  </div>

  <!--<div class='front-main-container-shadow'></div> -->
</div>
<!--
<div class="lcontainer-fluid clearfix front-s-news">
  <div class="container front-s-news-inner">
    <div class="row">
      <?php //print $page['front_small_carousel']; ?>
    </div>
  </div>
</div>

<div class='lcontainer-fluid clearfix front-news-bottom'>
  <div class='container'>
    <div class='front-news-bottom-inner'>
      <div>
        <span>&#216;nsker du at se alle nyheder   <a href='/nyheder' class='btn btn-primary'>Klik her</a></span>
      </div>
    </div>
  </div>
</div> 
-->
<?php print render($page['footer']); ?>
