<?php
/**
 * @file
 * drupalnz_company.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function drupalnz_company_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external|node|company|form';
  $field_group->group_name = 'group_external';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External links',
    'weight' => '7',
    'children' => array(
      0 => 'field_website',
      1 => 'field_links',
      2 => 'field_facebook',
      3 => 'field_linkedin',
      4 => 'field_twitter',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_external|node|company|form'] = $field_group;

  return $export;
}
