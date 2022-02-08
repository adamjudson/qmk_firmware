/* Copyright 2022 Caleb Lightfoot
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
#include "lesovoz.h"

// suspect this is happening too fast - led doesn't have time to actually turn on a lot of the time
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    record->event.pressed ? writePinHigh(LED1) : writePinLow(LED1);
    return process_record_user(keycode, record);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    // don't want led1 to stay on when we're just pressing a layer
    writePinLow(LED1);
    state ? writePinHigh(LED2) : writePinLow(LED2);

    return layer_state_set_user(state);
}
