(function ($) {
  "use strict";

  Drupal.behaviors.payPublishFields = {
    attach: function (context, settings) {
      ms_paypublish_update_fields();
      $(".ms_paypublish_pid_field input:radio").click(function() {
        ms_paypublish_update_fields();
      });
      function ms_paypublish_update_fields() {
        var pid = $(".ms_paypublish_pid_field input:radio:checked").val();
        // First, unblur all conditional fields
        $('.ms_paypublish_conditional_field').removeClass('ms_paypublish_field_blurred');
        // Get the value of the plan id and apply the blurred class to other fields
        $('.ms_paypublish_field_blur_when_' + pid).addClass('ms_paypublish_field_blurred');
      }
    },
  };
})(jQuery);
