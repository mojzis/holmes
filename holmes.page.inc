<?php
/**
 * @file page callbacks for holmes
 *
 * @todo
 * - add a form where hook / group selection can be performed
 * - make it into a searchable backbone ...
 * - dont forget to list drupal alters, too
 * - why doesnt hook_info show it all ? (ie views)
 * - add a posibility to filter by modules directory / group ...
 * - check what devel has ?!
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
  $hi = module_hook_info();
  foreach ($hi as $hookname => $hook) {
    $higroups[$hook['group']][] = $hookname;
  }
  ksort($higroups);
  dpm($higroups,'some of the hooks defined on this site');
  //dpm($mods);
  return "that's it. for now.";
}


function holmes_hooks($group) {
  $mods = array();
  foreach ($group as $h) {
    foreach(module_implements($h) as $mod) {
      //$mods[$h][] = $mod;
      $mods[$h][$mod] = holmes_func_source($mod.'_'.$h);
    }
  }
  return $mods;
}
