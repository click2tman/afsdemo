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
    drush @$site.$target_env pm-enable devel_themer
    drush @$site.$target_env pm-enable devel_generate
    drush @$site.$target_env pm-enable devel
    drush @$site.$target_env pm-enable admin_devel
    drush @$site.$target_env pm-enable field_ui
    drush @$site.$target_env pm-enable rules_admin
    drush @$site.$target_env pm-enable views_ui
    drush @$site.$target_env pm-enable dblog
    drush @$site.$target_env pm-enable feeds
    drush @$site.$target_env pm-enable masquerade
    drush @$site.$target_env pm-enable statistics
    drush @$site.$target_env pm-enable reroute_email
    drush @$site.$target_env pm-enable stage_file_proxy
#Disable production modules
    drush @$site.$target_env pm-disable syslog
    drush @$site.$target_env pm-disable seckit
    drush @$site.$target_env pm-disable securepages
    drush @$site.$target_env pm-disable username_enumeration_prevention
    drush @$site.$target_env pm-disable honeypot
#Uninstall production modules
    drush @$site.$target_env pm-uninstall syslog
    drush @$site.$target_env pm-uninstall seckit
    drush @$site.$target_env pm-uninstall securepages
    drush @$site.$target_env pm-uninstall username_enumeration_prevention
    drush @$site.$target_env pm-uninstall honeypot

