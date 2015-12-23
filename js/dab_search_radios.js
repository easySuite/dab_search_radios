(function ($) {
  'use strict';
  /**
   * Handle the submit of a search block. If the chosen type of search has a
   * redirect URL, redirect the user to it.
   */
  Drupal.behaviors.dab_search_radios_form_submit = {
    attach: function (context, settings) {

      /**
       * Handler function to take care of the redirect. This is used in
       * multiple events.
       */
      var event_handler = function(e) {
        if (e.type === 'keydown' && e.which !== 13) {
          return true;
        }

        var chosen_search = $('#edit-dab-search-radios input[name=dab_search_radios]:checked').val(),
            query = $('#search-block-form input[type="text"]').val(),
            url = '/search/node/' + query;
        if (query == '') {
          return false;
        }
        if (chosen_search !== 'local') {
          var tab = 'tab=' + settings.dab_search_radios[chosen_search];
          query = 'vl(freeText0)=' + query;
          url = settings.dab_search_radios.url;
          url = [url, tab, query].join('&');
        }
        window.location = url;
        return false;
      };

      // Add the event handler to some events.
      $('#search-block-form input[type="submit"]').click(event_handler);
      $('#search-block-form input[name="search_block_form"]').keydown(event_handler);
    }
  };
})(jQuery);
