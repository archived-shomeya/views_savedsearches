$Id$

Description
-----------
This module allows you to save your current configuration of exposed filters
for later use. This can be especially useful for Views with a lot of exposed
filters.

Whenever a View is changed, all saved searches for that View are deleted, to
prevent corruption.
If the user has JavaScript enabled, the saving and deleting process happens
through AHAH, and the new section is displayed below the exposed filters
section. When JavaScript is disabled, the new section is displayed above the
exposed filters section.


Dependencies
------------
* Views (http://drupal.org/project/views)

Installation
------------
1) Place this module directory in your modules folder (this will usually be
   "sites/all/modules/").

2) Enable the module.

3) Configure which views will have the Saved Searches functionality at
   admin/build/views/tools/saved-searches.


Sponsor
-------
Paul Ektov of http://autobin.ru.


Author
------
Wim Leers

* mail: work@wimleers.com
* website: http://wimleers.com/work

The author can be contacted for paid customizations of this module as well as
Drupal consulting, development and installation.
