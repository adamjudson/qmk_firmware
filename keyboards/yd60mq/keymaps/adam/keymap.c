#include QMK_KEYBOARD_H

#include "adam.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
        KC_ESC,       KC_1,    KC_2,          KC_3,       KC_4,         KC_5,          KC_6,              KC_7,         KC_8,          KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,
        KC_TAB,       KC_Q,    KC_W,          KC_E,       KC_R,         KC_T,          KC_Y,              KC_U,         KC_I,          KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(4,KC_ESC), KC_A,    LT(5,KC_S),    LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G),    LSFT_T(KC_H),      LT(8,KC_J),   LT(10,KC_K),   KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT,   _______,    KC_Z,          KC_X,       KC_C,         KC_V,          KC_B,              KC_N,         KC_M,          KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS), KC_UP,   LT(2, KC_PGUP),
        KC_LCTL,   KC_LGUI,    KC_LALT,                                 _______,       LSFT_T(KC_SPC),    _______,                              MO(1),   MO(2),   KC_LEFT,        KC_DOWN,  KC_RGHT
    ),
    // lower
	[1] = LAYOUT_all(
        KC_TILD, KC_F1,    KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,   _______,  KC_DEL,
        KC_TILD, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MUTE,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, TG(6),
        KC_TRNS, KC_TRNS,  KC_TRNS,                             _______,    KC_SPC,     _______,                           KC_TRNS,    MO(3), KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    // raise
	[2] = LAYOUT_all(
        KC_GRV, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, KC_DEL,
        KC_GRV, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, TG(6),
       KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_TRNS,     _______,                            MO(3),      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // adjust
	[3] = LAYOUT_all(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, RESET,
        KC_TRNS, RGB_TOG,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  RESET,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_TRNS,     _______,                            KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // esc - ap2
	[4] = LAYOUT_all(
        KC_TRNS, KC_TRNS,             KC_TRNS,              KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  _______, RESET,
        KC_TRNS, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), LGUI(KC_E), LALT(KC_F4),   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,
        KC_TRNS, KC_TRNS,             KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,             KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,             KC_TRNS,                           _______,      KC_TRNS,    _______,                            KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
    ),

    // s - numpad
	[5] = LAYOUT_all(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PAST,    KC_7,       KC_8,       KC_9,       KC_PMNS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_LGUI,    KC_TRNS,    KC_PMNS,    KC_4,       KC_5,       KC_6,       KC_PPLS,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_DOT,     KC_1,       KC_2,       KC_3,       KC_SLSH, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_0,       _______,                            KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),

    // 6 - game
	[6] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   TG(6),
        KC_LCTL, KC_NO,   KC_LALT,                   _______, LSFT_T(KC_SPC), _______,                    MO(1), TG(0), KC_LEFT, KC_DOWN, KC_RGHT
   ),

    // g - brackets
	[7] = AJ_LAYOUT(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    __AJ__G__u_p__,                                 KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    __AJ__G__h_semi__,                                          KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_TRNS,     _______,                            KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // j
	[8] = AJ_LAYOUT(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, KC_TRNS,
        KC_TRNS, __AJ__J__q_p__,                                                                                                       KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, __AJ__J__a_semi__,                                                                                                    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  __AJ__J__z_slash__,                                                                                                 KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_TRNS,     _______,                            KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // d - nav
	[9] = LAYOUT_all(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  _______, KC_TRNS,
        KC_TRNS, KC_TRNS,  LCTL(KC_W), KC_NO,      LCTL(KC_R),  LCTL(KC_T),    KC_NO,      KC_PGUP,    KC_UP,      KC_PGDN,    KC_NO,      KC_TRNS,    KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_DEL,     KC_TRNS,    KC_LSFT,     LCTL(KC_TAB),  KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,     KC_TRNS,    KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    LCTL(KC_C), LCTL(KC_V),  KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,        KC_LCTL,     _______,                          LCTL(KC_C),  LCTL(KC_X), KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // k - 
	[10] = AJ_LAYOUT(
        KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  _______, KC_TRNS,
        KC_TRNS, __AJ__K__q_p__,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, __AJ__K__a_semi_,    KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, _______,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            _______,    KC_ENT,     _______,                            KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),


};


