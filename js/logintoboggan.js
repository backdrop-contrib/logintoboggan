
(function ($) {
  Backdrop.behaviors.LoginToboggan = {
    attach: function (context, settings) {
      $('#toboggan-login', context).once('toggleboggan_setup', function () {
        $(this).hide();
        Backdrop.logintoboggan_toggleboggan();
      });
    }
  };

  Backdrop.logintoboggan_toggleboggan = function() {
    $("#toboggan-login-link").click(
      function () {
        $("#toboggan-login").slideToggle("fast");
        this.blur();
        return false;
      }
    );
  };
})(jQuery);

