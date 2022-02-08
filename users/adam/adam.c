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
        }

        return process_record_adam(keycode, record);
    }

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