/* See LICENSE file for copyright and license details. */

/* appearance */
//static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char font[]  = "-*-terminus2-*-*-*-*-*-*-*-*-*-*-*-*";

//static const char font[] = "-*-terminus2-medium-r-*-*-12-*-*-*-*-*-*-*";

#define NUMCOLORS 21
static const char colors[NUMCOLORS][ColLast][21] = {
    /* border     fg         bg */
    { "#1A1A1A", "#808080", "#020202" },  /* 01 - normal */
    { "#4C4C4C", "#B3B3B3", "#020202" },  /* 02 - selected */
    { "#B3354C", "#B3354C", "#020202" },  /* 03 - urgent */

    { "#1A1A1A", "#1A1A1A", "#020202" },  /* 04 - black */
    { "#802635", "#802635", "#020202" },  /* 05 - red */
    { "#608040", "#608040", "#020202" },  /* 06 - green */
    { "#877C43", "#877C43", "#020202" },  /* 07 - yellow */
    { "#1C678C", "#1C678C", "#020202" },  /* 08 - blue */
    { "#684D80", "#684D80", "#020202" },  /* 09 - magenta */
    { "#000000", "#000000", "#000000" },  /* unusable */
    { "#337373", "#337373", "#020202" },  /* 0B - cyan */
    { "#808080", "#808080", "#020202" },  /* 0C - light gray */
    { "#4C4C4C", "#4C4C4C", "#020202" },  /* 0D - gray */
    { "#B3354C", "#B3354C", "#020202" },  /* 0E - light red */
    { "#4BA65A", "#4BA65A", "#020202" },  /* 0F - light green */
    { "#BF9F5F", "#BF9F5F", "#020202" },  /* 10 - light yellow */
    { "#3995BF", "#3995BF", "#020202" },  /* 11 - light blue */
    { "#A64286", "#A64286", "#020202" },  /* 12 - light magenta */
    { "#6C98A6", "#6C98A6", "#020202" },  /* 13 - light cyan */
    { "#B3B3B3", "#B3B3B3", "#020202" },  /* 14 - white */

    { "#802635", "#BF9F5F", "#802635" },  /* 15 - warning */
};

static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
//int marginbottom = 20;
int marginbottom = 0;
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class instance title tagsmask isfloating monitor dontshow*/
	{ "Gimp", NULL, NULL, 0, True, -1, False},
        //{ "XTerm", "xterm",   "alsamixer",   NULL,   True,      -1, False}, /* scratchpad in its own tag (6th) */
        { "URxvt", "wifi-menu",   "Wifi-menu",   NULL,   True,      -1, False}, /* scratchpad in its own tag (6th) */
        { "Qalculate", NULL, NULL, NULL, True, -1, False},
        { "XTerm", NULL, NULL, NULL, True, -1, False},
        { "Gnuplot", NULL, NULL, NULL, True, -1, False},
	{ "Xfce4-panel", NULL, "", ~0, False, -1, False},
	{ "lxpanel", NULL, "", ~0, True, -1, True},
	{ "Docky", NULL, "", ~0, False, -1, False},
	{ "Tint2", NULL, NULL, ~0, False, -1, False},
	{ "trayer", NULL, NULL, ~0, False, -1, False},
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */
static const unsigned int gappx     = 6; // Useless gaps

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\u00C9 ",      tile },    /* first entry is default */
	{ "\u00CA ",      NULL },    /* no layout function means floating behavior */
	{ "\u00CB ",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define SUPERKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "/home/souvik1997/bin/urxvt-launcher.sh", NULL };
static const char *volup[]    ={"/home/souvik1997/bin/volup.sh","","",NULL};
static const char *voldwn[]    = {"/home/souvik1997/bin/voldwn.sh","","",NULL};
static const char *volmute[]    = {"volmute", NULL};
static const char *alsamixer[] = { "xterm-centered.sh", "-title", "alsamixer", "-e", "alsamixer", NULL };
static const char *wifimenu[] = { "xterm-centered.sh", "-title", "wifi-menu", "-e", "/home/souvik1997/bin/wifi-menu-wrapper.sh", NULL };

static const char *launchChromium[] = {"chromium","","",NULL};
static const char *launchGedit[] = {"gvim",NULL};
static const char *launchFM[]={"pcmanfm","","",NULL};
static const char *logout[]={"/home/souvik1997/bin/logout-dwm.sh","","",NULL};
static const char *mute[]={"/home/souvik1997/bin/mute.sh","","",NULL};
static const char *screenshot[]={"/home/souvik1997/bin/screenshot.sh","","",NULL};
static const char *screenshotrect[]={"/home/souvik1997/bin/screenshot.sh","rectangle","",NULL};
static const char *dimscreen[]={"/home/souvik1997/bin/dimscreen.sh","","",NULL};
static const char *dimscreen2[]={"/home/souvik1997/bin/dimscreen2.sh","","",NULL};
static const char *dimscreen3[]={"/home/souvik1997/bin/dimscreen3.sh","","",NULL};
static const char *quitFunc[]={"/usr/bin/systemctl","--user","exit",NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    { 0,                       0xff67,      spawn,          {.v = 
dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             0x60, spawn,               {.v = logout } }, // Shift+Alt+Grave
    { 0,             0x1008ff14, spawn,               {.v = logout } },
    { 0,                       0x1008ff11,      spawn,          {.v = alsamixer } },
    { 0,                       0x1008ff13,      spawn,          {.v = alsamixer } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { ControlMask,                       0xffbe,      spawn,     {.v = wifimenu} }, // Alt+F4
    { MODKEY,                       0xffc1,      killclient,     {0} }, // Alt+F4
    { MODKEY,                       0xffc3,     spawn,         {.v = dimscreen} },
    { MODKEY,                       0xffc4,     spawn,         {.v = dimscreen2} },
    { MODKEY,                       0xffc5,     spawn,         {.v = dimscreen3} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,			    XK_equal,  cycle, 	       {1} },
    { MODKEY,			    XK_minus,  cycle, 	       {-1} },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    {SUPERKEY,			XK_x,      spawn,	   {.v = launchChromium} },
    {MODKEY,			XK_e,      spawn,          {.v = launchGedit} },
    {MODKEY|ShiftMask,			XK_z,      spawn,          {.v = launchFM} },
    {0,			0x1008ff12,      spawn,          {.v = mute} },
    {0,			0xff61,      spawn,          {.v = screenshot} },
    { MODKEY|ShiftMask,             XK_q,      quitFunc,           {0} }
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         7,        cycle         ,{1} },
	{ ClkClientWin,         MODKEY,         6,        cycle         , {-1} },
        { ClkLtSymbol,         MODKEY,         7,        cycle         ,{1} },
        { ClkLtSymbol,         MODKEY,         6,        cycle         , {-1} },
        { ClkStatusText,         MODKEY,         7,        cycle         ,{1} },
        { ClkStatusText,         MODKEY,         6,        cycle         , {-1} },
        { ClkWinTitle,         MODKEY,         7,        cycle         ,{1} },
        { ClkWinTitle,         MODKEY,         6,        cycle         , {-1} },
        { ClkRootWin,         MODKEY,         7,        cycle         ,{1} },
        { ClkRootWin,         MODKEY,         6,        cycle         , {-1} },



	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const Bool systray_enable  = True;
static const int  systray_spacing = 2;
Bool autohide    = True;
static const int status_height = 0;
