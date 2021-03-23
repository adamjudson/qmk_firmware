#include QMK_KEYBOARD_H

enum custom_keycodes {
  JSARROW = SAFE_RANGE
};

// 0 base
// 1 lower
// 2 raise
// 3 adjust
// 4 ap2
// 5 numpad
// 6 game
// 7 brackets
// 8 os - j
// 9 nav - d
// 10 enter - k

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(4,KC_ESC), KC_A, LT(5,KC_S), LT(9,KC_D), LSFT_T(KC_F), LT(7,KC_G), LSFT_T(KC_H), LT(8,KC_J), LT(10,KC_K), KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LSFT_T(KC_BSLS), KC_LCTL, KC_LGUI, TG(6), KC_LALT, LT(1,KC_ENT), LSFT_T(KC_SPC), LSFT_T(KC_SPC), LT(2,KC_SPC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[1] = LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_LT, KC_GT, KC_QUES, KC_DQUO, KC_LCTL, KC_LGUI, MO(6), KC_LALT, KC_TRNS, KC_SPC, KC_SPC, MO(3), LALT(KC_LEFT), KC_VOLD, KC_VOLU, LALT(KC_RGHT)),
	[2] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_COMM, KC_DOT, KC_BSLS, KC_MFFD, KC_LCTL, KC_LGUI, MO(6), KC_LALT, MO(3), KC_SPC, KC_SPC, KC_TRNS, KC_MPLY, KC_VOLD, KC_VOLU, KC_MFFD),
	[3] = LAYOUT_ortho_4x12(KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_HUD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, LCA(KC_DEL), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT_ortho_4x12(KC_DEL, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), LGUI(KC_E), LALT(KC_F4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[5] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_DOT, KC_NO, KC_NO, KC_NO, KC_NO),
	[6] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LCTL, KC_NO, KC_TRNS, KC_LALT, KC_ENT, KC_ENT, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
	[7] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, JSARROW, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[8] = LAYOUT_ortho_4x12(KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, LGUI(KC_3), KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, KC_LGUI, LGUI(KC_L), KC_LALT, KC_NO, KC_NO, KC_TRNS, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[9] = LAYOUT_ortho_4x12(KC_NO, KC_NO, LCTL(KC_W), KC_NO, LCTL(KC_R), LCTL(KC_T), KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_BSPC, KC_NO, KC_BSPC, KC_DEL, KC_TRNS, KC_LSFT, LCTL(KC_TAB), KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, LCTL(KC_L), KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, JSARROW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, LCTL(KC_C), LCTL(KC_C), LCTL(KC_X), KC_NO, KC_NO, KC_NO, KC_NO),
	[10] = LAYOUT_ortho_4x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_R), LCTL(KC_T), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_BSPC, KC_DEL, KC_BSPC, LALT(KC_LEFT), KC_NO, KC_LCTL, KC_TRNS, LCTL(KC_L), KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

/*
const rgblight_segment_t PROGMEM lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GREEN}
);

const rgblight_segment_t PROGMEM raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM game[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(lower, raise, game);

*/
void keyboard_post_init_user(void) {
    // rgblight_sethsv_noeeprom(HSV_BLUE);
    // rgblight_layers = rgb_layers;
}

/* 
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 6));
    return state;
}
*/

void suspend_power_down_user(void) {
    // rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    // rgblight_enable();
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == JSARROW && record->event.pressed) {
    SEND_STRING("=>");
  }
  
  return true;
}

