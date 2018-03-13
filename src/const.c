/****************************************************************************
 * SynMUD copyright (c) 2018 was created by                                 *
 * Paolo 'Marduk' Francioso (email unknown)                                 *
 ***************************************************************************/ 

/* 

SWFotE copyright (c) 2002 was created by
Chris 'Tawnos' Dary (cadary@uwm.edu),
Korey 'Eleven' King (no email),
Matt 'Trillen' White (mwhite17@ureach.com),
Daniel 'Danimal' Berrill (danimal924@yahoo.com),
Richard 'Bambua' Berrill (email unknown),
Stuart 'Ackbar' Unknown (email unknown)

SWR 1.0 copyright (c) 1997, 1998 was created by Sean Cooper
based on a concept and ideas from the original SWR immortals: 
Himself (Durga), Mark Matt (Merth), Jp Coldarone (Exar), Greg Baily (Thrawn), 
Ackbar, Satin, Streen and Bib as well as much input from our other builders 
and players.

Original SMAUG 1.4a written by Thoric (Derek Snider) with Altrag,
Blodkai, Haus, Narn, Scryn, Swordbearer, Tricops, Gorog, Rennard,
Grishnakh, Fireblade, and Nivek.

Original MERC 2.1 code by Hatchet, Furey, and Kahn.

Original DikuMUD code by: Hans Staerfeldt, Katja Nyboe, Tom Madsen,
Michael Seifert, and Sebastian Hammer.

*/

#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include "mud.h"

/* undef these at EOF */
#define AM 95
#define AC 95
#define AT 85
#define AW 85
#define AV 95
#define AD 95
#define AR 90
#define AA 95

/*
 * Race table.
 */
struct race_type race_table[MAX_RACE] = {
   /*
    * race name     DEF_AFF      st dx ws in cn ch lk hp mn re su   RESTRICTION  LANGUAGE 
      assign always a not LANG_BASIC language. It will be added in comm.c
	*/
   {
    "Italian", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_ITALIAN },
   {
    "German", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_GERMAN },
   {
    "French", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_FRENCH },
   {
    "Spanish", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_SPANISH },
   {
  	"English", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_ENGLISH },
   {
    "Russian", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_RUSSIAN },
   {
    "Chinese", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_CHINESE },
   {
    "Japanese", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_JAPANESE },
   {
    "Turkish", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_TURKISH },
   {
    "American", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_ENGLISH },
   {
    "Indian", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_INDIAN },
   {
    "Australian", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_ENGLISH },
   {
    "Brazilian", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_PORTUGUESE },
   {
    "Mexican", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_SPANISH },
   {
    "African", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LANG_AFRO }	
};



const char *const npc_race[MAX_NPC_RACE] = {
   "Italian", "German", "French", "Spanish", "English", "Russian", "Chinese",
   "Japanese", "Turkish", "American", "Indian", "Australian", "Brazilian", "Mexican",
   "African", "r16",
   "r17", "r18", "r19", "r20", "r21", "r22",
   "r23", "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31", "r32",
   "r33", "r34", "r35", "r36", "r37", "r38", "r39",
   "r40", "r41", "r42", "r43", "r44", "r45", "r46", "r47",
   "r48", "r49", "r50", "r51", "r52", "r53", "r54",
   "r55", "r56", "r57", "r58", "r59",
   "r60", "r61", "r62", "r63", "r64", "r65", "r66",
   "r67", "r68", "r69", "r70", "r71", "r72", "r73", "r74",
   "r75", "r76", "r77", "r78", "r79", "r80", "r81", "r82",
   "r83", "r84", "r85", "r86", "Cyborg", "Android", "Droid", "Animal"
};


const char *const ability_name[MAX_ABILITY] = {
   "Commando", "Defender", "Engineer", "Hunter", "Infiltrator", "Persuader", "Not Used Yet", "Hacker", "Assassin",
   "Medic"
};

const char *const height_name[4] = {
   "average", "short", "tall", "very tall"
};

const char *const build_name[6] = {
   "petite", "thin", "lean", "overweight", "muscular", "obese"
};

const char *const droid_name[8] = {
   "modern", "antique", "small", "large", "tiny", "polished",
   "sleek", "huge"
};

/*
 * Attribute bonus tables.
 */
const struct str_app_type str_app[26] = {
   {-5, -4, 0, 0},   /* 0  */
   {-5, -4, 3, 1},   /* 1  */
   {-3, -2, 3, 2},
   {-3, -1, 10, 3},  /* 3  */
   {-2, -1, 25, 4},
   {-2, -1, 55, 5},  /* 5  */
   {-1, 0, 80, 6},
   {-1, 0, 90, 8},
   {0, 0, 100, 10},
   {0, 0, 100, 12},
   {0, 0, 115, 14},  /* 10  */
   {0, 0, 115, 15},
   {0, 0, 140, 16},
   {0, 0, 140, 17},  /* 13  */
   {0, 0, 170, 18},
   {1, 1, 170, 19},  /* 15  */
   {1, 1, 195, 20},
   {2, 2, 220, 22},
   {2, 2, 250, 25},  /* 18  */
   {3, 3, 400, 30},
   {4, 4, 500, 35},  /* 20  */
   {4, 4, 600, 40},
   {5, 5, 700, 45},
   {6, 6, 800, 50},
   {7, 7, 900, 55},
   {8, 8, 999, 60} /* 25   */
};



const struct int_app_type int_app[26] = {
   {3},  /*  0 */
   {5},  /*  1 */
   {7},
   {8},  /*  3 */
   {9},
   {10}, /*  5 */
   {11},
   {12},
   {13},
   {15},
   {17}, /* 10 */
   {19},
   {22},
   {25},
   {28},
   {31}, /* 15 */
   {34},
   {37},
   {40}, /* 18 */
   {44},
   {49}, /* 20 */
   {55},
   {60},
   {70},
   {85},
   {99}  /* 25 */
};



const struct wis_app_type wis_app[26] = {
   {0},  /*  0 */
   {0},  /*  1 */
   {0},
   {0},  /*  3 */
   {0},
   {1},  /*  5 */
   {1},
   {1},
   {1},
   {2},
   {2},  /* 10 */
   {2},
   {2},
   {2},
   {2},
   {3},  /* 15 */
   {3},
   {4},
   {5},  /* 18 */
   {5},
   {5},  /* 20 */
   {6},
   {6},
   {6},
   {6},
   {7}   /* 25 */
};



const struct dex_app_type dex_app[30] = {
   {6}, /* 0 */
   {5}, /* 1 */
   {5},
   {4},
   {3},
   {2}, /* 5 */
   {1},
   {0},
   {0},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {0},
   {-1},   /* 15 */
   {-1},
   {-2},
   {-2},
   {-3},
   {-3},   /* 20 */
   {-4},
   {-4},
   {-5},
   {-5},
   {-6},  /* 25 */
   {-6},
   {-7},
   {-7},
   {-8}   /* 29 */
};



const struct con_app_type con_app[26] = {
   {-30, 20},   /*  0 */
   {-30, 25},   /*  1 */
   {-20, 30},
   {-20, 35},   /*  3 */
   {-20, 40},
   {-10, 45},   /*  5 */
   {-10, 50},
   {0, 55},
   {0, 60},
   {0, 65},
   {0, 70}, /* 10 */
   {10, 75},
   {20, 80},
   {30, 85},
   {40, 88},
   {50, 90}, /* 15 */
   {60, 95},
   {70, 97},
   {80, 99}, /* 18 */
   {90, 99},
   {100, 99}, /* 20 */
   {110, 99},
   {120, 99},
   {130, 99},
   {140, 99},
   {150, 99}  /* 25 */
};


const struct cha_app_type cha_app[26] = {
   {-60},   /* 0 */
   {-50},   /* 1 */
   {-50},
   {-40},
   {-30},
   {-20},   /* 5 */
   {-10},
   {-5},
   {-1},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {1},
   {5},  /* 15 */
   {10},
   {20},
   {30},
   {40},
   {50}, /* 20 */
   {60},
   {70},
   {80},
   {90},
   {99}  /* 25 */
};

/* Have to fix this up - not exactly sure how it works (Scryn) */
const struct lck_app_type lck_app[26] = {
   {60}, /* 0 */
   {50}, /* 1 */
   {50},
   {40},
   {30},
   {20}, /* 5 */
   {10},
   {0},
   {0},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {0},
   {-10},   /* 15 */
   {-15},
   {-20},
   {-30},
   {-40},
   {-50},   /* 20 */
   {-60},
   {-75},
   {-90},
   {-105},
   {-120}   /* 25 */
};

/*
 * Liquid properties.
 * Used in #OBJECT section of area file.
 */
const struct liq_type liq_table[LIQ_MAX] = {
   {"water", "clear", {0, 1, 10}},  /*  0 */
   {"beer", "amber", {3, 2, 5}},
   {"wine", "rose", {5, 2, 5}},
   {"ale", "brown", {2, 2, 5}},
   {"dark ale", "dark", {1, 2, 5}},

   {"whiskey", "golden", {6, 1, 4}},   /*  5 */
   {"lemonade", "pink", {0, 1, 8}},
   {"firebreather", "boiling", {10, 0, 0}},
   {"local specialty", "everclear", {3, 3, 3}},
   {"slime mold juice", "green", {0, 4, -8}},

   {"milk", "white", {0, 3, 6}}, /* 10 */
   {"tea", "tan", {0, 1, 6}},
   {"coffee", "black", {0, 1, 6}},
   {"blood", "red", {0, 2, -1}},
   {"salt water", "clear", {0, 1, -2}},

   {"cola", "cherry", {0, 1, 5}},   /* 15 */
   {"mead", "honey color", {4, 2, 5}}, /* 16 */
   {"grog", "thick brown", {3, 2, 5}}, /* 17 */
   {"milkshake", "creamy", {0, 8, 5}}  /* 18 */
};

const char *const attack_table[13] = {
   "hit",
   "slice", "stab", "slash", "whip", "claw",
   "blast", "pound", "crush", "shot", "bite",
   "pierce", "suction"
};



/*
 * The skill and spell table.
 * Slot numbers must never be changed as they appear in #OBJECTS sections.
 */
#define SLOT(n)	n
#define LI LEVEL_IMMORTAL

#undef AM
#undef AC
#undef AT
#undef AW
#undef AV
#undef AD
#undef AR
#undef AA

#undef LI
