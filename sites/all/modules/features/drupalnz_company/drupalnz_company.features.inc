<?php
/**
 * @file
 * drupalnz_company.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalnz_company_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function drupalnz_company_node_info() {
  $items = array(
    'company' => array(
      'name' => t('Company'),
      'base' => 'node_content',
      'description' => t('A company that will be listed on the site'),
      'has_title' => '1',
      'title_label' => t('Company name'),
      'help' => '',
    ),
  );
  return $items;
}
