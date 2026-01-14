#!/bin/sh

detect_word()
{
	xdotool mousemove $X $Y click 1 click 1

	word=$(xclip -o -selection primary)

	test -n ${word} || word=$(xclip -o -selection clipboard)
	test -n ${word} || word="No words were detected."
}

translate_word()
{
	goldendict ${word} &
}

main()
{
	detect_word; translate_word
}

main
