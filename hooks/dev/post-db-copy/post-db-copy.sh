#!/bin/sh
#
# Cloud Hook: post-db-copy
#
# The post-db-copy hook is run whenever you use the Workflow page to copy a
# database from one environment to another. See ../README.md for
# details.
#
# Usage: post-db-copy site target-env db-name source-env

site="$1"
target_env="$2"
db_name="$3"
source_env="$4"

echo "$site.$target_env: Received copy of database $db_name from $source_env."
#Enable none production modules
    drush @$site.$target_env en examples
    drush @$site.$target_env en devel_themer
    drush @$site.$target_env en devel_generate
    drush @$site.$target_env en devel
    drush @$site.$target_env en admin_devel
    drush @$site.$target_env en field_ui
    drush @$site.$target_env en rules_admin
    drush @$site.$target_env en views_ui
    drush @$site.$target_env en dblog
    drush @$site.$target_env en feeds
    drush @$site.$target_env en masquerade
    drush @$site.$target_env en statistics
    drush @$site.$target_env en reroute_email
    drush @$site.$target_env en stage_file_proxy
    
#Disable production modules
    drush @$site.$target_env dis syslog
    drush @$site.$target_env dis seckit
    drush @$site.$target_env dis securepages
    drush @$site.$target_env dis username_enumeration_prevention
    drush @$site.$target_env dis honeypot
#Uninstall production modules
    drush @$site.$target_env pmu syslog
    drush @$site.$target_env pmu seckit
    drush @$site.$target_env pmu securepages
    drush @$site.$target_env pmu username_enumeration_prevention
    drush @$site.$target_env pmu honeypot

