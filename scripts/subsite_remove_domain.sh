#!/bin/bash
set -o errexit
set -o nounset

DEBUG=true

BASEDIR="/var/www/subsites.svendborg.dk"
MULTISITE="$BASEDIR/public_html"
SITESFILE="$MULTISITE/sites/sites.php"

if [ $# -ne 2 ]; then
  echo "ERROR: Usage: $0 <sitename> <domainname>"
  exit 10
fi

SITENAME=$(echo "$1" | tr -d ' ')
REMOVEDOMAIN=$(echo "$2" | tr -d ' ')

VHOST="/etc/apache2/sites-available/$SITENAME"

function debug {
  if [[ "$DEBUG" == true ]]; then
    echo "DEBUG: $1"
  fi
}

validate_name() {
  debug "Checking domain name ($REMOVEDOMAIN)"
  if [[ ! $REMOVEDOMAIN =~ (([a-zA-Z](-?[a-zA-Z0-9])*)\.)*[a-zA-Z](-?[a-zA-Z0-9])+\.[a-zA-Z]{2,}$ ]]; then
    echo "ERROR: Domain not valid"
    exit 10
  fi
}

check_existence() {
  debug "Checking if site exists ($SITENAME)"
  # Check if site dir already exists
  if [ ! -d "$MULTISITE/sites/$SITENAME" ]
  then
    echo "ERROR: Sitedir, $MULTISITE/sites/$SITENAME doesn't exists"
    exit 10
  fi

  # Check if site vhost exists
  if [ ! -f "$VHOST" ]
  then
    echo "ERROR: Vhost, $VHOST doesn't exists"
    exit 10
  fi

  debug "Checking if the domain exists ($REMOVEDOMAIN)"
  # Check if new domain exists
  EXISTSSERVERALIAS=$(egrep -c "ServerAlias $REMOVEDOMAIN" "/etc/apache2/sites-enabled/$SITENAME" || true)
  if [[ "$EXISTSSERVERALIAS" -eq 0 ]]
  then
    echo "ERROR: Vhost, $REMOVEDOMAIN doesn't exists in the vhost for $SITENAME"
    exit 10
  fi
}

remove_from_vhost() {
  debug "Removing $REMOVEDOMAIN from vhost for $SITENAME"
  sed -i "/ServerAlias\ $REMOVEDOMAIN\$/d" "$VHOST"
  debug "Reloading Apache2"
  /etc/init.d/apache2 reload >/dev/null
}

remove_from_hosts() {
  debug "Removing $REMOVEDOMAIN from /etc/hosts"
  sed -i "/\ $REMOVEDOMAIN\$/d" /etc/hosts
}

remove_from_sites() {
  debug "Removing $REMOVEDOMAIN from sites.php"
  sed -i "/'$REMOVEDOMAIN'/d" $SITESFILE
}

mail_status() {
  debug "Sending statusmail ($SITENAME) ($REMOVEDOMAIN)"
}

# only allow root to run this script - because of special sudo rights and permissions
if [[ "$USER" != "root" ]]; then
  echo "ERROR: Run with sudo or as root"
  exit 10
fi

validate_name
check_existence
remove_from_vhost
remove_from_hosts
remove_from_sites
##mail_status "$SITENAME" "mmh@bellcom.dk"
