#ifndef USERSPACE
#define USERSPACE


#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

void my_custom_function(void);

enum custom_keycodes {
  JSARROW = SAFE_RANGE,
  NEW_SAFE_RANGE
};


// defines for common rows

// KEYCODE GROUPS ======================================================================
// MISC 
#define ______TRANS______    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define ____NUMROW_L0____    KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define ____NUMROW_R0____    KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define _____BASE_L4_____    K41,      K42,      K43,      K44,      K45
#define _____BASE_R4_____    K46,      K47,      K48,      K49,      K4A

/* QWERTY ==============================================================================
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NAV  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | SHFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | C/S  | LGUI | LALT | SYMB |  NUM/SPACE  | SYMB | RALT | SETT | MUTG | LEAD |
 * `-----------------------------------------------------------------------------------'
 */

// LEFT
// - CORE
#define ____QWERTY_L1____    KC_Q,   KC_W,   KC_E,     KC_R,    KC_T
#define ____QWERTY_L2____    KC_A,   KC_S,   KC_D,     KC_F,    KC_G
#define ____QWERTY_L3____    KC_Z,   KC_X,   KC_C,     KC_V,    KC_B

// RIGHT
// - CORE
#define ____QWERTY_R1____    KC_Y,   KC_U,   KC_I,     KC_O,    KC_P
#define ____QWERTY_R2____    KC_H,   KC_J,   KC_K,     KC_L,    KC_SCLN
#define ____QWERTY_R3____    KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH

/* NUMPAD ==============================================================================
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |  F9  |  F10 |  F11 |  F12 |      | NLCK |   7  |   8  |   9  |   -  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |  F5  |  F6  |  F7  |  F8  | SPC  | SPC  |   4  |   5  |   6  |   +  | ENTR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |  F1  |  F2  |  F3  |  F4  | ALT  |      |   1  |   2  |   3  |   /  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     |   0  |   ,  |   .  |   *  | TRNS |
 * `-----------------------------------------------------------------------------------'
 */

// LEFT
// - CORE
#define ____NUMPAD_L1____    KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_NO
#define ____NUMPAD_L2____    KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_SPC
#define ____NUMPAD_L3____    KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_LALT


// my stuff
// J
#define __AJ__J__q_p__  LGUI(KC_1), LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),  LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), KC_TRNS, LGUI(KC_P)
#define __AJ__J__a_semi__  KC_TRNS, KC_TRNS, LGUI(KC_3), KC_TRNS, KC_TAB,  KC_TRNS, KC_TRNS, KC_LGUI, LGUI(KC_L), KC_LALT
#define __AJ__J__z_slash__ KC_TRNS, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO

// K
#define __AJ__K__q_p__ KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_R), LCTL(KC_T),  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
#define __AJ__K__a_semi_ KC_TRNS, KC_BSPC, KC_DEL, KC_BSPC, LALT(KC_LEFT), KC_NO, KC_LCTL, KC_TRNS, LCTL(KC_L), KC_NO

// G - Brackets 
#define __AJ__G__u_p__ KC_NO, KC_LBRC, KC_RBRC, KC_NO
#define __AJ__G__h_semi__ JSARROW, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR



#define AJ_LAYOUT(...) LAYOUT_all(__VA_ARGS__)

#endif