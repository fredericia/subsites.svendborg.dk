#!/bin/bash
set -o errexit
set -o nounset

DEBUG=true

BASE_DIR="/var/www/subsites.svendborg.dk/"
SERVERIP="192.168.2.56"
MULTISITE="/var/www/subsites.svendborg.dk/public_html"
TMPDIRBASE="/var/www/subsites.svendborg.dk/tmp"
LOGDIRBASE="/var/www/subsites.svendborg.dk/logs"
SESSIONDIRBASE="/var/www/subsites.svendborg.dk/sessions"
DBDIR="/var/lib/mysql"
PROFILE="minimal"
EMAIL="drupal@bellcom.dk"
SCRIPTDIR="$(dirname "$0")"
ADMINPASS=$(cat $SCRIPTDIR/.admin_password.txt)
VHOSTTEMPLATE="/var/www/subsites.svendborg.dk/scripts/vhost-template.txt"
NOW=$(date +"%d/%m/%y %H:%M:%S")

if [ $# -ne 1 ]; then
  echo "ERROR: usage: $0 <sitename>"
  exit 10
fi

SITENAME=$(echo $1 | tr -d ' ')
VHOST="/etc/apache2/sites-available/$SITENAME"
DBNAME=$(echo $SITENAME | sed 's/\./_/g')

function debug {
  if [[ "$DEBUG" == true ]]; then
    echo "DEBUG: $1"
  fi
}

validate_name() {
  debug "Checking site name ($SITENAME)"
# TODO, more checks for speciel chars
  if [[ ! "$SITENAME" =~ svendborg.bellcom.dk$ ]]; then
    echo "ERROR: domain not valid"
    exit 10
  fi
}

#validate_email() {
#  debug "Checking email address ($1)"
#  if [[ "$1" =~ "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$" ]]
#  then
#    echo "Email address $1 is valid."
#  else
#    echo "ERROR: email $1 not valid"
#    exit 10
#  fi
#}

check_existence() {
  debug "Checking if site already exists ($SITENAME)"
  # Check if site dir already exists
  if [ -d $MULTISITE/sites/$SITENAME ]
  then
    echo "ERROR: sitedir, $MULTISITE/sites/$SITENAME already exists"
    exit 10
  fi

  # Check if site vhost alias already exists
  if [ -f $VHOST ]
  then
    echo "ERROR: vhost, $VHOST already exists"
    exit 10
  fi

  # Check if database already exists
  if [ -d $DBDIR/$DBNAME ]
  then
    echo "ERROR: database, $DBDIR/$DBNAME already exists"
    exit 10
  fi
}

create_db() {
  DBNAME=$1
  DBUSER=$(echo $DBNAME | cut -c 1-16)
  debug "Creating database ($DBNAME) and database user ($DBUSER)"
  # check for pwgen
  command -v pwgen >/dev/null 2>&1 || { echo >&2 "ERROR: pwgen is required but not installed. Aborting."; exit 20; }
  DBPASS=$(pwgen -s 10 1)
  # this requires a /root/.my.cnf with password set
  /usr/bin/mysql -u root -e "CREATE DATABASE $DBNAME;"
  /usr/bin/mysql -u root -e "GRANT ALL ON $1.* TO $DBUSER@localhost IDENTIFIED BY \"$DBPASS\"";
}

create_dirs() {
  TMPDIR="$TMPDIRBASE/$SITENAME"
  LOGDIR="$LOGDIRBASE/$SITENAME"
  SESSIONDIR="$SESSIONDIRBASE/$SITENAME"
  mkdir $TMPDIR
  mkdir $LOGDIR
  mkdir $SESSIONDIR
}

create_vhost() {
  debug "Adding and enabling $SITENAME vhost"
  cp $VHOSTTEMPLATE /etc/apache2/sites-available/$SITENAME
  perl -p -i -e "s/\[domain\]/$SITENAME/g" /etc/apache2/sites-available/$SITENAME
  a2ensite $SITENAME >/dev/null
  debug "Reloading Apache2"
  /etc/init.d/apache2 reload >/dev/null
}

add_to_hosts() {
  debug "Adding $SITENAME to /etc/hosts"
  echo "$SERVERIP $SITENAME" >> /etc/hosts
}

install_drupal() {
  debug "Installing drupal ($SITENAME)"
  # Do a drush site install
  /usr/bin/drush -q -y -r $MULTISITE site-install $PROFILE --db-url="mysql://$DBUSER:$DBPASS@localhost/$DBNAME" --sites-subdir=$SITENAME --account-mail=$EMAIL --site-mail=$EMAIL --site-name=$SITENAME --account-pass=$ADMINPASS

  # Set tmp
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAME vset file_temporary_path $TMPDIR

  # Do some drupal setup here. Don't trust the profile?
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAME vset user_register 0
  # TODO, disable update? set error level?, cache?
}

set_permissions() {
  debug "Setting correct permissions"
  /bin/chgrp -R www-data $MULTISITE/sites/$SITENAME
  /bin/chmod -R g+rwX $MULTISITE/sites/$SITENAME
  /bin/chmod g-w $MULTISITE/sites/$SITENAME $MULTISITE/sites/$SITENAME/settings.php
}

add_to_crontab() {
  debug "Adding Drupal cron.php to www-data crontab"
  # if shuf is available, then run cron at random minutes
  if [ -x "/usr/bin/shuf" ]; then
    CRONMINUTE=$(shuf -i 0-59 -n 1)
  else
    CRONMINUTE=0
  fi
  CRONKEY=`/usr/bin/drush -r $MULTISITE --uri=$SITENAME vget cron_key | cut -d \' -f 2`
  CRONLINE="$CRONMINUTE */2 * * * /usr/bin/wget -O - -q -t 1 http://$SITENAME/cron.php?cron_key=$CRONKEY"
  (/usr/bin/crontab -u www-data -l; echo "$CRONLINE") | /usr/bin/crontab -u www-data -
}

mail_status() {
  debug "Sending statusmail ($SITENAME)"
}

# only allow root to run this script - because of special sudo rights and permissions
if [[ "$USER" != "root" ]]; then
  echo "ERROR: Run with sudo or as root"
  exit 10
fi

validate_name
#validate_email "$EMAIL"
check_existence
create_db "$DBNAME"
create_dirs
create_vhost
add_to_hosts
install_drupal "$EMAIL"
set_permissions
add_to_crontab
#mail_status "$SITENAME" "mmh@bellcom.dk"
