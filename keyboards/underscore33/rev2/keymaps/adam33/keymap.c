/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// probably don't need this
enum custom_keycodes{
  RGBRST = SAFE_RANGE,
  JSARROW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
  [_BASE] = LAYOUT_33_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
   KC_GA,  KC_AS,  KC_CD,  KC_SF,   KC_G,   KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_GSCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LCTL, KC_LALT, KC_NAV_ENT, KC_NUM_SPC, KC_RGUI, KC_RCTL
  ),

  [_NUM_SYM] = LAYOUT_33_split_space(
       KC_1,     KC_2,     KC_3,     KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL,  KC_MINS,
    KC_BSLS,  KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_GRV,
                  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

  [_NAV] = LAYOUT_33_split_space(
      RESET,   RGBRST,  AG_NORM,  AG_SWAP,  DEBUG,   KC_GRV,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,  KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
                   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

  */

 // need to find a spot for tilda and back quote
 // might be time to start dropping numbers from raise?

 // suspect there are issues with alt-tab and gui-tab

  /* a might be a problem.  Keep hitting left instead of space, so no more left... Keep hitting tab instead of b, but making it b seems a bit much.  Going to try dropping it*/ \
	[0] = LAYOUT_33_split_space(\
      KC_Q,         KC_W,       KC_E,       KC_R,         KC_T,              KC_Y,         KC_U,       KC_I,         KC_O,     KC_P, \
      LT(4,KC_A),   LT(5,KC_S), LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G),        LSFT_T(KC_H), LT(8,KC_J), LT(10,KC_K),  KC_L,     KC_SCLN, \
      KC_Z,         KC_X,       KC_C,       KC_V,         LT(7,KC_B),        KC_N,         KC_M,       KC_COMM,      KC_DOT,   KC_SLSH,  \
                        KC_LCTL,      KC_LGUI,   LT(1,KC_ENT),   LSFT_T(KC_SPC),   MO(2),    KC_ESC             ), \
  /* lower  - things to find a space for KC_TILD, KC_PIPE KC_QUOT again*/ \
	[1] = LAYOUT_33_split_space(\
      KC_EXLM,      KC_AT,     KC_HASH,     KC_DLR,       KC_PERC,        KC_CIRC,      KC_AMPR,    KC_ASTR,      KC_DEL,  KC_BSPC,  \
      KC_F1,        KC_F2,     KC_F3,       KC_F4,        KC_F5,          KC_F6,        KC_UNDS,    KC_EQUAL,     KC_QUOT, LSFT(KC_QUOT), \
      KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,         KC_F12,       KC_MUTE,    KC_LT,        KC_GT,    KC_QUES,  \
                         KC_TRNS,   KC_TRNS,     KC_TRNS,         LALT(KC_LEFT),  MO(3),         LALT(KC_RGHT)), \
/* raise - KC_MPRV media previous*/ \
\
	[2] = LAYOUT_33_split_space(\
      KC_1,         KC_2,      KC_3,        KC_4,         KC_5,            KC_6,         KC_7,       KC_8,          KC_9,    KC_0, \
      KC_F1,        KC_F2,     KC_F3,       KC_F4,        KC_F5,           KC_F6,        KC_PMNS,    KC_EQUAL,      KC_QUOT, LSFT(KC_QUOT), \
      KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,          KC_F12,       KC_MUTE,    KC_MPLY,     KC_PIPE, KC_BSLS,     \
                           KC_GRAVE, KC_TILD,     MO(3),              KC_VOLD,      KC_TRNS,     KC_VOLU), \
  /* adjust  - this is pretty much only reset  and c-a-d  */  \
	[3] = LAYOUT_33_split_space(\
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,             KC_NO,        KC_NO,     KC_NO,        KC_NO,   RESET, \
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,                 KC_NO,         KC_NO,    KC_NO,        KC_NO,   RESET, \
      KC_NO,        KC_NO,     KC_NO,       KC_NO,        KC_NO,                 KC_NO,         KC_NO,    KC_NO,        KC_NO,   KC_NO, \
                                 KC_TRNS,      KC_TRNS,      KC_TRNS,      LCA(KC_DEL),         KC_TRNS,   KC_NO), \
  /* anne pro / desktop swap - dropped os-e shifted left and right  - a is not a great key to use.  Especially for alt-F4.  Moving that to k*/ \
	[4] = LAYOUT_33_split_space(\
      KC_NO, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)),    KC_NO, KC_NO,   KC_NO,        KC_NO,      KC_NO,        KC_NO,    KC_NO,\
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,           KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO, \
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,          KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,  \
                      KC_NO,        KC_NO,      KC_NO,            KC_NO,          KC_NO,    KC_NO ), \
  /* numbers - think about 0 and 1 ?*/ \
	[5] = LAYOUT_33_split_space(\
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,           KC_PAST,      KC_P7,      KC_P8,          KC_P9,    KC_PMNS,   \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,           KC_PMNS,      KC_P4,      KC_P5,          KC_P6,    KC_PPLS,   \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,           KC_PDOT,      KC_P1,      KC_P2,          KC_P3,    KC_TRNS,   \
                          KC_NO,    KC_NO,            KC_TRNS,         KC_P0,             KC_NO,    KC_NO     ),\
  /* mouse - again, not sure if we can get here*/ \
	[6] = LAYOUT_33_split_space(\
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,              KC_NO,       KC_WH_U,      KC_MS_U,        KC_WH_D,    KC_NO, \
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,              KC_NO,       KC_MS_L,    KC_MS_D,        KC_MS_R,  KC_NO, \
      KC_NO,      KC_NO,   KC_NO,      KC_NO,        KC_NO,              KC_NO,     KC_NO,      KC_NO,        KC_NO,    KC_NO, \
      KC_TRNS,    KC_NO,        KC_BTN1,            KC_BTN2,   KC_TRNS,    KC_NO),\
  /* brackets - g layer */ \
	[7] = LAYOUT_33_split_space(\
      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,                KC_NO,        KC_NO,      KC_LBRC,        KC_RBRC,  KC_BSPC,     \
      KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,                JSARROW,      KC_LPRN,    KC_RPRN,        KC_LCBR,  KC_RCBR,   \
      KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,                KC_NO,        KC_LBRC,    KC_RBRC,        KC_NO,    KC_NO,     \
                            KC_TRNS,  KC_TRNS,           KC_TRNS,      KC_TRNS,          KC_TRNS,    KC_TRNS   ), \
  /*  os nav - j layer */ \
	[8] = LAYOUT_33_split_space(\
      LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),      LGUI(KC_6),   LGUI(KC_7), LGUI(KC_8),     KC_NO,    KC_NO, \
      KC_NO,      KC_NO,      LGUI(KC_3), KC_NO,      KC_TAB,           KC_NO,        KC_TRNS,    KC_LGUI,        LGUI(KC_L), KC_LALT, \
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_NO,    KC_NO, \
                    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_NO), \
  \
  /* nav - d layer - tab on q seems like a bit of a waste*/ \
	[9] = LAYOUT_33_split_space(\
      KC_TAB,  LCTL(KC_W), KC_TRNS,    LCTL(KC_R),   LCTL(KC_T),       KC_TRNS,      KC_PGUP,    KC_UP,          KC_PGDN,  KC_BSPC, \
      KC_ESC,  KC_DEL,     KC_TRNS,    KC_LSFT,      LCTL(KC_TAB),     KC_HOME,      KC_LEFT,    KC_DOWN,        KC_RGHT,  KC_END, \
      KC_TRNS,  KC_TRNS,    KC_TRNS,    LCTL(KC_V),   KC_TRNS,         KC_TRNS,      KC_TRNS,    KC_TRNS,        JSARROW,  KC_TRNS, \
                    KC_TRNS,    KC_TRNS,    KC_LCTL,      LCTL(KC_C),     LCTL(KC_X),    KC_TRNS), \
  \
  /* ctrl - k layer */ \
	[10] = LAYOUT_33_split_space(\
      KC_TAB,    LSFT(KC_TAB), KC_TRNS, LALT(KC_F4),        KC_NO,        KC_NO,        KC_NO,      KC_NO,          KC_NO,    KC_NO,  \
      KC_ESC,    KC_DEL,     KC_DEL,     KC_BSPC,    LALT(KC_LEFT),       KC_NO,        KC_LCTL,    KC_NO,          LCTL(KC_L), KC_NO, \
      KC_NO,    KC_NO,      KC_NO,      KC_NO,        KC_NO,            KC_NO,        KC_NO,      KC_NO,          KC_NO,   LCTL(KC_SLSH), \
                   KC_NO,      KC_NO,      KC_NO,             KC_LALT,  KC_TRNS,    KC_TRNS) \

};


// this is kind of cool

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
 COMBO(combo_bspc,KC_BSPC),
 COMBO(combo_tab,KC_TAB),
 COMBO(combo_esc,KC_ESC)
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == JSARROW && record->event.pressed) {
    SEND_STRING("=>");
  }
  
  return true;
}

