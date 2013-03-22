<?php

function holmes_fields() {
  $f = field_info_fields();
  holmes_json_cros($f);
}

function holmes_ents() {
  $e = entity_get_info();
  holmes_json_cros($e);
}

function holmes_img_styles() {
  $is = image_styles();
  holmes_json_cros($is);
}

// TODO: installed field types
