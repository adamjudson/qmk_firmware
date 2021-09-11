#include QMK_KEYBOARD_H


// 12
// 11
// 11
// 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ansi_split_space(
        KC_TAB,         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
        LT(10,KC_ESC),  KC_A, LT(3,KC_S), LT(4,KC_D), LSFT_T(KC_F), LT(6,KC_G), LSFT_T(KC_H), LT(7,KC_J), LT(8,KC_K), KC_L, KC_SCLN, 
        KC_LSFT,        KC_Z, KC_X, KC_C, LT(9,KC_V), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
        KC_LCTL,        KC_LGUI, KC_LALT, LT(1,KC_ENT), LT(2,KC_SPC), LSFT_T(KC_SPC), KC_DOWN, KC_UP, KC_QUOT
    ),
	[1] = LAYOUT_ansi_split_space(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PMNS, KC_PEQL, KC_BSLS, KC_QUOT, 
        KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_LT, KC_GT, KC_DQUO, 
        KC_NO, KC_NO, KC_NO, KC_TRNS, MO(5), KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),
	[2] = LAYOUT_ansi_split_space(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, 
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PEQL, KC_PIPE, KC_QUOT, 
        KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_LT, KC_GT, KC_DQUO, 
        KC_NO, KC_NO, KC_NO, MO(5), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    // numbers - note dropped 'P' in main because numpad is bad in linux
	[3] = LAYOUT_ansi_split_space(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PAST, KC_BSPC, 
        KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_SLSH, 
        KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_P0, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT_ansi_split_space(
        KC_NO, KC_NO, LCTL(KC_W), KC_NO, LCTL(KC_R), LCTL(KC_T), KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_BSPC, 
        KC_NO, KC_BSPC, KC_DEL, KC_TRNS, KC_LSFT, LCTL(KC_T), KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, 
        KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_LCTL, KC_LGUI, LCTL(KC_C), LCTL(KC_X), KC_NO, KC_NO
    ),
	[5] = LAYOUT_ansi_split_space(
        KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_F4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, LCA(KC_DEL), KC_NO, KC_NO, KC_NO
    ),
	[6] = LAYOUT_ansi_split_space(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_MINS, KC_GT, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
	[7] = LAYOUT_ansi_split_space(
        LGUI(KC_TAB), LGUI(KC_P1), LGUI(KC_W), LGUI(KC_E), LGUI(KC_P4), LGUI(KC_P5), LGUI(KC_P6), LGUI(KC_P7), LGUI(KC_P8), LGUI(KC_P9), LGUI(KC_O), KC_NO, 
        LGUI(KC_ESC), LGUI(KC_A), LGUI(KC_S), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LGUI, LGUI(KC_L), KC_NO, 
        KC_NO, KC_NO, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_SPC), KC_NO, KC_NO, KC_NO
    ),
	[8] = LAYOUT_ansi_split_space(
        LCTL(KC_TAB), LCTL(KC_Q), LCTL(KC_W), LCTL(KC_E), LCTL(KC_R), LCTL(KC_T), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        LCTL(KC_ESC), KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_TRNS, LCTL(KC_L), KC_NO, 
        KC_NO, KC_NO, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
	[9] = LAYOUT_ansi_split_space(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO
    ),
	[10] = LAYOUT_ansi_split_space(
        KC_DEL, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};
