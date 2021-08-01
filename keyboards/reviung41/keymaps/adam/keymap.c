/* Copyright 2020 gtips
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

#include "adam.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_reviung41(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,      
    LT(4,KC_ESCAPE),KC_A,           LT(5,KC_S),     LT(8,KC_D),     LSFT_T(KC_F),   LT(6,KC_G),     LSFT_T(KC_H),   LT(7,KC_J),     LT(9,KC_K),    KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LCTRL,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       RSFT_T(KC_BSLASH),
                                                   KC_LGUI,   LT(1,KC_ENTER),    KC_LALT,   LSFT_T(KC_SPACE),    MO(2)
  ),

  [1] = LAYOUT_reviung41(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,      
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_UNDS,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_PIPE,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_AUDIO_MUTE,  KC_LABK,        KC_RABK,        KC_QUES,        KC_DQUO,        
                                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(3)
  ),

  [2] = LAYOUT_reviung41(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_MEDIA_PLAY_PAUSE,   KC_TRNS,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_MINUS,       KC_EQUAL,       KC_LBRACKET,    KC_UP,                 KC_BSLASH,      
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_LEFT,       KC_DOWN,               KC_RIGHT,
                                                    KC_TRNS,                MO(3),   KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP, KC_TRNS
  ),

  [3] = LAYOUT_reviung41(
    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,          KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,    
    KC_TRNS,    KC_TRANSPARENT, KC_TRNS,        KC_TRNS,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS,        RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RESET,          
    KC_TRNS,    KC_TRANSPARENT, KC_TRNS,        KC_TRNS,          KC_TRNS,        KC_TRANSPARENT, KC_TRNS,        RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                KC_TRNS,   KC_TRNS,    KC_TRNS,  LCA(KC_DEL),     KC_TRANSPARENT
  ),

  // ap2
  [4] = LAYOUT_reviung41(
    KC_TRANSPARENT, LCTL(LGUI(KC_LEFT)),LCTL(LGUI(KC_RIGHT)),KC_TRANSPARENT, LALT(KC_F4),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    KC_TRANSPARENT, MO(1),          MO(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS
  ),
 
  // S - numbers
  [5] = LAYOUT_reviung41(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_ASTERISK, KC_7,           KC_8,           KC_9,           KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRNS,        KC_ESC,        KC_TRANSPARENT,  KC_TAB,         KC_TRANSPARENT, KC_UNDERSCORE, KC_MINUS,       KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_EQUAL,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI, KC_TRANSPARENT, KC_DOT,        KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRNS,   KC_LCTRL,    KC_DOT,   KC_0,    KC_TRNS
  ),

  //  g - brackets
  [6] = LAYOUT_reviung41(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ARRAY,     KC_LBRACKET,    KC_RBRACKET,    ARRAY_INSIDE,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     KC_TRANSPARENT, JSARROW,     KC_LPRN,        KC_RPRN,        KC_LCBR,        KC_RCBR,        BRACKETS,     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        END_TAG,     KC_TRANSPARENT, KC_TRANSPARENT, 
                                            KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS
  ),

  // J - launch
  [7] = LAYOUT_reviung41(
    KC_TRANSPARENT, LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_E),     LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     LGUI(KC_7),     LGUI(KC_8),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LCTL),  KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_F),     KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        LGUI(KC_L),     KC_LALT,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                            KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS
  ),

  // D - nav
  [8] = LAYOUT_reviung41(
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_W),     KC_TRANSPARENT, LCTL(KC_R),     LCTL(KC_T),     KC_TRANSPARENT, KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESC,         KC_DELETE,      KC_TRANSPARENT, KC_LSHIFT,      LCTL(KC_TAB),   KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         LCTL(KC_L),     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_V),     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_U), KC_TRANSPARENT,     LSFT(LCTL(KC_U) ),     LCTL(KC_SLASH), KC_TRANSPARENT, 
                                            KC_TRNS,   KC_LCTL,    LCTL(KC_C),   LCTL(KC_C),      LCTL(KC_X)
  ),

  // K 
  [9] = LAYOUT_reviung41(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESC,         KC_TRANSPARENT, KC_BSPC,        KC_BSPC,        LALT(KC_LEFT),  KC_TRANSPARENT, KC_LCTRL,       KC_TRANSPARENT, LCTL(KC_L),     OSM(MOD_LALT),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_SLASH), KC_TRANSPARENT, 
                                            KC_TRNS,   KC_TRNS,    KC_TRNS,   LCTL(KC_SPACE),    KC_TRNS
  )

};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_cut[]          = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[]        = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_bspc[]         = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[]          = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_single_quote[] = {KC_L, KC_SCLN, COMBO_END};
// this doesn't seem to work - probably because f is already overloaded?
// const uint16_t PROGMEM combo_another_bspc[] = {KC_F, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};

enum combo_events { ZX_CUT, XC_COPY, CV_PASTE };

combo_t key_combos[COMBO_COUNT] = {
    [ZX_CUT] = COMBO_ACTION(combo_cut),
    [XC_COPY] = COMBO_ACTION(combo_copy),
    [CV_PASTE] = COMBO_ACTION(combo_paste),
    COMBO(combo_bspc, KC_BSPC), 
    COMBO(combo_tab, KC_TAB), 
    COMBO(combo_single_quote, KC_QUOTE), 
};

// note that that this is using the index into key_combos, which is assumed to be the enum
// not clear if we can acutally mix enums and the combo macro...
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CV_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case XC_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
        case ZX_CUT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
    }
}
#endif

