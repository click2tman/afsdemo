<?php
/**
 * @file
 * irs_demo_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function irs_demo_config_default_rules_configuration() {
  $items = array();
  $items['rules_notify_editor_when_content_is_created'] = entity_import('rules_config', '{ "rules_notify_editor_when_content_is_created" : {
      "LABEL" : "Notify Editor When Content is Created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Workflow" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : { "5" : "5", "4" : "4", "6" : "6" } },
            "operation" : "OR"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "blog_entry" : "blog_entry",
                "document" : "document",
                "event" : "event",
                "faqs" : "faqs",
                "irs_demo_content" : "irs_demo_content",
                "idea_site" : "idea_site",
                "media_gallery" : "media_gallery",
                "photo" : "photo",
                "press_release" : "press_release",
                "profile" : "profile",
                "project" : "project",
                "resource" : "resource",
                "services" : "services",
                "site_page" : "site_page",
                "webform" : "webform"
              }
            }
          }
        },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Thank you [node:author] for creating content with ID:[node:nid]. Editors will be notified accordingly." } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "[node:author] created content with ID:[node:nid] at [node:created]",
            "message" : "[node:author] created content with ID:[node:nid] at [node:created]. You can view and edit the content at [node:url]"
          }
        }
      ]
    }
  }');
  $items['rules_notify_publisher_when_content_is_set_to_needs_review'] = entity_import('rules_config', '{ "rules_notify_publisher_when_content_is_set_to_needs_review" : {
      "LABEL" : "Notify Publisher When Content is set to needs review",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Workflow" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : { "5" : "5", "4" : "4", "6" : "6" } },
            "operation" : "OR"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "blog_entry" : "blog_entry",
                "document" : "document",
                "event" : "event",
                "faqs" : "faqs",
                "irs_demo_content" : "irs_demo_content",
                "idea_site" : "idea_site",
                "media_gallery" : "media_gallery",
                "photo" : "photo",
                "press_release" : "press_release",
                "profile" : "profile",
                "project" : "project",
                "resource" : "resource",
                "services" : "services",
                "site_page" : "site_page",
                "webform" : "webform"
              }
            }
          }
        },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Thank you [node:author] for editing content with ID:[node:nid]. Publishers will be notified accordingly." } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "[node:author] created content with ID:[node:nid] at [node:created]",
            "message" : "[node:author] created content with ID:[node:nid] at [node:created]. You can view and edit the content at [node:url]"
          }
        }
      ]
    }
  }');
  return $items;
}
