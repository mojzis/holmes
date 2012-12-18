<?php
/**
 * @file page callbacks for holmes
 *
 * @todo
 * - add a form where hook / group selection can be performed
 * - make it into a searchable backbone ...
 * - dont forget to list drupal alters, too
 */

function holmes_list() {
  $hooks = array(
    'views_definitions' => array(
      'views_form_substitutions',
      'views_form_validate',
      'views_form_submit',
      'views_query_alter',
      'views_query_substitutions',
      'views_data',
      'views_data_alter',
      'views_plugins',
      'views_plugins_alter',
    ),
    'views_runtime' => array(
      'views_pre_build',
      'views_post_build',
      'views_pre_execute',
      'views_post_execute',
      'views_pre_render',
      'views_post_render',
      'views_pre_view',
    ),
  );
  foreach ($hooks as $groupname => $hook_group) {
    dpm(holmes_hooks($hook_group),$groupname);
  }
  dpm(module_hook_info());
  //dpm($mods);
  return "that's it. for now.";
}


function holmes_hooks($group) {
  $mods = array();
  foreach ($group as $h) {
    foreach(module_implements($h) as $mod) {
      $mods[$h][] = $mod;
    }
  }
  return $mods;
}
