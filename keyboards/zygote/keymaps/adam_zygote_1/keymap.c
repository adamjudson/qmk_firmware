#include "zygote.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
// Fillers to make layering more clear


#define XXXX KC_NO
#define ____ KC_TRNS

// note original was plank with 2u space in middle of row 4

// zygote is missing the outer columns, but has two extra keys on row 3 and 4
// so 2 less keys in one and 2 - denoted with KC_NO in the middle two spots
// same keys in row 3
// one additional key in row 4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* base */ \
  /*  
	[0] = LAYOUT_ortho_4x12(\
      KC_TAB,       KC_Q,     KC_W,       KC_E,       KC_R,         KC_T,           KC_Y,         KC_U,       KC_I,         KC_O,     KC_P,     KC_BSPC, \
      LT(4,KC_ESC), KC_A,     LT(5,KC_S), LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G),     LSFT_T(KC_H), LT(8,KC_J), LT(10,KC_K),  KC_L,     KC_SCLN,  KC_QUOT, \
      KC_LSFT,      KC_Z,     KC_X,       KC_C,       KC_V,         LT(7,KC_B),     KC_N,         KC_M,       KC_COMM,      KC_DOT,   KC_SLSH,  KC_LSFT,  \
      KC_LCTL,      KC_LGUI,  TT(6),      KC_LALT,    LT(1,KC_ENT), LSFT_T(KC_SPC),               MO(2),      KC_LEFT,      KC_DOWN,  KC_UP,    KC_RGHT), \
  */ \
  \
  /* lower */ \
  /*  
	[1] = LAYOUT_ortho_4x12(\
      KC_TILD,      KC_EXLM,  KC_AT,      KC_HASH,    KC_DLR,       KC_PERC,        KC_CIRC,      KC_AMPR,    KC_ASTR,        KC_LPRN,  KC_RPRN,   KC_DEL, \
      KC_TRNS,      KC_F1,    KC_F2,      KC_F3,      KC_F4,        KC_F5,          KC_F6,        KC_UNDS,    KC_EQUAL,       KC_LCBR,  KC_RCBR,   KC_PIPE, \
      KC_TRNS,      KC_F7,    KC_F8,      KC_F9,      KC_F10,       KC_F11,         KC_F12,       KC_MUTE,    KC_LT,          KC_GT,    KC_QUES,    KC_QUOT, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,                      MO(3),      LALT(KC_LEFT),  KC_VOLD,  KC_VOLU,  LALT(KC_RGHT)), \
  */ \
  /* raise */ \
  /*  
	[2] = LAYOUT_ortho_4x12(\
      KC_GRV,       KC_1,     KC_2,       KC_3,       KC_4,         KC_5,           KC_6,         KC_7,       KC_8,           KC_9,     KC_0,     KC_DEL, \
      KC_TRNS,      KC_F1,    KC_F2,      KC_F3,      KC_F4,        KC_F5,          KC_F6,        KC_PMNS,    KC_EQUAL,       KC_LBRC,  KC_RBRC,  KC_BSLS, \
      KC_TRNS,      KC_F7,    KC_F8,      KC_F9,      KC_F10,       KC_F11,         KC_F12,       KC_MUTE,    KC_TRNS,        KC_TRNS,  KC_BSLS,  KC_MPRV,  \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    MO(3),        KC_TRNS,                      KC_TRNS,    KC_MPLY,        KC_VOLD,  KC_VOLU,  KC_MNXT), \
  */ \
  \
  /* adjust */  \
  /*  
	[3] = LAYOUT_ortho_4x12(\
      KC_TRNS,      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    RESET, \
      KC_TRNS,      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    RESET, \
      KC_TRNS,      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO, \
      KC_TRNS,      KC_NO,    KC_TRNS,    KC_NO,      KC_TRNS,      LCA(KC_DEL),                  KC_TRNS,    KC_NO,          KC_NO,    KC_NO,    EEP_RST), \
  */ \
  \
  /* anne pro / desktop swap */ \
  /*  
	[4] = LAYOUT_ortho_4x12(\
      KC_DEL,       LGUI(LCTL(KC_LEFT)),  LGUI(LCTL(KC_RIGHT)),   LGUI(KC_E), LALT(KC_F4), KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,    KC_NO,    KC_DEL, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_INS, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,                        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO), \
  */ \
  \
  /* numbers */ \
  /*  
	[5] = LAYOUT_ortho_4x12(\
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_PAST,      KC_P7,      KC_P8,          KC_P9,    KC_PMNS,  KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_P4,      KC_P5,          KC_P6,    KC_PPLS,  KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_P1,      KC_P2,          KC_P3,    KC_TRNS,  KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_P0,                        KC_PDOT,    KC_NO,          KC_NO,    KC_NO,    KC_NO),\
  */ \
  \
  /* mouse - we don't have a fn key, so maybe we don't want this?*/ \
  /*  
	[6] = LAYOUT_ortho_4x12(\
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_MS_U,        KC_NO,    KC_NO,    KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_MS_L,    KC_MS_D,        KC_MS_R,  KC_NO,    KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_WH_U,        KC_NO,    KC_NO,    KC_NO, \
      KC_NO,        KC_NO,    KC_TRNS,    KC_NO,      KC_TRNS,      KC_BTN1,                      KC_TRNS,    KC_WH_D,        KC_NO,    KC_NO,    KC_NO),\
  */ \
  \
  /* brackets - g layer */ \
  /*  
	[7] = LAYOUT_ortho_4x12(\
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_LBRC,        KC_RBRC,  KC_NO,    KC_NO, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,          KC_NO,        KC_LPRN,    KC_RPRN,        KC_LCBR,  KC_RCBR,  KC_NO, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_LBRC,    KC_RBRC,        KC_NO,    KC_NO,    KC_NO, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,                        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO), \
  */ \
  \
  /*  os nav - j layer */ \
  /*  
	[8] = LAYOUT_ortho_4x12(\
      KC_TRNS,      LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),     LGUI(KC_6),   LGUI(KC_7), LGUI(KC_8),     KC_NO,    KC_NO,    KC_NO, \
      KC_TRNS,      KC_NO,    KC_NO,      LGUI(KC_3), KC_NO,        KC_NO,          KC_NO,        KC_TRNS,    KC_LGUI,        LGUI(KC_L), KC_NO,  KC_NO, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_NO,    KC_NO,    KC_NO, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS,                      KC_TRNS,    KC_TRNS,        KC_NO,    KC_NO,    KC_NO), \
  */ \
  \
  /* nav - d layer */ \
  /*  
	[9] = LAYOUT_ortho_4x12(\
      KC_TRNS,      KC_TRNS,  LCTL(KC_W), KC_TRNS,    LCTL(KC_R),   LCTL(KC_T),     KC_TRNS,      KC_PGUP,    KC_UP,          KC_PGDN,  KC_NO,    KC_TRNS, \
      KC_TRNS,      KC_TRNS,  KC_DEL,     KC_TRNS,    KC_LSFT,      LCTL(KC_TAB),   KC_HOME,      KC_LEFT,    KC_DOWN,        KC_RGHT,  KC_END,   LCTL(KC_L), \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    LCTL(KC_V),   KC_TRNS,        KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS, \
      KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_LCTL,      LCTL(KC_C),                   LCTL(KC_X), KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS), \
  */ \
  \
  /* ctrl - k layer */ \
  /*  
	[10] = LAYOUT_ortho_4x12(\
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO, \
      KC_NO,        KC_NO,    KC_DEL,     KC_DEL,     KC_BSPC,      KC_NO,          KC_NO,        KC_LCTL,    KC_NO,          LCTL(KC_L), KC_NO,  KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    LCTL(KC_SLSH), KC_NO, \
      KC_NO,        KC_NO,    KC_NO,      KC_NO,      KC_NO,        LCTL(KC_SPC),                 KC_NO,      KC_NO,          KC_NO,    KC_NO,    KC_NO) \
  */ \
  /* a might be a problem.  Keep hitting left instead of space, so no more left... Keep hitting tab instead of b, but making it b seems a bit much.  Going to try dropping it*/ \
	[0] = LAYOUT_ortho_4x12(\
      KC_Q,         KC_W,       KC_E,       KC_R,         KC_T,         XXXX,         XXXX,        KC_Y,         KC_U,       KC_I,         KC_O,     KC_P, \
      LT(4,KC_A),   LT(5,KC_S), LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G),   XXXX,         XXXX,        LSFT_T(KC_H), LT(8,KC_J), LT(10,KC_K),  KC_L,     KC_SCLN, \
      KC_Z,         KC_X,       KC_C,       KC_V,         LT(7,KC_B),   KC_NO,       KC_BSPC,      KC_N,         KC_M,       KC_COMM,      KC_DOT,   KC_SLSH,  \
      KC_LCTL,      KC_LGUI,    KC_LALT,    LT(1,KC_ENT), LT(1,KC_ENT), LT(6, KC_ESC), MO(2),      LSFT_T(KC_SPC),  LSFT_T(KC_SPC),   KC_DOWN,      KC_UP,    KC_RGHT), \
  /* lower  - things to find a space for KC_TILD, KC_PIPE KC_QUOT again*/ \
	[1] = LAYOUT_ortho_4x12(\
      KC_EXLM,      KC_AT,     KC_HASH,     KC_DLR,       KC_PERC,      XXXX,        XXXX,        KC_CIRC,      KC_AMPR,    KC_ASTR,      KC_DEL,  KC_BSPC,  \
      KC_F1,        KC_F2,     KC_F3,       KC_F4,        KC_F5,        XXXX,        XXXX,        KC_F6,        KC_UNDS,    KC_EQUAL,     KC_QUOT, LSFT(KC_QUOT), \
      KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,       KC_TAB,   KC_DEL,       KC_F12,       KC_MUTE,    KC_LT,        KC_GT,    KC_QUES,  \
      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_GRAVE,      MO(3),        KC_TRNS,  LALT(KC_LEFT),  KC_VOLD,  KC_VOLU,  LALT(KC_RGHT)), \
/* raise - KC_MPRV media previous*/ \
\
	[2] = LAYOUT_ortho_4x12(\
      KC_1,         KC_2,      KC_3,        KC_4,         KC_5,         XXXX,      XXXX,          KC_6,         KC_7,       KC_8,          KC_9,    KC_0, \
      KC_F1,        KC_F2,     KC_F3,       KC_F4,        KC_F5,        XXXX,      XXXX,          KC_F6,        KC_PMNS,    KC_EQUAL,      KC_QUOT, LSFT(KC_QUOT), \
      KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,       LSFT(KC_TAB),   KC_DEL,   KC_F12,       KC_MUTE,    KC_MPLY,     KC_PIPE, KC_BSLS,     \
      KC_TRNS,      KC_TRNS,   KC_TRNS,     MO(3),        KC_TRNS,      KC_TILD,    KC_TRNS,        KC_TRNS,      KC_MPLY,    KC_VOLD,       KC_VOLU, KC_MNXT), \
  /* adjust  - this is pretty much only reset  and c-a-d  pretty sure reset doesn't actually work  */  \
	[3] = LAYOUT_ortho_4x12(\
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,        XXXX,       XXXX,          KC_NO,        KC_NO,     KC_NO,        KC_NO,   RESET, \
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,        KC_NO,       KC_NO,          KC_NO,         KC_NO,    KC_NO,        KC_NO,   RESET, \
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,        KC_NO,       KC_NO,          KC_NO,         KC_NO,    KC_NO,        KC_NO,   KC_NO, \
      KC_NO,        KC_TRNS,   KC_NO,       KC_TRNS,      KC_TRNS,      LCA(KC_DEL), KC_TRNS,        KC_NO,         KC_NO,    KC_NO,        KC_NO,   KC_NO), \
  /* anne pro / desktop swap - dropped os-e shifted left and right  - a is not a great key to use.  Especially for alt-F4.  Moving that to k*/ \
	[4] = LAYOUT_ortho_4x12(\
      KC_NO, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)),    KC_NO, KC_NO, XXXX, XXXX,  KC_NO,        KC_NO,      KC_NO,        KC_NO,    KC_NO,\
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,          XXXX, XXXX, KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO, \
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO, KC_NO, KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,  \
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO, KC_NO, KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO ), \
  /* numbers */ \
	[5] = LAYOUT_ortho_4x12(\
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          XXXX,   XXXX,  KC_PAST,      KC_P7,      KC_P8,          KC_P9,    KC_PMNS,   \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          XXXX,   XXXX,  KC_NO,        KC_P4,      KC_P5,          KC_P6,    KC_PPLS,   \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,  KC_NO,  KC_NO,        KC_P1,      KC_P2,          KC_P3,    KC_TRNS,   \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,  KC_NO,  KC_P0,        KC_PDOT,    KC_NO,          KC_NO,    KC_NO     ),\
  /* mouse */ \
	[6] = LAYOUT_ortho_4x12(\
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,          XXXX,     XXXX,        KC_NO,       KC_WH_U,      KC_MS_U,        KC_WH_D,    KC_NO, \
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,          XXXX,     XXXX,        KC_NO,       KC_MS_L,    KC_MS_D,        KC_MS_R,  KC_NO, \
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,     KC_NO,      KC_NO,        KC_NO,    KC_NO, \
      KC_TRNS,    KC_NO,   KC_NO,      KC_TRNS,      KC_BTN1,        KC_NO,     KC_NO,        KC_BTN2,   KC_TRNS,    KC_NO,        KC_NO,    KC_NO),\
  /* brackets - g layer */ \
	[7] = LAYOUT_ortho_4x12(\
      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,        KC_NO,      KC_LBRC,        KC_RBRC,  KC_BSPC,     \
      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,        KC_LPRN,    KC_RPRN,        KC_LCBR,  KC_RCBR,   \
      KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,        KC_LBRC,    KC_RBRC,        KC_NO,    KC_NO,     \
      KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,          KC_NO,     KC_NO,        KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO   ), \
  /*  os nav - j layer */ \
	[8] = LAYOUT_ortho_4x12(\
      LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),     XXXX,     XXXX,   LGUI(KC_6),   LGUI(KC_7), LGUI(KC_8),     KC_NO,    KC_NO, \
      KC_NO,      KC_NO,      LGUI(KC_3), KC_NO,      KC_NO,          XXXX,     XXXX,   KC_NO,        KC_TRNS,    KC_LGUI,        LGUI(KC_L), KC_NO, \
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TAB,   KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_NO,    KC_NO, \
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,   KC_TRNS, LGUI(KC_SPC),      KC_TRNS,    KC_NO,          KC_NO,    KC_NO), \
  \
  /* nav - d layer - tab on q seems like a bit of a waste*/ \
	[9] = LAYOUT_ortho_4x12(\
      KC_TAB,  LCTL(KC_W), KC_TRNS,    LCTL(KC_R),   LCTL(KC_T),     XXXX,     XXXX,   KC_TRNS,      KC_PGUP,    KC_UP,          KC_PGDN,  KC_BSPC, \
      KC_ESC,  KC_DEL,     KC_TRNS,    KC_LSFT,      LCTL(KC_TAB),   XXXX,     XXXX,   KC_HOME,      KC_LEFT,    KC_DOWN,        KC_RGHT,  KC_END, \
      KC_TRNS,  KC_TRNS,    KC_TRNS,    LCTL(KC_V),   KC_TRNS,        KC_NO,     KC_NO,   KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS, \
      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_LCTL,      LCTL(KC_C),     LCTL(KC_C),   KC_TRNS, LCTL(KC_C), LCTL(KC_X),   KC_TRNS,        KC_TRNS,  KC_TRNS), \
  \
  /* ctrl - k layer */ \
	[10] = LAYOUT_ortho_4x12(\
      KC_TAB,    LSFT(KC_TAB), KC_TRNS, LALT(KC_F4),        KC_NO,         XXXX,    XXXX,       KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,  \
      KC_ESC,    KC_DEL,     KC_DEL,     KC_BSPC,      KC_NO,         XXXX,    XXXX,       KC_NO,        KC_LCTL,    KC_NO,          LCTL(KC_L), KC_NO, \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,         KC_TRNS, KC_TRNS,    KC_NO,        KC_NO,      KC_NO,          KC_NO,   LCTL(KC_SLSH), \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,         KC_TRNS, KC_TRNS,   KC_LALT,  KC_TRNS,    KC_TRNS,        KC_TRNS,  KC_TRNS) \

};


void matrix_scan_user(void) {
		return;
};

