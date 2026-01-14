#!/bin/sh

configure_display()
{
	xrandr --output HDMI-0 --mode 1920x1080 --rate 165 &
	feh --bg-fill ~/.config/resources/wallpapers/pale.png &
	redshift -PO 3000 &
	xset s off &
	xset -dpms &
}

configure_keyboard()
{
	setxkbmap -layout us,ru -option 'grp:alt_shift_toggle' &
	clipmenud &
}

configure_status_bar()
{
	~/.config/scripts/warm-up.sh &
	~/.config/scripts/telegram.py &
	~/.config/scripts/mail.sh &

	slstatus &
}

configure_workspace()
{
 	configure_display
 	configure_keyboard
 	configure_status_bar 
}

run_wm()
{
	exec dwm
}

main()
{
	configure_workspace
	
	run_wm
}

main

