<?php

function holmes_fields() {
  
  $f = field_info_fields();
  drupal_add_http_header('Access-Control-Allow-Origin','*');
  drupal_json_output($f);
}

function holmes_ents() {
  // attention, this could be dangerous
  // http://benbuckman.net/tech/12/04/cracking-cross-domainallow-origin-nut
  drupal_add_http_header('Access-Control-Allow-Origin','*');
  //drupal_add_http_header('Access-Control-Allow-Methods','http://qw');

  switch($_SERVER['REQUEST_METHOD']) {
    case 'OPTIONS':
      drupal_add_http_header('Access-Control-Allow-Methods',"'OPTIONS, GET'");
      drupal_add_http_header('Access-Control-Allow-Headers',"'Content-Type, X-Requested-With, X-PINGOTHER'");
      drupal_add_http_header('Access-Control-Max-Age', 86400);
      //drupal_add_http_header('Public','OPTIONS, GET');
      drupal_json_output(true);
    break;
    case 'GET':
      $e = entity_get_info();
      drupal_json_output($e);
    break;
  }
}
