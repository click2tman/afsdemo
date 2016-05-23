#!/bin/sh
#
# Cloud Hook: post-code-update
#
# The post-code-update hook runs in response to code commits.
# When you push commits to a Git branch, the post-code-update hooks runs for
# each environment that is currently running that branch. See
# ../README.md for details.
#
# Usage: post-code-update site target-env source-branch deployed-tag repo-url
#                         repo-type

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

if [ "$target_env" != 'prod' ]; then
    echo "$site.$target_env: The $source_branch branch has been updated on $target_env. Clearing the cache."
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
#Revert features in production
    drush @$site.$target_env features-revert irs_demo_config --force -y
#Flush caches in production
    drush @$site.$target_env cc all
else
    echo "$site.$target_env: The $source_branch branch has been updated on $target_env."
fi
