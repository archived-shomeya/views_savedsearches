<?php

/**
 * Display a link to a views saved search.
 */
class views_savedsearches_handler_field_link extends views_handler_field_url {
  function construct() {
    parent::construct();
    $this->additional_fields['display'] = 'display';
    $this->additional_fields['view_name'] = 'view_name';
    $this->additional_fields['name'] = 'name';
    $this->additional_fields['filters'] = 'filters';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Load associated view.
    $view = views_get_view($values->views_savedsearches_view_name);
    $view->set_display($values->views_savedsearches_display);

    $query = _views_savedsearches_filters_to_params(unserialize($values->views_savedsearches_filters));

    return l($values->views_savedsearches_name, $view->get_path(), array('query' => $query));
  }
}
