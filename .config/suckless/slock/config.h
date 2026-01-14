/* user and group to drop privileges to */
static const char *user  = "amir";
static const char *group = "amir";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#ffffea",     /* after initialization */
	[INPUT] =  "white",       /* during input */
	[FAILED] = "firebrick",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* default message */
static const char * message = "";

/* text color */
static const char * text_color = "#333333";

/* text size (must be a valid size) */
static const char * font_name = "lucidasanstypewriter-bold-24";
