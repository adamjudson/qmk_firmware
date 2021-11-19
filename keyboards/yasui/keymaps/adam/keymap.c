
#include QMK_KEYBOARD_H

#include "adam.h"

// I only have 8 keys on the bottom row, so middle two are KC_NO

// H as shift is causing issues - not really clear why it's happenning only on this keyboard though
// but I don't really use that shift, so taking it out for now
// LSFT_T(KC_H) => KC_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0 - base */
	LAYOUT(
        KC_Q,         KC_W,       KC_E,       KC_R,         KC_T,              KC_Y,         KC_U,       KC_I,         KC_O,    KC_P, 
        LT(4,KC_A),   LT(5,KC_S), LT(8,KC_D), LSFT_T(KC_F), LT(6,KC_G),      SFT_T(KC_H),   LT(7,KC_J), LT(9,KC_K),  KC_L,     KC_SCLN, 
      MT(MOD_LCTL, KC_Z),    MT(MOD_LALT, KC_X),       KC_C,       KC_V,         KC_B,              KC_N,         KC_M,       KC_COMM,      KC_DOT,   MT(MOD_LGUI, KC_SLSH),  
        KC_LCTL,      KC_LGUI,    KC_LALT,  LT(1,KC_ENT),   KC_NO,             KC_NO,     LSFT_T(KC_SPC),   MO(2),    KC_ESC,   KC_BSPC   
    ), 
    /* 1 - lower */
    // kept hitting F6 when I want underscore...
	LAYOUT(
        KC_EXLM,      KC_AT,     KC_HASH,     KC_DLR,       KC_PERC,        KC_CIRC,      KC_AMPR,    KC_ASTR,      KC_DEL,  KC_BSPC,  
        KC_F1,        KC_F2,     KC_F3,       KC_F4,        TD(TD_F5_F6),   KC_UNDS,      KC_UNDS,    KC_EQUAL,     KC_QUOT, LSFT(KC_QUOT), 
        KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,         KC_F12,       KC_MUTE,    KC_LT,        KC_PIPE,  KC_BSLS, 
        KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,      KC_NO,          KC_NO,        KC_TRNS,    MO(3),        KC_GRAVE, KC_TILD
    ), 
    /* 2 - raise - try to avoid putting anything important here */
	LAYOUT(
        KC_GRAVE,     KC_TILD,   KC_3,        LALT(KC_F4),   KC_5,           KC_6,         KC_7,       KC_VOLD,       KC_VOLU,    TD(TD_MEDIA), 
        KC_F1,        KC_F2,     KC_F3,       KC_F4,        KC_F5,           KC_F6,        KC_MINS,    KC_EQUAL,      KC_UP, LSFT(KC_QUOT), 
        KC_F7,        KC_F8,     KC_F9,       KC_F10,       KC_F11,          KC_F12,       KC_MUTE,    KC_LEFT,      KC_DOWN, KC_RIGHT,     
        KC_TRNS,      KC_TRNS,   KC_TRNS,     MO(3),        KC_NO,           KC_NO,        KC_TRNS,    KC_TRNS,      KC_VOLD,    KC_VOLU
    ), 
    /* 3 - adjust  - this is pretty much only reset  and c-a-d  */ 
	LAYOUT(
        DYN_REC_START1, DYN_MACRO_PLAY1,  KC_NO,       KC_NO,        KC_NO,             KC_NO,        KC_NO,    KC_NO,        KC_NO,   RESET, 
        DYN_REC_STOP,        TG(5),       KC_NO,       KC_NO,        KC_NO,             KC_NO,        RGB_TOG,  RGB_VAI,      RGB_VAD, RESET, 
        KC_NO,                 KC_NO,     KC_NO,       KC_NO,        KC_NO,             KC_NO,        RGB_MOD,  RGB_HUI,      RGB_HUD, KC_NO, 
        KC_NO,                 KC_NO,     KC_NO,       KC_TRNS,      KC_NO,             KC_NO,    LCA(KC_DEL),  KC_TRNS,      KC_NO,   KC_NO
    ), 
    /* 4 - anne pro / desktop swap - dropped os-e shifted left and right  - a is not a great key to use.  Especially for alt-F4.  Moving that to k*/ 
    /* MO on s is questionable - triggering when I don't want sometimes */
	LAYOUT(
        KC_TAB, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)),   KC_TRNS,      KC_NO,   KC_NO,        KC_NO,      KC_NO,    KC_NO,    RESET, 
        KC_NO,  MO(1),               MO(2),                  KC_ESC,       KC_NO,   KC_NO,        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_NO,  KC_NO,                KC_NO,                 KC_NO,        KC_NO,   KC_NO,        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  
        KC_NO,  KC_NO,                KC_NO,                 KC_NO,        KC_NO,   KC_NO,        KC_NO,      KC_NO,    KC_VOLD,    KC_VOLU 
    ), 
    /* 5 - s numbers - and tab I guess */ 
	LAYOUT(
        KC_NO,              KC_NO,      KC_TRNS,      KC_NO,        KC_NO,         KC_PAST,      KC_7,      KC_8,           KC_9,    KC_MINS,  
        OSM(MOD_LGUI),      TG(5),      KC_TAB,     KC_TRNS,      KC_UNDS,       KC_MINS,      KC_4,      KC_5,           KC_6,    KC_PLUS,   
        KC_NO,              KC_NO,      KC_NO,      KC_LGUI,      KC_NO,         KC_PDOT,      KC_1,      KC_2,           KC_3,    KC_TRNS,
        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_LCTL,      KC_NO,         KC_NO,        KC_0,      KC_TRNS,        KC_NO,    KC_NO     
    ),
    /* 6 - g brackets */ 
	LAYOUT(
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,                KC_NO,        ARRAY,      KC_LBRC,        KC_RBRC,  ARRAY_INSIDE,   
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_BSPC,      KC_NO,                JSARROW,      KC_LPRN,    KC_RPRN,        KC_LCBR,  KC_RCBR,   
        KC_TRNS,  KC_TRNS,    KC_NO,      KC_NO,        KC_NO,                KC_NO,        KC_LT,      KC_GT,          END_TAG,  KC_GT,     
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_NO,        KC_NO,                KC_NO,        KC_TRNS,    KC_NO,          KC_NO,    KC_NO   
    ), 
    /* 7 - j  os nav */ 
	LAYOUT(
        LGUI(KC_1),    LGUI(KC_2), LGUI(KC_E), LGUI(KC_4), LGUI(KC_5),      LGUI(KC_6),   LGUI(KC_7), LGUI(KC_8),     KC_NO,    KC_BSPC, 
        OSM(MOD_LCTL), KC_TRNS,    KC_TRNS,    LCTL(KC_F),  KC_TAB,         KC_NO,        KC_TRNS,    KC_LGUI,        LGUI(KC_L), KC_LALT, 
        KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,         KC_TRNS,      KC_TRNS,    KC_TRNS,        KC_NO,    KC_NO, 
        KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_BSPC,    KC_NO,           KC_NO,        KC_TRNS,    KC_NO,          KC_NO,    KC_NO
    ), 
    /* 8 - d nav */ 
	LAYOUT(
        KC_TRNS,  LCTL(KC_W), KC_TRNS,    LCTL(KC_R),   LCTL(KC_T),       KC_TRNS,      KC_PGUP,     KC_UP,         KC_PGDN,            KC_BSPC, 
        KC_ESC,   KC_DEL,     KC_TRNS,    KC_LSFT,      LCTL(KC_TAB),     KC_HOME,      KC_LEFT,     KC_DOWN,       KC_RGHT,            KC_END, 
        KC_TRNS,  LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),   KC_TRNS,          KC_TRNS,      LCTL(KC_U),  KC_BSPC,       LCTL(LSFT(KC_U)),   LCTL(KC_SLSH), 
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_LCTL,      KC_NO,            KC_NO,        LCTL(KC_C),  LCTL(KC_X),    LCTL(KC_U),         LCTL(LSFT(KC_U))
    ), 
    /* 9 - k ctrl */ 
	LAYOUT(
      KC_TAB,    LSFT(KC_TAB), KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,  
      KC_ESC,    KC_TRNS,     KC_BSPC,     KC_BSPC,      LALT(KC_LEFT),     KC_TRNS,    KC_LCTL,    KC_NO,     LCTL(KC_L), OSM(MOD_LALT), 
      KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_NO,           KC_TRNS,     KC_NO,      KC_NO,     KC_NO,      LCTL(KC_SLSH), 
      KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_BSPC,      KC_NO,             KC_NO,      KC_TRNS,    KC_NO,     KC_TRNS,    KC_TRNS
    ) 
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_cut[]  = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_cutt[] = {MT(MOD_LCTL, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combo_bslash[] = {KC_DOT, MT(MOD_LGUI, KC_SLSH), COMBO_END};

const uint16_t PROGMEM combo_copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[]        = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_bspc[]         = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[]          = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_single_quote[] = {KC_L, KC_SCLN, COMBO_END};
// this doesn't seem to work - probably because f is already overloaded?
// const uint16_t PROGMEM combo_another_bspc[] = {KC_F, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};

enum combo_events { ZX_CUT, ZX_CUTT, XC_COPY, CV_PASTE, DOTSLASH_BSLASH };

combo_t key_combos[COMBO_COUNT] = {
    [ZX_CUT] = COMBO_ACTION(combo_cut), 
    [ZX_CUTT] = COMBO_ACTION(combo_cutt), 
    [XC_COPY] = COMBO_ACTION(combo_copy), 
    [CV_PASTE] = COMBO_ACTION(combo_paste), 
    [DOTSLASH_BSLASH] = COMBO_ACTION(combo_bslash),
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
        case ZX_CUTT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
        case DOTSLASH_BSLASH:
            if (pressed) {
                tap_code16(KC_BSLASH);
            }
            break;
    }
}
#endif
