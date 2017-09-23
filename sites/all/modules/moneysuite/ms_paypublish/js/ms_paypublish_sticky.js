(function ($) {
  $(document).ready(function() {
    $('.ms_paypublish_payment_plans .form-item').click(function(){
      var item = $(this).find('.ms_paypublish_plan_item');
      // Show the sticky offer
      if(item.hasClass('ms_paypublish_offer_sticky'))
      {
        $('.form-item-make-sticky .ms_paypublish_make_sticky_text').html(item.children('.ms_paypublish_sticky_text').html());
        item.append($('.form-item-make-sticky').remove());
        $('.form-item-make-sticky').show();
      }
      else
      {
        $('.form-item-make-sticky').hide();
      }
      // Show the promote offer
      if(item.hasClass('ms_paypublish_offer_promote'))
      {
        $('.form-item-make-promote .ms_paypublish_make_promote_text').html(item.children('.ms_paypublish_promote_text').html());
        item.append($('.form-item-make-promote').remove());
        $('.form-item-make-promote').show();
      }
      else
      {
        $('.form-item-make-promote').hide();
      }
    });
    $('.ms_paypublish_payment_plans .form-radio').each(function(index){
      if ($(this).attr('checked')) {
      $(this).parents('.form-item').click();
      }
    });
  });
})(jQuery);
