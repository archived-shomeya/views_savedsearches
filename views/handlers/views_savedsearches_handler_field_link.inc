<?php

/**
 * Filter by project type vocabulary.  This filter provides two checkboxes for
 * including top level project type terms and/or child project type terms.
 */
class views_savedsearches_handler_field_link extends views_handler_field_url {
  function render($values) {
    // Load saved search.
    $saved_search = views_savedsearches_load($values->sid);

    // Load associated view.
    $view = views_get_view($saved_search->view_name);
    $view->set_display($saved_search->display);

    $query = _views_savedsearches_filters_to_params($saved_search->filters);

    return l(check_plain($saved_search->name), $view->get_path(), array('query' => $query));
  }
}
