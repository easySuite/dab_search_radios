<?php
/**
 * @file
 * Administration page for DAB search.
 */

/**
 * Define admin form for the DAB search.
 */
function dab_search_radios_settings() {
  $form = array();
  $form['dab_search_radios_settings_search'] = array(
    '#type' => 'fieldset',
    '#title' => t('DAB Searches'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['dab_search_radios_settings_search']['dab_search_radios_settings_search_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Search url'),
    '#default_value' => variable_get('dab_search_radios_settings_search_url', 'http://minibib.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do'),
    '#description' => t('Enter the URL where to provide search E.g. http://minibib.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do'),
  );
  $form['dab_search_radios_search_tabs'] = array(
    '#type' => 'fieldset',
    '#title' => t('DAB Search tabs'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['dab_search_radios_search_tabs']['dab_search_radios_settings_library_catalogue'] = array(
    '#type' => 'textfield',
    '#title' => t('Library catalogue tab.'),
    '#default_value' => variable_get('dab_search_radios_settings_library_catalogue', 'default_tab'),
    '#description' => t('Which tab to use for library catalogue search'),
  );
  $form['dab_search_radios_search_tabs']['dab_search_radios_settings_international_articles'] = array(
    '#type' => 'textfield',
    '#title' => t('Search url'),
    '#default_value' => variable_get('dab_search_radios_settings_international_articles', 'primo_central'),
    '#description' => t('Which tab to use for international articles search.'),
  );

  return system_settings_form($form);
}
