<?php
/**
 * @file
 * drupalnz_showcase.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalnz_showcase_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function drupalnz_showcase_node_info() {
  $items = array(
    'showcase' => array(
      'name' => t('Showcase'),
      'base' => 'node_content',
      'description' => t('A NZ Drupal powered website'),
      'has_title' => '1',
      'title_label' => t('Site name'),
      'help' => '',
    ),
  );
  return $items;
}
