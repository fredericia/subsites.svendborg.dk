#!/bin/bash
set -o errexit
set -o nounset

DEBUG=true

SCRIPTDIR="$(dirname "$0")"
if [ -f "$SCRIPTDIR"/config.sh ]; then
  source "$SCRIPTDIR"/config.sh
else
  echo "ERROR: please create a config.sh file"
  exit 10
fi

if [ -f "$SCRIPTDIR"/functions.sh ]; then
  source "$SCRIPTDIR"/functions.sh
else
  echo "ERROR: functions.sh missing"
  exit 10
fi

if [ $# -ne 2 ]; then
  echo "ERROR: Usage: $0 <sitename> <email>"
  exit 10
fi

SITENAME=$(echo "$1" | tr -d ' ')
USEREMAIL=$(echo "$2" | tr -d ' ')
DBNAME=${SITENAME//\./_}
DBNAME=${DBNAME//\-/_}
VHOST="/etc/apache2/sites-available/$SITENAME"

# only allow root to run this script - because of special sudo rights and permissions
if [[ "$USER" != "root" ]]; then
  echo "ERROR: Run with sudo or as root"
  exit 10
fi

validate_sitename "$SITENAME"
validate_email "$USEREMAIL"
check_existence_create "$SITENAME"
create_db "$DBNAME"
create_dirs
create_vhost
add_to_hosts "$SITENAME"
install_drupal
add_to_crontab
add_subsiteadmin
set_permissions
#mail_status "$SITENAME" "mmh@bellcom.dk"

#
# FROM PUPPET. DONT EDIT
# Try to set correct permissions for files
#

PWD=`pwd`
PATHARRAY=( `echo ${PWD} | tr '/' ' '`)

if [[ ${PATHARRAY[1]} != 'www'  ]]; then
  exit 10
fi

chgrp --preserve-root -R www-data "$PWD"
chmod --preserve-root -R ug+rwX "$PWD"
chmod --preserve-root -R o-w "$PWD"
find "$PWD" -type d -exec chmod g+s '{}' \;

# Set correct permissions for Drupal
if [ -d $PWD"/public_html/sites/default" ]; then
  chmod --preserve-root a-w $PWD"/public_html/sites/default"
fi
if [ -d $PWD"/sites/default" ]; then
  chmod --preserve-root a-w $PWD"/sites/default"
fi
if [ -f $PWD"/public_html/sites/default/settings.php" ]; then
  chmod --preserve-root a-w $PWD"/public_html/sites/default/settings.php"
fi
if [ -f $PWD"/sites/default/settings.php" ]; then
  chmod --preserve-root a-w $PWD"/sites/default/settings.php"
fi

