/**
 * @file svendborg_top_menu.js
 */

(function($) {
  Drupal.behaviors.top_menu = {
    attach: function(context) {
      $('.primary_nav_top').hide();
      var menu_link = $(".header_main_menu .nav_main_menu li.main_menu_li.expanded");
      if ($(window).width() > 767) {
        var menu_location = Drupal.settings.menu_location;
        if (menu_location) {
          menu_link.hover(function(){

            $(this).find('ul.dropdown-menu').removeClass('dropdown-menu');
            var data = $(this).find('ul.dropdown-me').html();

            if ($(this).hasClass('open')) {
              $('.primary_nav_top').hide();
            }
            else if (!data) {
              $('.primary_nav_top').hide();
            }
            else {
              $('.primary_nav_top').show();
            }

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
  }

})(jQuery);
