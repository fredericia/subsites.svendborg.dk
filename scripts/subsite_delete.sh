#!/bin/bash
set -o errexit
set -o nounset

DEBUG=true

BASE_DIR="/var/www/subsites.svendborg.dk/"
SERVERIP="192.168.2.56"
MULTISITE="/var/www/subsites.svendborg.dk/public_html"
SITESFILE="$MULTISITE/sites/sites.php"
TMPDIRBASE="/var/www/subsites.svendborg.dk/tmp"
LOGDIRBASE="/var/www/subsites.svendborg.dk/logs"
SESSIONDIRBASE="/var/www/subsites.svendborg.dk/sessions"
DBDIR="/var/lib/mysql"
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

check_existence() {
  debug "Checking if site exists ($SITENAME)"
  # Check if site dir already exists
  if [ ! -d $MULTISITE/sites/$SITENAME ]
  then
    echo "ERROR: sitedir, $MULTISITE/sites/$SITENAME doesn't exists"
    exit 10
  fi

  # Check if site vhost alias already exists
  if [ ! -f $VHOST ]
  then
    echo "ERROR: vhost, $VHOST doesn't exists"
    exit 10
  fi

  # Check if database already exists
  if [ ! -d $DBDIR/$DBNAME ]
  then
    echo "ERROR: database, $DBDIR/$DBNAME doesn't exists"
    exit 10
  fi
}

delete_vhost() {
  debug "Disabling and deleting $SITENAME vhost"
  a2dissite $SITENAME >/dev/null
  rm -f /etc/apache2/sites-available/$SITENAME
  debug "Reloading Apache2"
  /etc/init.d/apache2 reload >/dev/null
}

delete_db() {
  if [ -z $1 ]; then
    echo "ERROR: delete_db called without an argument"
    exit 10
  fi
  DBNAME=$1
  DBUSER=$(echo $DBNAME | cut -c 1-16)
  debug "Backing up, then deleting database ($DBNAME) and database user ($DBUSER)"
  # backup first, just in case
  /usr/local/sbin/mysql_backup.sh $DBNAME
  /usr/bin/mysql -u root -e "DROP DATABASE $DBNAME;"
  /usr/bin/mysql -u root -e "DROP USER $DBUSER@localhost";
}

delete_dirs() {
  TMPDIR="$TMPDIRBASE/$SITENAME"
  LOGDIR="$LOGDIRBASE/$SITENAME"
  SESSIONDIR="$SESSIONDIRBASE/$SITENAME"
  SITEDIR="$MULTISITE/sites/$SITENAME"
  if [ -d $TMPDIR ]; then
    rm -rf $TMPDIR
  fi
  if [ -d $LOGDIR ]; then
    rm -rf $LOGDIR
  fi
  if [ -d $SESSIONDIR ]; then
    rm -rf $SESSIONDIR
  fi
  if [ -d $SITEDIR ]; then
    rm -rf $SITEDIR
  fi
}

remove_from_hosts() {
# TODO, also remove serveralias lines
  debug "Removing $SITENAME from /etc/hosts"
  sed -i "/$SERVERIP $SITENAME/d" /etc/hosts
}

remove_from_crontab() {
  debug "Removing Drupal cron.php from www-data crontab ($SITENAME)"
  crontab -u www-data -l | sed "/$SITENAME\/cron.php/d" | crontab -u www-data -
}

remove_from_sites() {
  debug "Removing $SITENAME from $SITESFILE"
  sed -i "/$SITENAME/d" $SITESFILE
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
check_existence
delete_vhost
delete_dirs
delete_db "$DBNAME"
remove_from_hosts
remove_from_crontab
remove_from_sites
#mail_status "mmh@bellcom.dk"
