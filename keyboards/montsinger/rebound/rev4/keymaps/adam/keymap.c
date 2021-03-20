#include QMK_KEYBOARD_H


// 0 base
// 1 lower
// 2 raise
// 3 adjust
// 4  esc - annepro2 - windows desdtop swap
// 5 s - numpad
// 6 gaming 
// 7 g - brackets
// 8 j - windows  key
// 9 d - nav - this should provalvy be lower...
// 10 k - ctrl key

// first row is missing the middle key
// last row has 2u space on both thumbs, so that's the 6th and 9th keys.  5th and 10th are no-ops

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(
    KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,         KC_T,                                 KC_Y,              KC_U,         KC_I,         KC_O,   KC_P,     KC_BSPC, 
    LT(4,KC_ESC),   KC_A,       LT(5,KC_S), LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G),            KC_LCTL,       LSFT_T(KC_H),      LT(8,KC_J),   LT(10,KC_K),  KC_L,   KC_SCLN,  KC_QUOT, 
    KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,         KC_B,                  LT(2,KC_SPC),  KC_N,              KC_M,         KC_COMM,      KC_DOT, KC_SLSH,  LSFT_T(KC_BSLS), 
    KC_LCTL,        KC_LGUI,    TG(6),      KC_LALT,    KC_NO,        LT(1,KC_ENT),       KC_MUTE,       LSFT_T(KC_SPC),    KC_NO,       KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT
    ),

	[1] = LAYOUT_all(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_TRNS,                KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
    KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,         MO(3),               KC_F12, KC_MUTE, KC_LT, KC_GT, KC_QUES, KC_DQUO, 
    KC_LCTL, KC_LGUI, MO(6), KC_LALT, KC_NO, KC_TRNS,     KC_MPLY,               KC_SPC, KC_NO, LALT(KC_LEFT), KC_VOLD, KC_VOLU, LALT(KC_RGHT)
    ),

	[2] = LAYOUT_all(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, 
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_TRNS,               KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, 
    KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,          KC_TRNS,               KC_F12, KC_MUTE, KC_COMM, KC_DOT, KC_BSLS, KC_MFFD, 
    KC_LCTL, KC_LGUI, MO(6), KC_LALT, KC_NO, KC_SPC,       KC_TRNS,               KC_SPC, KC_NO, KC_MPLY, KC_VOLD, KC_VOLU, KC_MFFD
    ),

	[3] = LAYOUT_all(
    KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_TRNS,                KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, RESET, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_TRNS,                KC_NO, RGB_MOD, RGB_HUI, RGB_HUD, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_TRNS,                LCA(KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[4] = LAYOUT_all(
    KC_DEL, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), LGUI(KC_E), LALT(KC_F4), KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, 
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_TRNS,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_TRNS,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_TRNS,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[5] = LAYOUT_all(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                         KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_NO, 
    KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO,                    KC_TRNS,                                   KC_PMNS, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_TRNS,                                   KC_DOT, KC_1, KC_2, KC_3, KC_SLSH, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_TRNS,                                  KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[6] = LAYOUT_all(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                      KC_TRNS,                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                          KC_TRNS,                                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, 
    KC_LCTL, KC_NO, KC_TRNS, KC_LALT, KC_NO, KC_ENT,                 KC_TRNS,                                 KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

	[7] = LAYOUT_all(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                         KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_TRNS,                          KC_NO, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_TRNS,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_TRNS,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[8] = LAYOUT_all(
    KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),                              LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_NO, KC_TRNS, KC_TRNS, LGUI(KC_3), KC_TRNS, KC_TAB,                   KC_TRNS,                          KC_TRNS, KC_TRNS, KC_LGUI, LGUI(KC_L), KC_NO, KC_NO, 
    KC_NO, KC_TRNS, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_TRNS, KC_NO,      KC_TRNS,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,                   KC_TRNS,                          KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[9] = LAYOUT_all(
    KC_NO, KC_NO, LCTL(KC_W), KC_NO, LCTL(KC_R), LCTL(KC_T),                                          KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_BSPC, 
    KC_NO, KC_BSPC, KC_DEL, KC_TRNS, KC_LSFT, LCTL(KC_TAB),                   KC_TRNS,                        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, LCTL(KC_L), 
    KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_V), KC_NO,                            LCTL(KC_X),                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL,                          KC_MFFD,                        LCTL(KC_C), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

	[10] = LAYOUT_all(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_R), LCTL(KC_T),                                       KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_TRNS, KC_BSPC, KC_DEL, KC_BSPC, KC_NO,                           KC_TRNS,                       KC_NO, KC_LCTL, KC_TRNS, LCTL(KC_L), KC_NO, KC_NO, 
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                          KC_TRNS,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_TRNS,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};


/*

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_COLEMAK] = LAYOUT_all(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   _______,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_DVORAK] = LAYOUT_all(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,             KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   _______,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   _______,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, _______,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_all(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_all(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] =  LAYOUT_all(
  _______, RESET,   _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

*/

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(S(KC_VOLD));
    } else {
      tap_code16(KC_VOLU);
    }
}
