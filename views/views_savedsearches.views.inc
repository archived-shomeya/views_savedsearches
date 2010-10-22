<?php

/**
 * @file
 * Provide views data and handlers for views_savedsearches.module.
 */

/**
 * Implementation of hook_views_data().
 *
 * Exposes all fields to the views system.
 */
function views_savedsearches_views_data() {
  $data = array();

  $data['views_savedsearches']['table']['group']  = t('Views Saved Searches');

  $data['views_savedsearches']['table']['base'] = array(
    'field' => 'sid',
    'title' => t('Views saved searches'),
    'help' => t('Saved searches associated with users and/or views.')
  );

  $data['views_savedsearches']['sid'] = array(
    'title' => t('Sid'),
    'help' => t('The ID of the saved search.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_savedsearches']['view_name'] = array(
    'title' => t('View name'),
    'help' => t('The name of the view in the saved search.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'title',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_savedsearches']['display'] = array(
    'title' => t('Display'),
    'help' => t('The name of the views display in the saved search.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'title',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_savedsearches']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the saved search.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'title',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_savedsearches']['public'] = array(
    'title' => t('Public'),
    'help' => t('Whether or not the saved search is public.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Public'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_savedsearches']['filters'] = array(
    'title' => t('Link'),
    'help' => t('Link to the view with the saved search.'),
    'field' => array(
      'handler' => 'views_savedsearches_handler_field_link',
      'click sortable' => TRUE,
    ),
  );

  return $data;
}

function views_savedsearches_views_data_alter(&$data) {
  $data['users']['table']['join'] = array(
    'views_savedsearches' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'type' => 'INNER',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function views_savedsearches_views_handlers() {;
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_savedsearches') .'/views/handlers',
    ),
    'handlers' => array(
      'views_savedsearches_handler_field_link' => array(
        'parent' => 'views_handler_field_url',
      ),
    ),
  );
}
