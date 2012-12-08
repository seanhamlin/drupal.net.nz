<?php
/**
 * @file
 * drupalnz_plain_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalnz_plain_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function drupalnz_plain_page_node_info() {
  $items = array(
    'plain_page' => array(
      'name' => t('Plain Page'),
      'base' => 'node_content',
      'description' => t('A plain page that can appear in a menu'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
