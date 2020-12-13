/* Copyright 2019-2020 DMQ Design
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

enum layers {
    _NUMPAD,
    _RGB,
    _MACRO
};

enum custom_keycodes {
    HELLO_WORLD = SAFE_RANGE,
};

//The below layers are intentionally empty in order to give a good starting point for how to configure multiple layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUMPAD] = LAYOUT(/* Base */
                KC_7, KC_8, KC_9, TO(_NUMPAD),
                KC_4, KC_5, KC_6, TO(_RGB),
                KC_1, KC_2, KC_3, TO(_MACRO),
                KC_0, KC_DOT, KC_ENTER
                ),

    [_RGB] = LAYOUT(/* Base */
                RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS,
                RGB_HUD,  RGB_SAD, RGB_VAD, KC_TRNS,
                KC_NO,    KC_NO,   KC_NO,   KC_TRNS,
                RGB_RMOD, RGB_TOG, RGB_MOD
                ),

    [_MACRO] = LAYOUT(/* Base */
                KC_ESC, KC_NO, KC_BSPC, KC_TRNS,
                KC_NO, KC_NO, KC_NO, KC_TRNS,
                KC_NO, KC_MUTE, KC_MPLY, KC_TRNS,
                KC_NO, KC_NO, KC_NO
                )
};

uint16_t lastKey;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HELLO_WORLD:
            if (record->event.pressed) {
                SEND_STRING("Hello, world!");
            }
            break;
    }
    lastKey = keycode;
    // fix rgb - FIXME, this is kludgy
    // and we don't really want to do this on the encoder click...
    // rgblight_increase_val();
    // rgblight_decrease_val();
    return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (get_highest_layer(layer_state)) {     //break each encoder update into a switch statement for the current layer
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _RGB:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case _MACRO:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
        }
    } else if (index == 1) { /* Second encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _RGB:
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
                break;
            case _MACRO:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
        }
    } else if (index == 2) { /* Third encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _RGB:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            case _MACRO:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    switch (get_highest_layer(state)) {
        case _NUMPAD:
            setrgb(75, 0, 0, &led[0]); //Set the top LED to white for the bottom layer
            setrgb(0, 0, 0, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _RGB:
            setrgb(0, 0, 0, &led[0]); //Set the middle LED to white for the middle layer
            setrgb(75, 0, 0, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _MACRO:
            setrgb(0, 0, 0, &led[0]);
            setrgb(0, 0, 0, &led[1]);
            setrgb(75, 0, 0, &led[2]); //Set the bottom LED to white for the top layer
            break;
    }
    rgblight_set();

    return state;
}

#ifdef OLED_DRIVER_ENABLE

static const char *ANIMATION_NAMES[] = {
	"unknown",
	"static",
	"breathing I",
	"breathing II",
	"breathing III",
	"breathing IV",
	"rainbow m I",
	"rainbow m II",
	"rainbow m III",
	"rainbow s I",
	"rainbow s II",
	"rainbow s III",
	"rainbow s IV",
	"rainbow s V",
	"rainbow s VI",
	"snake I",
	"snake II",
	"snake III",
	"snake IV",
	"snake V",
	"snake VI",
	"knight I",
	"knight II",
	"knight III",
	"christmas",
	"static grad I",
	"static grad II",
	"static grad III",
	"static grad IV",
	"static grad V",
	"static grad VI",
	"static grad VII",
	"static grad VIII",
	"static grad IX",
	"static grad X",
	"rgb test",
	"alternating",
	"twinkle I",
	"twinkle II",
	"twinkle III",
	"twinkle IV",
	"twinkle V",
	"twinkle VI"
};

void rgblight_get_mode_name(uint8_t mode, size_t bufsize, char *buf) {
    snprintf(buf, bufsize, "%-25s", ANIMATION_NAMES[mode]);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef LEFT_HAND
    return OLED_ROTATION_180;
#else
    return OLED_ROTATION_0;
#endif
}

void oled_task_user(void) {
    // oled_clear();
    // oled_write_ln("5", false);
    // oled_render();
    // oled_clear();
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        case _MACRO:
            oled_write_P(PSTR("Macro\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    static char rgb_mode_name[30];
    rgblight_get_mode_name(rgblight_get_mode(), sizeof(rgb_mode_name), rgb_mode_name);

    oled_write_P(PSTR("Mode: "), false);
    oled_write_ln(rgb_mode_name, false);
    //oled_write_ln("Boy I wonder what key we just pressed...", false);
}
#endif
