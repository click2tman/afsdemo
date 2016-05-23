#!/bin/sh
#
# Cloud Hook: post-code-deploy
#
# The post-code-deploy hook is run whenever you use the Workflow page to 
# deploy new code to an environment, either via drag-drop or by selecting
# an existing branch or tag from the Code drop-down list. See 
# ../README.md for details.
#
# Usage: post-code-deploy site target-env source-branch deployed-tag repo-url 
#                         repo-type

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$source_branch" != "$deployed_tag" ]; then
    echo "$site.$target_env: Deployed branch $source_branch as $deployed_tag."
#Disable none production modules
    drush @$site.$target_env dis examples
    drush @$site.$target_env dis devel_themer
    drush @$site.$target_env dis devel_generate
    drush @$site.$target_env dis devel
    drush @$site.$target_env dis admin_devel
    drush @$site.$target_env dis field_ui
    drush @$site.$target_env dis rules_admin
    drush @$site.$target_env dis views_ui
    drush @$site.$target_env dis dblog
    drush @$site.$target_env dis feeds
    drush @$site.$target_env dis masquerade
    drush @$site.$target_env dis statistics
#Uninstall none production modules
    drush @$site.$target_env pmu examples
    drush @$site.$target_env pmu devel_themer
    drush @$site.$target_env pmu devel_generate
    drush @$site.$target_env pmu devel
    drush @$site.$target_env pmu admin_devel
    drush @$site.$target_env pmu field_ui
    drush @$site.$target_env pmu rules_admin
    drush @$site.$target_env pmu views_ui
    drush @$site.$target_env pmu dblog
    drush @$site.$target_env pmu feeds
    drush @$site.$target_env pmu masquerade
    drush @$site.$target_env pmu statistics
#Enable production modules
    drush @$site.$target_env en syslog
    drush @$site.$target_env en seckit
    drush @$site.$target_env en securepages
    drush @$site.$target_env en username_enumeration_prevention
    drush @$site.$target_env en helloirs
    drush @$site.$target_env en irs_demo_config
#Revert features in production
    drush @$site.$target_env fr --force -y irs_demo_config
#Flush caches in production
    drush @$site.$target_env cc all

else
    echo "$site.$target_env: Deployed $deployed_tag."
fi
