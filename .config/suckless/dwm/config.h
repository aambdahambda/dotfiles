/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* key definitions */
#define MODKEY   Mod4Mask
#define ALT      Mod1Mask
#define CTRL     ControlMask
#define SHIFT    ShiftMask

#define RAISEVOL XF86XK_AudioRaiseVolume
#define LOWERVOL XF86XK_AudioLowerVolume
#define MUTEVOL  XF86XK_AudioMute

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,            KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|CTRL,       KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|SHIFT,      KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|CTRL|SHIFT, KEY, toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* appearance */
static const unsigned int borderpx = 5;		 
static const unsigned int gappx    = 0;
static const unsigned int snap     = 0;			 
static const int showbar           = 1;
static const int topbar            = 1;				
static const char *fonts[]         = { "Comic Code-22" };
static const char col_black[]      = "#333333";
static const char col_white[]      = "#ffffea";
static const char col_gray[]       = "#d3d3d3";
static const char *colors[][3]     = {
	/*               fg         bg         border  */
	[SchemeNorm] = { col_black, col_white, col_gray },
	[SchemeSel]  = { col_black, col_white, col_black },
};

/* tagging */
static const char *tags[] = { "!", "@", "#" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING)  = title
   */
  /* class           instance title   tagsmask isfloating monitor */
  { "GoldenDict-ng", NULL,    NULL,   0,       0          -1 },
};

/* layout(s) */
static const float mfact        = 0.5;
static const int nmaster        = 1; 
static const int resizehints    = 1; 
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
	/* symbol arrange function */
	{ "[]=",  tile },
	{ "><>",  NULL },
	{ "[M]",  monocle },
};

/* commands */
/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0"; 
static const char *dmenucmd[]         = { "dmenu_run", "-m", dmenumon, NULL };
static const char *clipmenucmd[]      = { "clipmenu", "-l", "39", NULL };
static const char* termcmd[]          = { "st", NULL };
static const char* slockcmd[]         = { "slock", NULL };
static const char* zathuracmd[]       = { "zathura", NULL };
static const char* floorpcmd[]        = { "firefox", NULL };
static const char* flameshotcmd[]     = { "flameshot", "gui", NULL };

static const char goldendictcmd[]     = "~/.config/scripts/goldendict.sh";
static const char startpomodorocmd[]  = "~/.config/scripts/pomodoro.sh 60";
static const char stoppomodorocmd[]   = "pkill pom; echo > /tmp/pomodoro";
static const char windowswitchercmd[] = "~/.config/scripts/window-switcher.sh";

static const char* raisevolcmd[]      = 
  { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char* lowervolcmd[]      = 
  { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char* mutevolcmd[]       = 
  { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };

static const Key keys[] = {
  /* modifier     key        function        argument */
  /* custom */
  { MODKEY,       XK_d,      spawn,          {.v = dmenucmd} },
  { MODKEY|ALT,   XK_v,      spawn,          {.v = clipmenucmd} },
  { MODKEY|SHIFT, XK_Return, spawn,          {.v = termcmd} },
  { MODKEY|SHIFT, XK_s,      spawn,          {.v = slockcmd} },
  { MODKEY|SHIFT, XK_z,      spawn,          {.v = zathuracmd} },
  { MODKEY|SHIFT, XK_f,      spawn,          {.v = floorpcmd} },
  { MODKEY|ALT,   XK_f,      spawn,          {.v = flameshotcmd} },
  /* scirpts */
  { MODKEY,       XK_w,      spawn,          SHCMD(windowswitchercmd) },
  { MODKEY,       XK_g,      spawn,          SHCMD(goldendictcmd) },
	{ MODKEY,       XK_p,      spawn,          SHCMD(startpomodorocmd) },
  { MODKEY|SHIFT, XK_p,      spawn,          SHCMD(stoppomodorocmd) },
  /* volume */
  { 0,            RAISEVOL,  spawn,          {.v = raisevolcmd} },
  { 0,            LOWERVOL,  spawn,          {.v = lowervolcmd} },
  { 0,            MUTEVOL,   spawn,          {.v = mutevolcmd} },
  /* wm */
  { MODKEY,       XK_b,      togglebar,      {0} },
  { MODKEY,       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,       XK_o,      incnmaster,     {.i = -1 } },
  { MODKEY,       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,       XK_Return, zoom,           {0} },
  { MODKEY,       XK_Tab,    view,           {0} },
  { MODKEY|SHIFT, XK_q,      killclient,     {0} },
  { MODKEY,       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,       XK_f,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,       XK_space,  setlayout,      {0} },
  { MODKEY|SHIFT, XK_space,  togglefloating, {0} },
  { MODKEY,       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|SHIFT, XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|SHIFT, XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|SHIFT, XK_period, tagmon,         {.i = +1 } },
  { MODKEY,       XK_minus,  setgaps,        {.i = -1 } },
  { MODKEY,       XK_equal,  setgaps,        {.i = +1 } },
  { MODKEY|SHIFT, XK_equal,  setgaps,        {.i = 0  } },
  TAGKEYS(        XK_1,                      0)
  TAGKEYS(        XK_2,                      1)
  TAGKEYS(        XK_3,                      2)
  { MODKEY|SHIFT, XK_e,      quit,           {0} },
};

/* button definitions */
static const Button buttons[] = {
  /* click        event mask button   function     argument */
  { ClkWinTitle,  0,         Button2, zoom,        {0} },
  { ClkClientWin, MODKEY,    Button1, movemouse,   {0} },
  { ClkClientWin, MODKEY,    Button3, resizemouse, {0} },
}; 
