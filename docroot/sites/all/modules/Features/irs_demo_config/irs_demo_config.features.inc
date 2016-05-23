<?php
/**
 * @file
 * irs_demo_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function irs_demo_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function irs_demo_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function irs_demo_config_node_info() {
  $items = array(
    'irs_demo_content' => array(
      'name' => t('IRS Demo Content'),
      'base' => 'node_content',
      'description' => t('IRS Demo Content'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
