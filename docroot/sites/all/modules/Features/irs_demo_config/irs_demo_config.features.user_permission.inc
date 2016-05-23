<?php
/**
 * @file
 * irs_demo_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function irs_demo_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create irs_demo_content content'.
  $permissions['create irs_demo_content content'] = array(
    'name' => 'create irs_demo_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any irs_demo_content content'.
  $permissions['delete any irs_demo_content content'] = array(
    'name' => 'delete any irs_demo_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own irs_demo_content content'.
  $permissions['delete own irs_demo_content content'] = array(
    'name' => 'delete own irs_demo_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any irs_demo_content content'.
  $permissions['edit any irs_demo_content content'] = array(
    'name' => 'edit any irs_demo_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own irs_demo_content content'.
  $permissions['edit own irs_demo_content content'] = array(
    'name' => 'edit own irs_demo_content content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
