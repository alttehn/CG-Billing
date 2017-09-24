<?php
/**
 * @file
 * Admin page callbacks for the Node.js module.
 */

/**
 * Form builder function for module settings.
 */
function nodejs_settings() {
  $form['server'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node.js server'),
  );
  $form['server']['nodejs_server_scheme'] = array(
    '#type' => 'radios',
    '#title' => t('Protocol used by Node.js server'),
    '#default_value' => variable_get('nodejs_server_scheme', 'http'),
    '#options' => array('http' => t('http'), 'https' => t('https')),
    '#description' => t('The protocol used to communicate with the Node.js server.'),
  );
  $form['server']['nodejs_server_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Node.js server host'),
    '#default_value' => variable_get('nodejs_server_host', 'localhost'),
    '#size' => 40,
    '#required' => TRUE,
    '#description' => t('The hostname of the Node.js server.'),
  );
  $form['server']['nodejs_server_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Node.js server port'),
    '#default_value' => variable_get('nodejs_server_port', '8080'),
    '#size' => 10,
    '#required' => TRUE,
    '#description' => t('The port of the Node.js server.'),
  );
  $description = t("Enter one page per line as Drupal paths. The '*' character is a wildcard.
                    Example paths are %blog for the blog page and %blog-wildcard for every personal blog.
                    %front is the front page.",
                    array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));

  $form['server']['nodejs_pages_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pages on which to enable nodejs'),
   );

  $form['server']['nodejs_pages_config']['nodejs_disabled_pages'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('nodejs_disabled_pages', 1),
    '#options' => array(
      0 => t('All pages except those listed'),
      1 => t('Only the listed pages'),
    ),
  );

  $form['server']['nodejs_pages_config']['nodejs_pages'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('nodejs_pages', '*'),
    '#description' => $description,
   );

  $form['server']['nodejs_service_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Node.js service key'),
    '#default_value' => variable_get('nodejs_service_key', ''),
    '#size' => 40,
    '#description' => t('An arbitrary string used as a secret between the Node.js server and the Drupal site. Be sure to enter the same service key in the Node.js app configuration file.'),
  );

  $form['client'] = array(
    '#type' => 'fieldset',
    '#title' => t('Socket.io client'),
  );

  $form['client']['nodejs_socket_io_type'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('nodejs_socket_io_type', 'internal'),
    '#options' => array(
      'internal' => t('Internal'),
      'external' => t('External'),
    ),
    '#description' => t('<b>Internal</b> - use socket.io client packaged with socket.io server. <b>External</b> - use minified socket.io from CDN.'),
  );

  $form['client']['nodejs_socket_io_path'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for external socket.io client'),
    '#default_value' => variable_get('nodejs_socket_io_path', ''),
    '#size' => 80,
    '#description' => t('Version of socket.io client must be same version as socket.io server.'),
    '#states' => array(
      'visible' => array(
        ':input[name=nodejs_socket_io_type]' => array('value' => 'external'),
      ),
      'required' => array(
         ':input[name=nodejs_socket_io_type]' =>  array('value' => 'external'),
      ),
    ),
  );

  return system_settings_form($form);
}

