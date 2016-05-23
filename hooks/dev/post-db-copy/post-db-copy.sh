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
    drush @$site.$target_env pm-enable devel_themer -y
    drush @$site.$target_env pm-enable devel_generate -y
    drush @$site.$target_env pm-enable devel -y
    drush @$site.$target_env pm-enable admin_devel -y
    drush @$site.$target_env pm-enable field_ui -y
    drush @$site.$target_env pm-enable rules_admin -y
    drush @$site.$target_env pm-enable views_ui -y
    drush @$site.$target_env pm-enable dblog -y
    drush @$site.$target_env pm-enable feeds -y
    drush @$site.$target_env pm-enable masquerade -y
    drush @$site.$target_env pm-enable statistics -y
    drush @$site.$target_env pm-enable reroute_email -y
    drush @$site.$target_env pm-enable stage_file_proxy -y
#Disable production modules
    drush @$site.$target_env pm-disable syslog -y
    drush @$site.$target_env pm-disable seckit -y
    drush @$site.$target_env pm-disable securepages -y
    drush @$site.$target_env pm-disable username_enumeration_prevention -y
    drush @$site.$target_env pm-disable honeypot -y
#Uninstall production modules
    drush @$site.$target_env pm-uninstall syslog -y
    drush @$site.$target_env pm-uninstall seckit -y
    drush @$site.$target_env pm-uninstall securepages -y
    drush @$site.$target_env pm-uninstall username_enumeration_prevention -y
    drush @$site.$target_env pm-uninstall honeypot -y

