<?php
/**
 * @file
 * irs_demo_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function irs_demo_config_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_draft';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Draft';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Draft';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    7 => '7',
    4 => '4',
    6 => '6',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'log' => 'log',
    'workbench_moderation_history_link' => 'workbench_moderation_history_link',
    'state' => 'state',
    'moderation_actions' => 'moderation_actions',
    'title' => 'title',
    'type' => 'type',
    'name' => 'name',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workbench_moderation_history_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'moderation_actions' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Workbench Moderation: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['exclude'] = TRUE;
  /* Field: Workbench Moderation: Moderation history link */
  $handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
  $handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Moderation state';
  $handler->display->display_options['fields']['state']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['state']['alter']['text'] = '<div>[state]</div><div>[workbench_moderation_history_link]</div>';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Moderation links */
  $handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
  $handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
  $handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Revision by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state_1']['expose']['operator_id'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state_1']['expose']['operator'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['identifier'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/workbench/all-drafts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All drafts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['all_draft'] = array(
    t('Master'),
    t('All Draft'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Node'),
    t('revision user'),
    t('Nid'),
    t('Log message'),
    t('Moderation history link'),
    t('Moderation state'),
    t('<div>[state]</div><div>[workbench_moderation_history_link]</div>'),
    t('Set moderation state'),
    t('Title'),
    t('Type'),
    t('Revision by'),
    t('Last updated'),
    t('State'),
    t('Page'),
  );
  $export['all_draft'] = $view;

  $view = new view();
  $view->name = 'channel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Channel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Channel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_entry' => 'blog_entry',
  );
  /* Filter criterion: Content: Channel (field_channel) */
  $handler->display->display_options['filters']['field_channel_tid']['id'] = 'field_channel_tid';
  $handler->display->display_options['filters']['field_channel_tid']['table'] = 'field_data_field_channel';
  $handler->display->display_options['filters']['field_channel_tid']['field'] = 'field_channel_tid';
  $handler->display->display_options['filters']['field_channel_tid']['value'] = array(
    21 => '21',
  );
  $handler->display->display_options['filters']['field_channel_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_channel_tid']['vocabulary'] = 'channel';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Desktop Channel';
  $translatables['channel'] = array(
    t('Master'),
    t('Channel'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('Desktop Channel'),
  );
  $export['channel'] = $view;

  $view = new view();
  $view->name = 'forms_publications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Forms & Publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Forms & Publications';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_form_and_pub_type',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_document_attachment' => 'field_document_attachment',
    'title' => 'title',
    'field_related_form_and_pub' => 'field_related_form_and_pub',
    'body' => 'body',
    'field_form_and_pub_type' => 'field_form_and_pub_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_document_attachment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_related_form_and_pub' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_form_and_pub_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['summary'] = 'Table Summary';
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Use our Forms & Publications Search to quickly find and download current forms, instructions and publications.  To get started, enter keywords into the box below and click Search.';
  /* No results behavior: Global: Result summary */
  $handler->display->display_options['empty']['result']['id'] = 'result';
  $handler->display->display_options['empty']['result']['table'] = 'views';
  $handler->display->display_options['empty']['result']['field'] = 'result';
  $handler->display->display_options['empty']['result']['empty'] = TRUE;
  /* Relationship: Content: Related Form and Pub (field_related_form_and_pub) */
  $handler->display->display_options['relationships']['field_related_form_and_pub_nid']['id'] = 'field_related_form_and_pub_nid';
  $handler->display->display_options['relationships']['field_related_form_and_pub_nid']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['relationships']['field_related_form_and_pub_nid']['field'] = 'field_related_form_and_pub_nid';
  $handler->display->display_options['relationships']['field_related_form_and_pub_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Related Form and Pub */
  $handler->display->display_options['fields']['field_related_form_and_pub']['id'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['field'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['label'] = '';
  $handler->display->display_options['fields']['field_related_form_and_pub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] 
[field_related_form_and_pub] ';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Form and Publication Type */
  $handler->display->display_options['fields']['field_form_and_pub_type']['id'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['table'] = 'field_data_field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['field'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['label'] = '';
  $handler->display->display_options['fields']['field_form_and_pub_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'irs_demo_content' => 'irs_demo_content',
  );
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    'Current' => 'Current',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );

  /* Display: current Page */
  $handler = $view->new_display('page', 'current Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_document_attachment']['id'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_document_attachment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_attachment']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_document_attachment]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_document_attachment_1']['id'] = 'field_document_attachment_1';
  $handler->display->display_options['fields']['field_document_attachment_1']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment_1']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment_1']['relationship'] = 'field_related_form_and_pub_nid';
  $handler->display->display_options['fields']['field_document_attachment_1']['label'] = '';
  $handler->display->display_options['fields']['field_document_attachment_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_attachment_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_attachment_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_attachment_1']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_attachment_1']['delta_offset'] = '0';
  /* Field: Content: Related Form and Pub */
  $handler->display->display_options['fields']['field_related_form_and_pub']['id'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['field'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['label'] = '';
  $handler->display->display_options['fields']['field_related_form_and_pub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['alter']['text'] = '<a href="[field_document_attachment_1]">[field_related_form_and_pub]</a>';
  $handler->display->display_options['fields']['field_related_form_and_pub']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['type'] = 'node_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]
[field_related_form_and_pub]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Form and Publication Type */
  $handler->display->display_options['fields']['field_form_and_pub_type']['id'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['table'] = 'field_data_field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['field'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['label'] = '';
  $handler->display->display_options['fields']['field_form_and_pub_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'irs_demo_content' => 'irs_demo_content',
  );
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    'Current' => 'Current',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'forms-and-publications/current';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Current';
  $handler->display->display_options['menu']['description'] = 'Current';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Current';
  $handler->display->display_options['tab_options']['description'] = 'Current';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Prior Year Page */
  $handler = $view->new_display('page', 'Prior Year Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Prior Year';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_document_attachment']['id'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_document_attachment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_attachment']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_document_attachment]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Related Form and Pub */
  $handler->display->display_options['fields']['field_related_form_and_pub']['id'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['field'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['label'] = '';
  $handler->display->display_options['fields']['field_related_form_and_pub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]
[field_related_form_and_pub]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Form and Publication Type */
  $handler->display->display_options['fields']['field_form_and_pub_type']['id'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['table'] = 'field_data_field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['field'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['label'] = '';
  $handler->display->display_options['fields']['field_form_and_pub_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'irs_demo_content' => 'irs_demo_content',
  );
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    'Prior Year' => 'Prior Year',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'forms-and-publications/prior-year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Prior Year';
  $handler->display->display_options['menu']['description'] = 'Prior Year';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Prior Year';
  $handler->display->display_options['tab_options']['description'] = 'Prior Year';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Accessible Page */
  $handler = $view->new_display('page', 'Accessible Page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accessible';
  $handler->display->display_options['display_description'] = 'Accessible';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_document_attachment']['id'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_document_attachment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_attachment']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_document_attachment]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Related Form and Pub */
  $handler->display->display_options['fields']['field_related_form_and_pub']['id'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['field'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['label'] = '';
  $handler->display->display_options['fields']['field_related_form_and_pub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]
[field_related_form_and_pub]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Form and Publication Type */
  $handler->display->display_options['fields']['field_form_and_pub_type']['id'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['table'] = 'field_data_field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['field'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['label'] = '';
  $handler->display->display_options['fields']['field_form_and_pub_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'irs_demo_content' => 'irs_demo_content',
  );
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    'Accessible' => 'Accessible',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'forms-and-publications/accessible';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accessible';
  $handler->display->display_options['menu']['description'] = 'Accessible';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Prior Year';
  $handler->display->display_options['tab_options']['description'] = 'Prior Year';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: ebook Page */
  $handler = $view->new_display('page', 'ebook Page', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ebook';
  $handler->display->display_options['display_description'] = 'ebook';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_document_attachment']['id'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['field_document_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_document_attachment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_document_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_attachment']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_document_attachment]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Related Form and Pub */
  $handler->display->display_options['fields']['field_related_form_and_pub']['id'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['table'] = 'field_data_field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['field'] = 'field_related_form_and_pub';
  $handler->display->display_options['fields']['field_related_form_and_pub']['label'] = '';
  $handler->display->display_options['fields']['field_related_form_and_pub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_related_form_and_pub']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]
[field_related_form_and_pub]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Form and Publication Type */
  $handler->display->display_options['fields']['field_form_and_pub_type']['id'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['table'] = 'field_data_field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['field'] = 'field_form_and_pub_type';
  $handler->display->display_options['fields']['field_form_and_pub_type']['label'] = '';
  $handler->display->display_options['fields']['field_form_and_pub_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_form_and_pub_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'irs_demo_content' => 'irs_demo_content',
  );
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_value']['value'] = array(
    'Ebook' => 'Ebook',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'forms-and-publications/ebook';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Ebook';
  $handler->display->display_options['menu']['description'] = 'Ebook';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Prior Year';
  $handler->display->display_options['tab_options']['description'] = 'Prior Year';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['forms_publications'] = array(
    t('Master'),
    t('Forms & Publications'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Use our Forms & Publications Search to quickly find and download current forms, instructions and publications.  To get started, enter keywords into the box below and click Search.'),
    t('Displaying @start - @end of @total'),
    t('field_related_form_and_pub'),
    t('[body] 
[field_related_form_and_pub] '),
    t('current Page'),
    t('<a href="[field_document_attachment_1]">[field_related_form_and_pub]</a>'),
    t('[body]
[field_related_form_and_pub]'),
    t('Prior Year Page'),
    t('Prior Year'),
    t('Accessible Page'),
    t('Accessible'),
    t('ebook Page'),
    t('Ebook'),
    t('ebook'),
  );
  $export['forms_publications'] = $view;

  $view = new view();
  $view->name = 'photo_with_ivy';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo with Ivy';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo with Ivy';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'photo' => 'photo',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['photo_with_ivy'] = array(
    t('Master'),
    t('Photo with Ivy'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['photo_with_ivy'] = $view;

  return $export;
}
