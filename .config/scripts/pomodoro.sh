#!/bin/sh

TMP=/tmp/pomodoro

ensure_tmp_exists()
{
	test -e ${TMP} || touch ${TMP}
}

clean_tmp()
{
	echo > ${TMP}
}

timer()
{
	time=$1

	while [ ${time} -ne 0 ]; do
		sleep 1

		locked_screen=$(pgrep slock)
		test -z ${locked_screen} || continue

		min=$((time/60))
		sec=$((time%60))

		test ${min} -ne 0 || min=00
		test ${sec} -gt 9 || sec=0${sec}

		echo "[POM ${min}:${sec}]" > ${TMP}
		time=$((time-1))
	done

	clean_tmp

	slock -m "Pomodoro session has been done!"
}

main()
{
	ensure_tmp_exists

	timer $(($1*60))
}

main $1
