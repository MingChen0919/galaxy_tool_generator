<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_configfiles_configfile() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_configfiles_configfile($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_configfiles_configfile', $component, 'tool > configfiles > configfile');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_configfiles_configfile(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'configfile'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Cheetah variable used to reference the path to the file 
      created with this directive.'),
  ];
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('The value will be placed within the XML tag pair.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}