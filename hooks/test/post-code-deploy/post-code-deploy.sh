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
    drush @$site.$target_env pm-disable devel_themer -y
    drush @$site.$target_env pm-disable devel_generate -y
    drush @$site.$target_env pm-disable devel -y
    drush @$site.$target_env pm-disable admin_devel -y
    drush @$site.$target_env pm-disable field_ui -y
    drush @$site.$target_env pm-disable rules_admin -y
    drush @$site.$target_env pm-disable views_ui -y
    drush @$site.$target_env pm-disable dblog -y
    drush @$site.$target_env pm-disable feeds -y
    drush @$site.$target_env pm-disable masquerade -y
    drush @$site.$target_env pm-disable statistics -y
    drush @$site.$target_env pm-disable reroute_email -y
    drush @$site.$target_env pm-disable stage_file_proxy -y
   
#Uninstall none production modules
    drush @$site.$target_env pm-uninstall devel_themer -y
    drush @$site.$target_env pm-uninstall devel_generate -y
    drush @$site.$target_env pm-uninstall devel -y
    drush @$site.$target_env pm-uninstall admin_devel -y
    drush @$site.$target_env pm-uninstall field_ui -y
    drush @$site.$target_env pm-uninstall rules_admin -y
    drush @$site.$target_env pm-uninstall views_ui -y
    drush @$site.$target_env pm-uninstall dblog -y
    drush @$site.$target_env pm-uninstall feeds -y
    drush @$site.$target_env pm-uninstall masquerade -y
    drush @$site.$target_env pm-uninstall statistics -y
    drush @$site.$target_env pm-uninstall reroute_email -y
    drush @$site.$target_env pm-uninstall stage_file_proxy -y
#Enable production modules
    drush @$site.$target_env pm-enable honeypot -y
    drush @$site.$target_env pm-enable syslog -y
    drush @$site.$target_env pm-enable seckit -y
    drush @$site.$target_env pm-enable securepages -y
    drush @$site.$target_env pm-enable username_enumeration_prevention -y
    drush @$site.$target_env pm-enable helloirs -y
    drush @$site.$target_env pm-enable irs_demo_config -y
#Revert features in production
    drush @$site.$target_env features-revert irs_demo_config --force -y 
#Flush caches in production
    drush @$site.$target_env cc all

else
    echo "$site.$target_env: Deployed $deployed_tag."
fi
