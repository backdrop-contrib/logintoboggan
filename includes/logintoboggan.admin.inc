<?php

/**
 * @file
 *  Administration functions for LoginToboggan module.
 */

function logintoboggan_main_settings() {
  $config = config('logintoboggan.settings');
  $system_config = config('system.core');

  $_disabled = t('Disabled');
  $_enabled = t('Enabled');

  $form['login'] = array(
    '#type' => 'fieldset',
    '#title' => t('Log in'),
  );

  $form['login']['logintoboggan_login_with_email'] = array(
    '#type' => 'radios',
    '#title' => t('Allow users to login using their e-mail address'),
    '#default_value' => $config->get('login_with_email'),
    '#options' => array($_disabled, $_enabled),
    '#description' => t('Users will be able to enter EITHER their username OR their e-mail address to log in.'),
  );

  $form['login']['logintoboggan_unified_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Present a unified login/registration page'),
    '#default_value' => $config->get('unified_login'),
    '#description' => t("Use one page for both login and registration instead of Backdrop's tabbed login/registration/password pages."),
  );

  $form['registration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration'),
  );

  $form['registration']['logintoboggan_confirm_email_at_registration'] = array(
    '#type' => 'radios',
    '#title' => t('Use two e-mail fields on registration form'),
    '#default_value' => $config->get('confirm_email_at_registration'),
    '#options' => array($_disabled, $_enabled),
    '#description' => t('User will have to type the same e-mail address into both fields. This helps to confirm that they\'ve typed the correct address.'),
  );

  $form['registration']['logintoboggan_user_email_verification'] = array(
    '#type' => 'checkbox',
    '#title' => t('Set password'),
    '#default_value' => !$system_config->get('user_email_verification') ? 1 : 0,
    '#description' => t("This will allow users to choose their initial password when registering (note that this setting is a mirror of the <a href=\"!settings\">Require e-mail verification when a visitor creates an account</a> setting, and is merely here for convenience). If selected, users will be assigned to the role below. They will not be assigned to the 'authenticated user' role until they confirm their e-mail address by following the link in their registration e-mail. It is HIGHLY recommended that you set up a 'pre-authorized' role with limited permissions for this purpose. <br />NOTE: If you enable this feature, you should edit the <a href=\"!settings\">Welcome (no approval required)</a> text.", array('!settings' => url('admin/config/people/settings'))),
  );

  // Grab the roles that can be used for pre-auth. Remove the anon role, as it's not a valid choice.
  $roles = user_roles(TRUE);

  $form ['registration']['logintoboggan_pre_auth_role'] = array(
    '#type' => 'select',
    '#title' => t('Non-authenticated role'),
    '#options' => $roles,
    '#default_value' => $config->get('pre_auth_role'),
    '#description' => t('If "Set password" is selected, users will be able to login before their e-mail address has been authenticated. Therefore, you must choose a role for new non-authenticated users -- you may wish to <a href="!url">add a new role</a> for this purpose. Users will be removed from this role and assigned to the "authenticated user" role once they follow the link in their welcome e-mail. <strong>WARNING: changing this setting after initial site setup can cause undesirable results, including unintended deletion of users -- change with extreme caution!</strong>', array('!url' => url('admin/config/people/roles'))),
  );

  $purge_options = array(
    0 => t('Never delete'),
    86400 => t('1 Day'),
    172800 => t('2 Days'),
    259200 => t('3 Days'),
    345600 => t('4 Days'),
    432000 => t('5 Days'),
    518400 => t('6 Days'),
    604800 => t('1 Week'),
    1209600 => t('2 Weeks'),
    2592000 => t('1 Month'),
    7776000 => t('3 Months'),
    15379200 => t('6 Months'),
    30758400 => t('1 Year'),
  );

  $form['registration']['logintoboggan_purge_unvalidated_user_interval'] = array(
    '#type' => 'select',
    '#title' => t('Delete unvalidated users after'),
    '#options' => $purge_options,
    '#default_value' => $config->get('purge_unvalidated_user_interval'),
    '#description' => t("If enabled, users that are still in the 'Non-authenticated role' set above will be deleted automatically from the system, if the set time interval since their initial account creation has passed. This can be used to automatically purge spambot registrations. Note: this requires cron, and also requires that the 'Set password' option above is enabled. <strong>WARNING: changing this setting after initial site setup can cause undesirable results, including unintended deletion of users -- change with extreme caution! (please read the CAVEATS section of INSTALL.txt for important information on configuring this feature)</strong>")
  );

  $form['registration']['logintoboggan_immediate_login_on_register'] = array(
    '#type' => 'checkbox',
    '#title' => t('Immediate login'),
    '#default_value' => $config->get('immediate_login_on_register'),
    '#description' => t("If set, the user will be logged in immediately after registering. Note this only applies if the 'Set password' option above is enabled."),
  );

  $form['registration']['redirect'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirections'),
    '#collapsible' => true,
    '#collapsed' => false,
  );

  $form['registration']['redirect']['logintoboggan_redirect_on_register'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path on registration'),
    '#default_value' => $config->get('redirect_on_register'),
    '#description' => t('Normally, after a user registers a new account, they will be taken to the front page, or to their user page if you specify <cite>Immediate login</cite> above. Leave this setting blank if you wish to keep the default behavior. If you wish the user to go to a page of your choosing, then enter the path for it here. For instance, you may redirect them to a static page such as <cite>node/35</cite>, or to the <cite>&lt;front&gt;</cite> page. You may also use <em>%uid</em> as a variable, and the user\'s user ID will be substituted in the path.'),
  );

  $form['registration']['redirect']['logintoboggan_redirect_on_confirm'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path on confirmation'),
    '#default_value' => $config->get('redirect_on_confirm'),
    '#description' => t('Normally, after a user confirms their new account, they will be taken to their user page. Leave this setting blank if you wish to keep the default behavior. If you wish the user to go to a page of your choosing, then enter the path for it here. For instance, you may redirect them to a static page such as <cite>node/35</cite>, or to the <cite>&lt;front&gt;</cite> page. You may also use <em>%uid</em> as a variable, and the user\'s user ID will be substituted in the path. In the case where users are not creating their own passwords, it is suggested to use <cite>user/%uid/edit</cite> here, so the user may set their password immediately after validating their account.'),
  );
  $form['registration']['redirect']['logintoboggan_override_destination_parameter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override destination parameter'),
    '#default_value' => $config->get('override_destination_parameter'),
    '#description' => t("Normally, when a Backdrop redirect is performed, priority is given to the 'destination' parameter from the originating URL. With this setting enabled, LoginToboggan will attempt to override this behavior with any values set above."),
  );

  $form['other'] = array('#type' => 'fieldset',
    '#title' => t('Other'),
    '#tree' => FALSE,
  );

  $site403 = $system_config->get('site_403');
  if ($site403 == '') {
    $disabled = $default = '0';
  }
  elseif ($site403 == 'toboggan/denied') {
    $disabled = '0';
    $default = 'toboggan/denied';
  }
  else {
    $disabled = $default = $site403;
  }
  $options = array($disabled => $_disabled, 'toboggan/denied' => $_enabled);

  $form['other']['logintoboggan_site_403'] = array(
    '#type' => 'radios',
    '#title' => t('Present login form on access denied (403)'),
    '#options' => $options,
    '#default_value' => $default,
    '#description' => t('Anonymous users will be presented with a login form along with an access denied message.')
  );
  $form['other']['logintoboggan_login_successful_message'] = array(
    '#type' => 'radios',
    '#title' => t('Display login successful message'),
    '#options' => array($_disabled, $_enabled),
    '#default_value' => $config->get('login_successful_message'),
    '#description' => t('If enabled, users will receive a \'Log in successful\' message upon login.')
  );
  $min_pass_options = array(t('None'));
  for ($i = 2; $i < 30; $i++) {
    $min_pass_options[$i] = $i;
  }
  $form['other']['logintoboggan_minimum_password_length'] = array(
    '#type' => 'select',
    '#title' => t('Minimum password length'),
    '#options' => $min_pass_options,
    '#default_value' => $config->get('minimum_password_length'),
    '#description' => t('LoginToboggan automatically performs basic password validation for illegal characters. If you would additionally like to have a minimum password length requirement, select the length here, or set to \'None\' for no password length validation.')
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save configuration'),
  );

  return $form;
}

/**
 * Takes custom settings on the main settings page, transforms them into the
 * appropriate core setting, and cleans up the custom values.
 */
function logintoboggan_main_settings_submit($form, &$form_state) {
  $config = config('logintoboggan.settings');
  $system_config = config('system.core');
  $values = $form_state['values'];

  // System config.
  $user_email_verification = $values['logintoboggan_user_email_verification'] ? FALSE : TRUE;
  $system_config->set('user_email_verification', $user_email_verification);
  $site_403 = $values['logintoboggan_site_403'] == '0' ? '' : $values['logintoboggan_site_403'];
  $system_config->set('site_403', $site_403);
  $system_config->save();

  // Logintoboggan config.
  $config->set('confirm_email_at_registration', $values['logintoboggan_confirm_email_at_registration']);
  $config->set('immediate_login_on_register', $values['logintoboggan_immediate_login_on_register']);
  $config->set('login_successful_message', $values['logintoboggan_login_successful_message']);
  $config->set('login_with_email', $values['logintoboggan_login_with_email']);
  $config->set('minimum_password_length', $values['logintoboggan_minimum_password_length']);
  $config->set('pre_auth_role', $values['logintoboggan_pre_auth_role']);
  $config->set('purge_unvalidated_user_interval', $values['logintoboggan_purge_unvalidated_user_interval']);
  $config->set('redirect_on_confirm', $values['logintoboggan_redirect_on_confirm']);
  $config->set('redirect_on_register', $values['logintoboggan_redirect_on_register']);
  $config->set('override_destination_parameter', $values['logintoboggan_override_destination_parameter']);
  $config->set('unified_login', $values['logintoboggan_unified_login']);
  $config->save();

  // If the unified login setting has been changed, we need to rebuild the
  // menu cache.
  if ($form['login']['logintoboggan_unified_login']['#default_value'] != $form['login']['logintoboggan_unified_login']['#value']) {
    backdrop_set_message(t('Unified login setting was changed, menus have been rebuilt.'));
    // For some reason, a regular menu_rebuild() still leaves the old callbacks
    // cached -- doing it in a shutdown function seems to correct that issue.
    backdrop_register_shutdown_function('menu_rebuild');
  }
}
