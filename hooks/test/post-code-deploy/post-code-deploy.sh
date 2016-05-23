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
    drush @$site.$target_env pm-disable devel_themer
    drush @$site.$target_env pm-disable devel_generate
    drush @$site.$target_env pm-disable devel
    drush @$site.$target_env pm-disable admin_devel
    drush @$site.$target_env pm-disable field_ui
    drush @$site.$target_env pm-disable rules_admin
    drush @$site.$target_env pm-disable views_ui
    drush @$site.$target_env pm-disable dblog
    drush @$site.$target_env pm-disable feeds
    drush @$site.$target_env pm-disable masquerade
    drush @$site.$target_env pm-disable statistics
    drush @$site.$target_env pm-disable reroute_email
    drush @$site.$target_env pm-disable stage_file_proxy
   
#Uninstall none production modules
    drush @$site.$target_env pm-uninstall devel_themer
    drush @$site.$target_env pm-uninstall devel_generate
    drush @$site.$target_env pm-uninstall devel
    drush @$site.$target_env pm-uninstall admin_devel
    drush @$site.$target_env pm-uninstall field_ui
    drush @$site.$target_env pm-uninstall rules_admin
    drush @$site.$target_env pm-uninstall views_ui
    drush @$site.$target_env pm-uninstall dblog
    drush @$site.$target_env pm-uninstall feeds
    drush @$site.$target_env pm-uninstall masquerade
    drush @$site.$target_env pm-uninstall statistics
    drush @$site.$target_env pm-uninstall reroute_email
    drush @$site.$target_env pm-uninstall stage_file_proxy
#Enable production modules
    drush @$site.$target_env pm-enable honeypot
    drush @$site.$target_env pm-enable syslog
    drush @$site.$target_env pm-enable seckit
    drush @$site.$target_env pm-enable securepages
    drush @$site.$target_env pm-enable username_enumeration_prevention
    drush @$site.$target_env pm-enable helloirs
    drush @$site.$target_env pm-enable irs_demo_config
#Revert features in production
    drush @$site.$target_env features-revert irs_demo_config --force -y 
#Flush caches in production
    drush @$site.$target_env cc all

else
    echo "$site.$target_env: Deployed $deployed_tag."
fi
