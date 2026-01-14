#!/bin/sh

mute=$(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}') 
vol=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}')

if test ${mute} = yes; then 
	echo ${vol}[X]; 
else 
	echo ${vol}
fi   

