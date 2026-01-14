/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = { "Comic Code-22" };
static const char *prompt  = NULL;      /* -p  option; prompt to the left of input field */

static const char col_black[]               = "#333333";
static const char col_white[]               = "#ffffea";
static const char *colors[SchemeLast][2] = {
	/*                fg         bg       */
	[SchemeNorm] = { col_black, col_white },
	[SchemeSel] = {  col_white, col_black },
	[SchemeOut] = {  col_black, col_white },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 39;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
