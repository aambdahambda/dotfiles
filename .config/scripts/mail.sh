#!/bin/sh

MB=~/.mail/aambdahambda@ya.ru
TMP=/tmp/mail

ensure_paths_exist()
{
	for path in ${MB} ${TMP}; do 
		test -e ${path} || mkdir -p ${path}
	done
}

sync_mb()
{
	mbsync -a -q
	notmuch new > /dev/null 2>&1
}

check_mb()
{
	new=$(notmuch count tag:unread)
	if test ${new} -gt 0; then
		echo " [@${new}]" > ${TMP}
	else
		echo > ${TMP}
	fi
}

main()
{
	ensure_paths_exist

	while :; do 
		sync_mb; check_mb; sleep 60
	done
}

main
