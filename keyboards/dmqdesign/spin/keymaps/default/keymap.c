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
enum custom_keycodes { IS_OPEN = SAFE_RANGE, FILED, HI_THANKS, COPY, PASTE, STACKTRACE, NAME };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                 IS_OPEN, FILED, NAME, KC_TRNS, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_TAB), KC_TRNS, COPY, PASTE, STACKTRACE, KC_TRNS, HI_THANKS, RGB_TOG, KC_ENTER),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            rgblight_increase_hue(); // Cycle through the RGB hue
        } else {
            rgblight_decrease_hue();
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU); // Example of using tap_code which lets you use keycodes outside of the keymap
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            rgblight_increase_val(); // Change brightness on the RGB LEDs
        } else {
            rgblight_decrease_val();
        }
    }
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IS_OPEN:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("Is open: ");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case FILED:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("Filed: ");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case HI_THANKS:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("Hi, \nThanks for the information. I have passed it onto the developers.\nIf this is still an issue for you let me know.\n\nRegards,\nDavid");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case COPY:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LCTL("c"));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case PASTE:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LCTL("v"));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case STACKTRACE:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("*Stacktrace*\n{noformat}\n\n{noformat}\n");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case NAME:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("David");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
};
