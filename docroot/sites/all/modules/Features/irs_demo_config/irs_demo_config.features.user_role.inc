<?php
/**
 * @file
 * irs_demo_config.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function irs_demo_config_user_default_roles() {
  $roles = array();

  // Exported role: configuration manager.
  $roles['configuration manager'] = array(
    'name' => 'configuration manager',
    'weight' => 5,
  );

  return $roles;
}
