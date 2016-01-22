/**
 * @file svendborg_top_menu.js
 */

(function($) {
  Drupal.behaviors.top_menu = {
    attach: function(context) {
      $('.primary_nav_top').hide();
      var menu_link = $(".header_main_menu .nav_main_menu li.main_menu_li.expanded");
      if ($(window).width() > 767) {
        menu_link.hover(function(){
          if ($(this).hasClass('open')) {
            $('.primary_nav_top').hide();
          }
          else {
            $('.primary_nav_top').show();
          }
          var data = $(this).find('ul.dropdown-me').html();

          $('#menu_nav_top').html(data);
        },
          function() {
            //$('.primary_nav_top').hide();
        });
        $('.primary_nav_top').hover(function(){
          $(this).show();
        }, function() {
          $('.primary_nav_top').hide();
        });
      }

    }
  }

})(jQuery);
