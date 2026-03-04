#include "adam.h"

void my_custom_function(void) {
    
}

bool process_record_adam(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    if (keycode == JSARROW && record->event.pressed) {
        SEND_STRING("=>");
    } else if (keycode == BRACKETS && record->event.pressed) {
        SEND_STRING("() ");
    } else if (keycode == ARRAY && record->event.pressed) {
        SEND_STRING("[] ");
    } else if (keycode == ARRAY_INSIDE && record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
    } else if (keycode == END_TAG && record->event.pressed) {
        SEND_STRING("</");
    } else if (keycode == CLOSE_TAG && record->event.pressed) {
        SEND_STRING("/>");
    }

    if (keycode == KC_MS_BTN1 || keycode == KC_MS_BTN2 || keycode == KC_MS_BTN3) {
        // by default mouse keys don't clear OSM
        // that's pretty annoying.
        clear_oneshot_mods();
    }
    return process_record_adam(keycode, record);
}



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(4)) {
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}



#ifdef COMBO_ENABLE
// const uint16_t PROGMEM combo_cut[] = {KC_Z, KC_X, COMBO_END};
// this was hard to type with - got triggered all the time
// const uint16_t PROGMEM combo_esc[] = {KC_W, KC_E, COMBO_END};

// c-v for paste can be annoying on not ortho - so add a define to drop it - NO_PASTE_COMBO
// kind of an ugly implementation though...

const uint16_t PROGMEM combo_cutt[] = {MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), COMBO_END};
const uint16_t PROGMEM combo_bslash[] = {KC_DOT, MT(MOD_LGUI, KC_SLSH), COMBO_END};

const uint16_t PROGMEM combo_copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_copyy[]        = {MT(MOD_LALT, KC_X), KC_C, COMBO_END};
const uint16_t PROGMEM combo_bspc[]         = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[]          = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_single_quote[] = {KC_L, LT(5, KC_SCLN), COMBO_END};

#ifndef NO_PASTE_COMBO
const uint16_t PROGMEM combo_paste[]        = {KC_C, KC_V, COMBO_END};
#endif

// this doesn't seem to work - probably because f is already overloaded?
// const uint16_t PROGMEM combo_another_bspc[] = {KC_F, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};

// enum combo_events { ZX_CUT, ZX_CUTT, XC_COPY, XC_COPYY, CV_PASTE, DOTSLASH_BSLASH };
enum combo_events { ZX_CUTT, XC_COPY, XC_COPYY, 
#ifndef NO_PASTE_COMBO
    CV_PASTE, 
#endif
    DOTSLASH_BSLASH };
// don't think this worked when combo_esc was at the beginning
combo_t key_combos[COMBO_COUNT] = {
//     [ZX_CUT] = COMBO_ACTION(combo_cut),
    // QWE_ESC] = COMBO_ACTION(combo_esc),
    [ZX_CUTT] = COMBO_ACTION(combo_cutt),
    [XC_COPY] = COMBO_ACTION(combo_copy),
    [XC_COPYY] = COMBO_ACTION(combo_copyy),
#ifndef NO_PASTE_COMBO
    [CV_PASTE] = COMBO_ACTION(combo_paste),
#endif
    [DOTSLASH_BSLASH] = COMBO_ACTION(combo_bslash),
    // COMBO(combo_esc, KC_ESC),
    COMBO(combo_bspc, KC_BSPC), 
    COMBO(combo_tab, KC_TAB), 
    COMBO(combo_single_quote, KC_QUOTE), 
};

// note that that this is using the index into key_combos, which is assumed to be the enum
// anything that's not a simple keypress needs to be here
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
#ifndef NO_PASTE_COMBO
        case CV_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
#endif
        case XC_COPY:
        case XC_COPYY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
//         case ZX_CUT:
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



#ifdef TAP_DANCE_ENABLE

void dance_media(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code(KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance(state);
    }
}

void dance_volume(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_VOLD);
    } else if (state->count == 2) {
        tap_code(KC_VOLU);
    } else if (state->count == 3) {
        tap_code(KC_MUTE);
    } else {
        reset_tap_dance(state);
    }
}

// tap dance stuff
qk_tap_dance_action_t tap_dance_actions[] = {
    // ctrl and then gui/win
    [TD_CTRL_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
    [TD_MEDIA]    = ACTION_TAP_DANCE_FN(dance_media),
    [TD_VOLUME]   = ACTION_TAP_DANCE_FN(dance_volume),
    [TD_F5_F6]    = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F6)
};

#endif