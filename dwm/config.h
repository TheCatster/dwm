/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "alacritty"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps               = 1;   /* 1 means no outer gap when there is only one window */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "JuliaMono:size=11", "Noto Color Emoji:pixelsize=11:antialias=true:autohint=true" };
static const char dmenufont[]            = "JuliaMono:size=11";

static char normfgcolor[]                = "#c6d4e4";
static char normbgcolor[]                = "#0c0b0c";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#c6d4e4";
static char selbgcolor[]                 = "#0c0b0c";
static char selbordercolor[]             = "#316097";
static char selfloatcolor[]              = "#0c0b0c";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#c6d4e4";
static char titleselbgcolor[]            = "#0c0b0c";
static char titleselbordercolor[]        = "#0c0b0c";
static char titleselfloatcolor[]         = "#0c0b0c";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#c6d4e4";
static char tagsselbgcolor[]             = "#0c0b0c";
static char tagsselbordercolor[]         = "#0c0b0c";
static char tagsselfloatcolor[]          = "#0c0b0c";

static char hidfgcolor[]                 = "#0c0b0c";
static char hidbgcolor[]                 = "#222222";
static char hidbordercolor[]             = "#0c0b0c";
static char hidfloatcolor[]              = "#f76e0c";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static char *colors[][ColCount] = {
  /*                       fg                bg                border                float */
  [SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
  [SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
  [SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
  [SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
  [SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
  [SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
  [SchemeHid]          = { hidfgcolor,       hidbgcolor,       hidbordercolor,       hidfloatcolor },
  [SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-f", "JuliaMono:size=10", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-f", "JuliaMono:size=14", "-g", "50x20", "-e", "bb", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spcalc",      spcmd2},
};

static char *tagicons[][NUMTAGS] = {
  [DEFAULT_TAGS]        = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
};

static const Rule rules[] = {
  // class instance title wintype isfloating monitor
  RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
  RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
  RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
  RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
  RULE(.class = "Android Emulator", .isfloating = 1)
  RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
  RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1)
};

static const BarRule barrules[] = {
  /* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
  { -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
  {  0,       0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
  { -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
  {  0,       0,     BAR_ALIGN_RIGHT,  width_status,            draw_status,            click_statuscmd,         "status" },
  { -1,       0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */


static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[M]",      monocle },
  { "TTT",      bstack },
  { "|M|",      centeredmaster },
  { "[D]",      deck },
  { "[\\]",     dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
  { MOD,  XK_j, ACTION##stack,  {.i = INC(+1) } }, \
  { MOD,  XK_k, ACTION##stack,  {.i = INC(-1) } }, \
  { MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
  "dmenu_run",
  "-m", dmenumon,
  "-fn", dmenufont,
  "-nb", normbgcolor,
  "-nf", normfgcolor,
  "-sb", selbgcolor,
  "-sf", selfgcolor,
  NULL
};
static const char *termcmd[]  = { TERMINAL, NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
  /* modifier                     key        function        argument */
  STACKKEYS(MODKEY,                          focus)
  STACKKEYS(MODKEY|ShiftMask,                push)
  { MODKEY,     XK_grave, spawn,  SHCMD("dmenuunicode") },
  TAGKEYS(      XK_1,   0)
  TAGKEYS(      XK_2,   1)
  TAGKEYS(      XK_3,   2)
  TAGKEYS(      XK_4,   3)
  TAGKEYS(      XK_5,   4)
  TAGKEYS(      XK_6,   5)
  TAGKEYS(      XK_7,   6)
  TAGKEYS(      XK_8,   7)
  TAGKEYS(      XK_9,   8)
  { MODKEY,     XK_0,   view,   {.ui = ~0 } },
  { MODKEY|ShiftMask,   XK_0,   tag,    {.ui = ~0 } },
  { MODKEY,     XK_minus, spawn,    SHCMD("pamixer -d 5; kill -44 $(pidof dwmblocks)") },
  { MODKEY|ShiftMask,   XK_minus, spawn,    SHCMD("pamixer -d 15; kill -44 $(pidof dwmblocks)") },
  { MODKEY,     XK_equal, spawn,    SHCMD("pamixer -i 5; kill -44 $(pidof dwmblocks)") },
  { MODKEY|ShiftMask,   XK_equal, spawn,    SHCMD("pamixer -i 15; kill -44 $(pidof dwmblocks)") },
  { MODKEY,     XK_BackSpace, spawn,    SHCMD("sysact") },
  { MODKEY|ShiftMask,   XK_BackSpace, spawn,    SHCMD("sysact") },

  { MODKEY,     XK_Tab,   view,   {0} },
  { MODKEY,     XK_q,   killclient, {0} },
  { MODKEY,     XK_w,   spawn,    SHCMD("$BROWSER") },
  { MODKEY|ShiftMask,   XK_w,   spawn,    SHCMD("$BROWSER -P default-release") },
  { MODKEY,     XK_e,   spawn,    SHCMD("$EDITOR") },
  { MODKEY|ShiftMask,   XK_e,   spawn,    SHCMD("thunderbird") },
  { MODKEY,     XK_t,   setlayout,  {.v = &layouts[0]} }, /* tile */
  { MODKEY|ShiftMask,   XK_t,   setlayout,  {.v = &layouts[1]} }, /* null */
  { MODKEY,     XK_y,   setlayout,  {.v = &layouts[2]} }, /* monocle */
  { MODKEY|ShiftMask,   XK_y,   setlayout,  {.v = &layouts[3]} }, /* bstack */
  { MODKEY,     XK_u,   setlayout,  {.v = &layouts[4]} }, /* centered master */
  { MODKEY|ShiftMask,   XK_u,   setlayout,  {.v = &layouts[5]} }, /* deck */
  { MODKEY,     XK_i,   setlayout,  {.v = &layouts[6]} }, /* dwindle */
  { MODKEY|ShiftMask,   XK_i,   setlayout,  SHCMD(TERMINAL " -e sudo nmtui") },
  { MODKEY,     XK_o,   incnmaster,     {.i = +1 } },
  { MODKEY|ShiftMask,   XK_o,   incnmaster,     {.i = -1 } },
  { MODKEY,     XK_p,     spawn,    SHCMD("flameshot gui") },
  { MODKEY,     XK_backslash,   view,   {0} },

  { MODKEY,     XK_a,   togglegaps, {0} },
  { MODKEY|ShiftMask,   XK_a,   defaultgaps,  {0} },
  { MODKEY,     XK_s,   togglesticky, {0} },
  { MODKEY,     XK_d,   spawn,          SHCMD("rofi -show drun") },
  { MODKEY|ShiftMask,   XK_d,   spawn,    SHCMD("dmenyt") },
  { MODKEY,     XK_f,   togglefullscreen, {0} },
  { MODKEY|ShiftMask,   XK_f,   setlayout,  {.v = &layouts[8]} },
  { MODKEY,     XK_g,   shiftview,  { .i = -1 } },
  { MODKEY,     XK_h,   setmfact, {.f = -0.05} },
  { MODKEY,     XK_l,   setmfact,       {.f = +0.05} },
  { MODKEY,     XK_semicolon, shiftview,  { .i = 1 } },
  { MODKEY,     XK_apostrophe,  togglescratch,  {.ui = 1} },
  { MODKEY,     XK_Return,  spawn,    {.v = termcmd } },
  { MODKEY|ShiftMask,   XK_Return,  togglescratch,  {.ui = 0} },

  { MODKEY,     XK_m,   spawn,    SHCMD("spotify") },
  { MODKEY|ShiftMask,   XK_m,   spawn,    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
  { MODKEY,     XK_x,   incrgaps, {.i = -3 } },
  { MODKEY,     XK_z,   incrgaps, {.i = +3 } },
  { MODKEY,     XK_b,   togglebar,  {0} },

  { MODKEY,     XK_Left,  focusmon, {.i = -1 } },
  { MODKEY|ShiftMask,   XK_Left,  tagmon,   {.i = -1 } },
  { MODKEY,     XK_Right, focusmon, {.i = +1 } },
  { MODKEY|ShiftMask,   XK_Right, tagmon,   {.i = +1 } },

  { MODKEY,     XK_Page_Up, shiftview,  { .i = -1 } },
  { MODKEY,     XK_Page_Down, shiftview,  { .i = +1 } },

  { MODKEY,     XK_F3,    spawn,    SHCMD("displayselect") },
  { MODKEY,     XK_F4,    spawn,    SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
  { MODKEY,     XK_F6,    spawn,    SHCMD("torwrap") },
  { MODKEY,     XK_F9,    spawn,    SHCMD("dmenumount") },
  { MODKEY,     XK_F10,   spawn,    SHCMD("dmenuumount") },
  { MODKEY,     XK_F11,   spawn,    SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  { MODKEY,     XK_F12,   spawn,    SHCMD("remaps & notify-send \\\"⌨️ Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") },
  { MODKEY,     XK_space, zoom,   {0} },
  { MODKEY|ShiftMask,   XK_space, togglefloating, {0} },

  { 0,        XK_Print, spawn,    SHCMD("flameshot gui") },
  { MODKEY,     XK_Print, spawn,    SHCMD("dmenurecord") },
  { MODKEY|ShiftMask,   XK_Print, spawn,    SHCMD("dmenurecord kill") },
  { MODKEY,     XK_Delete,  spawn,    SHCMD("dmenurecord kill") },
  { MODKEY,     XK_Scroll_Lock, spawn,    SHCMD("killall screenkey || screenkey &") },

  { 0, XF86XK_AudioMute,    spawn,    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioRaiseVolume, spawn,    SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioLowerVolume, spawn,    SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_PowerOff,   spawn,    SHCMD("sysact") },
  { 0, XF86XK_Sleep,    spawn,    SHCMD("sudo -A zzz") },
  { 0, XF86XK_MonBrightnessUp,  spawn,    SHCMD("xbacklight -inc 15") },
  { 0, XF86XK_MonBrightnessDown,  spawn,    SHCMD("xbacklight -dec 15") },
  { 0, XF86XK_Calculator,   togglescratch,  {.ui = 1} },
  { 0, XF86XK_HomePage,   spawn,    SHCMD("$BROWSER") },
  { 0, XF86XK_MyComputer,   spawn,    SHCMD("thunderbird") },
  { 0, XF86XK_Display,    spawn,    SHCMD("displayselect") },

  /* Unmapped Keys */

  /* { ShiftMask,     XK_Print, spawn,    SHCMD("") }, */
  /* { 0, XF86XK_AudioNext,   spawn,    SHCMD("mpc next") }, */
  /* { 0, XF86XK_AudioPause,    spawn,    SHCMD("mpc pause") }, */
  /* { 0, XF86XK_AudioPlay,   spawn,    SHCMD("mpc play") }, */
  /* { 0, XF86XK_AudioStop,   spawn,    SHCMD("mpc stop") }, */
  /* { 0, XF86XK_AudioRewind, spawn,    SHCMD("mpc seek -10") }, */
  /* { 0, XF86XK_AudioForward,  spawn,    SHCMD("mpc seek +10") }, */
  /* { 0, XF86XK_AudioPrev,   spawn,    SHCMD("mpc prev") }, */
  /* { MODKEY|ShiftMask,    XK_q,   spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_r,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_r,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_p,     spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_bracketleft,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_bracketleft,   spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_bracketright,  spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_bracketright,  spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_Insert,  spawn,    SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") }, */
  /* { MODKEY,      XK_F1,    spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_F2,    spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_F5,    xrdb,   {.v = NULL } }, */
    /* { MODKEY,      XK_F7,    spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_F8,    spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_Escape,  spawn,  SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_grave, togglescratch,  SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_Tab,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_backslash,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_s,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_apostrophe,  spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_z,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_x,   spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_c,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_c,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_b,   spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_n,   spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_n,   spawn,    SHCMD(TERMINAL "") }, */
  /* { MODKEY,      XK_comma, spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_comma, spawn,    SHCMD("") }, */
  /* { MODKEY,      XK_period,  spawn,    SHCMD("") }, */
  /* { MODKEY|ShiftMask,    XK_period,  spawn,    SHCMD("") }, */
  /* { 0, XF86XK_Battery,   spawn,    SHCMD("") }, */
  /* { 0, XF86XK_DOS,   spawn,    SHCMD(TERMINAL) }, */
  /* { 0, XF86XK_ScreenSaver, spawn,    SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") }, */
  /* { 0, XF86XK_TaskPane,    spawn,    SHCMD(TERMINAL " -e htop") }, */
  /* { 0, XF86XK_Mail,    spawn,    SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") }, */
  /* { 0, XF86XK_Launch1,   spawn,    SHCMD("xset dpms force off") }, */
  /* { 0, XF86XK_TouchpadToggle,  spawn,    SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") }, */
  /* { 0, XF86XK_TouchpadOff, spawn,    SHCMD("synclient TouchpadOff=1") }, */
  /* { 0, XF86XK_TouchpadOn,    spawn,    SHCMD("synclient TouchpadOff=0") }, */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
#ifndef __OpenBSD__
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
  { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
  { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
  { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
  { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
  { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
  { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        defaultgaps,  {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkClientWin,   MODKEY,   Button4,  incrgaps, {.i = +1} },
  { ClkClientWin,   MODKEY,   Button5,  incrgaps, {.i = -1} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkTagBar,    0,    Button4,  shiftview,  {.i = -1} },
  { ClkTagBar,    0,    Button5,  shiftview,  {.i = 1} },
  { ClkRootWin,   0,    Button2,  togglebar,  {0} },
};
