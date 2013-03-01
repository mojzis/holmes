<?php

function holmes_fields() {
  $f = field_info_fields();
  holmes_json_cros($f);
}

function holmes_ents() {
  $e = entity_get_info();
  holmes_json_cros($e);
}

// TODO: installed field types
