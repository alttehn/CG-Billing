<?php

/**
 * @file theme.inc
 *
 * Theme functions for the nodejs_chat.module.
 */

/**
 * Displays a list of users with their pictures, or the default one.
 */
function theme_nodejs_chat_users($variables) {
  $users = user_load_multiple($variables['user_ids']);
  $user_pictures_enabled = variable_get('user_pictures', FALSE);
  $user_picture_default = variable_get('user_picture_default', '');

  $output = '<ul>';

  foreach ($users as $user) {
    $output .= '<li class="nodejs-chat-user-box-' . $user->uid . '">';

    if ($user_pictures_enabled) {
      $variables = array(
        'path' => ($user->picture) ? $user->picture->uri : $user_picture_default,
        'height' => '35',
        'width' => '35',
        'alt' => $user->name . "'s avatar.",
      );
      $output .= theme('image', $variables);
    }
    $output .= '<span class="username">' . $user->name . '</span>';
    $output .= '</li>';
  }
  $output .= '</ul>';

  return $output;
}
