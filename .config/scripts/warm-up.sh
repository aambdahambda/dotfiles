#!/bin/sh

TIME=900
TMP=/tmp/warm_up

ensure_path_exists() 
{
	test -e ${TMP} || touch ${TMP}
}

timer()
{
	time=${1}
	
	while test $time -gt 0; do
		min=$((time/60))
		sec=$((time%60))

		test ${min} -ne 0 || min=00
		test ${sec} -gt 9 || sec=0${sec}

		echo " [WU ${min}:${sec}]" > ${TMP}
		time=$((time-1))
		sleep 1 
	done

	slock -m "Do what YOU must do!"
}

main()
{
	ensure_path_exists

	while :; do
		timer $TIME
	done
}

main
