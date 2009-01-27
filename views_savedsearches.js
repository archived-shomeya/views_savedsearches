// $Id$

var ViewsSavedSearches = ViewsSavedSearches || {};

ViewsSavedSearches.baseContext = function() {
  var $baseContext;

  if (undefined === $baseContext) {
    $baseContext = $("div.views-savedsearches-container");
  }
  return $baseContext;
};

ViewsSavedSearches.attachBindings = function(firstTime) {
  var view_name;
  var i;

  for (i = 0; i < Drupal.settings.views_savedsearches.view_names.length; i++) {
    view_name = Drupal.settings.views_savedsearches.view_names[i];

    if (firstTime) {
      // Move the saved searches container below the exposed filters.
      $('div#view-'+ view_name +'-views-savedsearches-container-clear-block', ViewsSavedSearches.baseContext)
      .add('div#view-'+ view_name +'-savedsearches-container')
      .remove()
      .insertAfter('div.view-'+ view_name +' form');
    }

    // Attach the bindings.
    ViewsSavedSearches.bindings(view_name);
  }
}

ViewsSavedSearches.bindings = function(view_name) {
  function ahahDeleteBeforeSubmit(formData, jqForm, options) {
    // Validate checkboxes: at least one must be checked.
    if ($('div#view-'+ view_name +'-savedsearches-container div.views-savedsearches-list-ahah form:first :checkbox[@checked]').length == 0) {
      alert("You must select at least one saved search to be deleted!");
      return false;
    }

    // The form is validated, it will be submitted. Now let's add the form
    // data of the views filters form, to be able to check if we should
    // display the save form.
    formData.push({ name: 'views_filters_form', value: $('form#views-filters').formSerialize() });

    return true;
  }

  function ahahSaveBeforeSubmit(formData, jqForm, options) {
    var $name = $('div#view-'+ view_name +'-savedsearches-container div.views-savedsearches-save-ahah form:first input#edit-name');

    // Validate the name field.
    if ($name.fieldValue()[0].length == 0 || $name.fieldValue()[0].length > 30 ) {
      alert("You must enter a name for this saved search (maximum 30 characters)!");
      return false;
    }

    // The form is validated, it will be submitted. Now let's add the form
    // data of the views filters form, to save it.
    formData.push({ name: 'views_filters_form', value: $('form#views-filters').formSerialize() });

    return true;
  }

  // The target container that will receive the updated filter..
  var container = $('div#view-'+ view_name +'-savedsearches-container').get(0);

  // List (with delete saved search form).
  var deleteOptions = {
    url: Drupal.settings.basePath + Drupal.settings.views_savedsearches.paths.deletePath,
    beforeSubmit: ahahDeleteBeforeSubmit,
    target: container,
    success: function(response, status) {
      Drupal.attachBehaviors(container);
    }
  };

  $('div#view-'+ view_name +'-savedsearches-container div.views-savedsearches-list-ahah form:first', ViewsSavedSearches.baseContext)
  .ajaxForm(deleteOptions);

  // Save search form.
  var saveOptions = {
    url: Drupal.settings.basePath + Drupal.settings.views_savedsearches.paths.savePath,
    beforeSubmit: ahahSaveBeforeSubmit,
    target: container,
    success: function(response, status) {
      Drupal.attachBehaviors(container);
    }
  };
  var saveForm = $('div#view-'+ view_name +'-savedsearches-container div.views-savedsearches-save-ahah form:first', ViewsSavedSearches.baseContext);
  $('div#view-'+ view_name +'-savedsearches-container div.views-savedsearches-save-ahah form:first', ViewsSavedSearches.baseContext)
  .ajaxForm(saveOptions);
}

Drupal.behaviors.viewsSavedSearches = function(context) {
  var firstTime = (context == window.document);
  var obj = ViewsSavedSearches.attachBindings(firstTime);
}
