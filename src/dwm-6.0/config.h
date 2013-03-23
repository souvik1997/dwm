#include "fibonacci.c"
/* See LICENSE file for copyright and license details. */

/* appearance */
//static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char font[]  = "-*-terminus2-*-*-*-*-*-*-*-*-*-*-*-*";

//static const char font[] = "-*-terminus2-medium-r-*-*-12-*-*-*-*-*-*-*";

#define NUMCOLORS 39
static const char colors[NUMCOLORS][ColLast][21] = {
	/* border     fg         bg */

	{"#1D1D1D","#1C678C","#030303"}, //FG:SeaBlue BG:Black ID:1 (1)
	{"#1D1D1D","#FDFDFD","#030303"}, //FG:White BG:Black ID:2 (2)
	{"#1D1D1D","#1D1D1D","#1C678C"}, //FG:Gray BG:SeaBlue ID:3 (3)
	{"#1D1D1D","#1D1D1D","#EAC658"}, //FG:Gray BG:SolarizedYellow ID:4 (4)
	{"#1D1D1D","#1D1D1D","#E77636"}, //FG:Gray BG:SoftOrange ID:5 (5)
	{"#1D1D1D","#1D1D1D","#CE2319"}, //FG:Gray BG:SoftRed ID:6 (6)
	{"#B3354C","#B3354C","#1D1D1D"}, //FG:Magenta BG:Gray ID:7 (7)
	{"#B3354C","#B3354C","#B3354C"}, //FG:Magenta BG:Magenta ID:8 (8)
	{"#B3354C","#B3354C","#1C678C"}, //FG:Magenta BG:SeaBlue ID:9 (9)
	{"#B3354C","#B3354C","#1C678C"}, //Unusable
	{"#B3354C","#B3354C","#EAC658"}, //FG:Magenta BG:SolarizedYellow ID:11 (b)
	{"#B3354C","#B3354C","#E77636"}, //FG:Magenta BG:SoftOrange ID:12 (c)
	{"#B3354C","#B3354C","#CE2319"}, //FG:Magenta BG:SoftRed ID:13 (d)
	{"#1C678C","#1C678C","#1D1D1D"}, //FG:SeaBlue BG:Gray ID:14 (e)
	{"#1C678C","#1C678C","#B3354C"}, //FG:SeaBlue BG:Magenta ID:15 (f)
	{"#1C678C","#1C678C","#1C678C"}, //FG:SeaBlue BG:SeaBlue ID:16 (10)
	{"#1C678C","#1C678C","#EAC658"}, //FG:SeaBlue BG:SolarizedYellow ID:17 (11)
	{"#1C678C","#1C678C","#E77636"}, //FG:SeaBlue BG:SoftOrange ID:18 (12)
	{"#1C678C","#1C678C","#CE2319"}, //FG:SeaBlue BG:SoftRed ID:19 (13)
	{"#EAC658","#EAC658","#1D1D1D"}, //FG:SolarizedYellow BG:Gray ID:20 (14)
	{"#EAC658","#EAC658","#B3354C"}, //FG:SolarizedYellow BG:Magenta ID:21 (15)
	{"#EAC658","#EAC658","#1C678C"}, //FG:SolarizedYellow BG:SeaBlue ID:22 (16)
	{"#EAC658","#EAC658","#EAC658"}, //FG:SolarizedYellow BG:SolarizedYellow ID:23 (17)
	{"#EAC658","#EAC658","#E77636"}, //FG:SolarizedYellow BG:SoftOrange ID:24 (18)
	{"#EAC658","#EAC658","#CE2319"}, //FG:SolarizedYellow BG:SoftRed ID:25 (19)
	{"#E77636","#E77636","#1D1D1D"}, //FG:SoftOrange BG:Gray ID:26 (1a)
	{"#E77636","#E77636","#B3354C"}, //FG:SoftOrange BG:Magenta ID:27 (1b)
	{"#E77636","#E77636","#1C678C"}, //FG:SoftOrange BG:SeaBlue ID:28 (1c)
	{"#E77636","#E77636","#EAC658"}, //FG:SoftOrange BG:SolarizedYellow ID:29 (1d)
	{"#E77636","#E77636","#E77636"}, //FG:SoftOrange BG:SoftOrange ID:30 (1e)
	{"#E77636","#E77636","#CE2319"}, //FG:SoftOrange BG:SoftRed ID:31 (1f)
	{"#CE2319","#CE2319","#CE2319"}, //Unusable
	{"#CE2319","#CE2319","#1D1D1D"}, //FG:SoftRed BG:Gray ID:33 (21)
	{"#CE2319","#CE2319","#B3354C"}, //FG:SoftRed BG:Magenta ID:34 (22)
	{"#CE2319","#CE2319","#1C678C"}, //FG:SoftRed BG:SeaBlue ID:35 (23)
	{"#CE2319","#CE2319","#EAC658"}, //FG:SoftRed BG:SolarizedYellow ID:36 (24)
	{"#CE2319","#CE2319","#E77636"}, //FG:SoftRed BG:SoftOrange ID:37 (25)
	{"#CE2319","#CE2319","#CE2319"}, //FG:SoftRed BG:SoftRed ID:38 (26)
	{"#030303","#030303","#1C678C"}, //FG:Black BG:SeaBlue ID:39 (27)
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
static const unsigned int shade = 70; 
//int marginbottom = 20;
int marginbottom = 0;
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class instance title tagsmask isfloating monitor opacity*/
	{ "Gimp", NULL, NULL, 0, True, -1, -1},
        //{ "XTerm", "xterm",   "alsamixer",   NULL,   True,      -1, False}, /* scratchpad in its own tag (6th) */
        { "URxvt", "wifi-menu",   "Wifi-menu",   NULL,   True,      -1, -1}, /* scratchpad in its own tag (6th) */
        { "Qalculate", NULL, NULL, NULL, True, -1, -1},
        { "XTerm", NULL, NULL, NULL, True, -1, -1},
        { "Gnuplot", NULL, NULL, NULL, True, -1, -1},
	{ "Xfce4-panel", NULL, "", ~0, False, -1, -1},
	{ "lxpanel", NULL, "", ~0, True, -1, -1},
	{ "Docky", NULL, "", ~0, False, -1, -1},
	{ "Tint2", NULL, NULL, ~0, False, -1, -1},
	{ "trayer", NULL, NULL, ~0, False, -1, -1},
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */
static const unsigned int gappx     = 10; // Useless gaps

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\u00C9 ",      tile },    /* first entry is default */
	{ "\u00CA ",      NULL },    /* no layout function means floating behavior */
	{ "\u00CB ",      monocle },
	{ "\u00CC", spiral	},
	{ "\u00CD", dwindle	},
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
    { MODKEY,                       XK_s,      setlayout,      {.v = &layouts[3]} },   
    { MODKEY,                       XK_d,      setlayout,      {.v = &layouts[4]} },
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
    {MODKEY,			XK_a,      spawn,	   {.v = launchChromium} },
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
