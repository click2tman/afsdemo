<?php

function openpublic_password_apps_app_info() {
  return array(
    'configure form' => 'openpublic_password_app_configure_form', // This form will be render on the app config pag
  );
}

function openpublic_password_app_configure_form() {
  return array(
    'link' => array('#markup' => l('Password policy configuration', 'admin/config/people/password_policy'))
  );
}
