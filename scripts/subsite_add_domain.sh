#!/bin/bash
set -o errexit
set -o nounset

DEBUG=true

BASEDIR="/var/www/subsites.svendborg.dk/"
SERVERIP="192.168.2.56"
MULTISITE="$BASEDIR/public_html"
SITESFILE="$MULTISITE/sites/sites.php"

if [ $# -ne 2 ]; then
  echo "ERROR: Usage: $0 <sitename> <domainname>"
  exit 10
fi

SITENAME=$(echo "$1" | tr -d ' ')
NEWDOMAIN=$(echo "$2" | tr -d ' ')

VHOST="/etc/apache2/sites-available/$SITENAME"

function debug {
  if [[ "$DEBUG" == true ]]; then
    echo "DEBUG: $1"
  fi
}

validate_name() {
  debug "Checking domain name ($NEWDOMAIN)"
  if [[ ! $NEWDOMAIN =~ (([a-zA-Z](-?[a-zA-Z0-9])*)\.)*[a-zA-Z](-?[a-zA-Z0-9])+\.[a-zA-Z]{2,}$ ]]; then
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

  debug "Checking if the new domain already exists ($NEWDOMAIN)"
  # Check if new domain already exists
  egrep -q "ServerName $NEWDOMAIN" /etc/apache2/sites-enabled/* && EXISTSSERVERNAME=$? || EXISTSSERVERNAME=$?
  egrep -q "ServerAlias $NEWDOMAIN" /etc/apache2/sites-enabled/* && EXISTSSERVERALIAS=$? || EXISTSSERVERALIAS=$?
  if [[ "$EXISTSSERVERALIAS" -eq 0 || $EXISTSSERVERNAME -eq 0 ]]
  then
    echo "ERROR: Domain, $NEWDOMAIN already exists in a vhost"
    exit 10
  fi
}

add_to_vhost() {
  debug "Adding $NEWDOMAIN to vhost for $SITENAME"
  /usr/bin/perl -p -i -e "s/ServerName $SITENAME/ServerName $SITENAME\n    ServerAlias $NEWDOMAIN/g" "$VHOST"
  debug "Reloading Apache2"
  /etc/init.d/apache2 reload >/dev/null
}

add_to_hosts() {
  debug "Adding $NEWDOMAIN to /etc/hosts"
  echo "$SERVERIP $NEWDOMAIN" >> /etc/hosts
}

add_to_sites() {
  debug "Adding $NEWDOMAIN to sites.php"
  echo "\$sites['$NEWDOMAIN'] = '$SITENAME';" >> $SITESFILE
}

mail_status() {
  debug "Sending statusmail ($SITENAME) ($NEWDOMAIN)"
}

# only allow root to run this script - because of special sudo rights and permissions
if [[ "$USER" != "root" ]]; then
  echo "ERROR: Run with sudo or as root"
  exit 10
fi

validate_name
check_existence
add_to_vhost
add_to_hosts
add_to_sites
#mail_status "$SITENAME" "mmh@bellcom.dk"
