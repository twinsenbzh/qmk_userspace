/* Copyright 2020 jbeaurepaire
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

#define TAPPING_TOGGLE 2

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_DEL,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS, \
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENTER,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PGUP, \
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        TT(_FN),    KC_N ,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGDN, \
         MO(_FN),  KC_LALT, KC_LGUI,                                                              KC_HOME, KC_UP,   KC_END,  MO(_FN), \
                                      MO(_FN), KC_LSFT, KC_SPACE,      KC_SPACE, KC_BSPC,KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
        _______, _______, _______, _______, _______, _______,  _______,       _______,  KC_TAB, KC_PSLS, KC_PAST,  KC_PMNS,  _______, \
        _______, _______, _______, _______, _______, _______,       _______,  _______,    KC_7,    KC_8,    KC_9,  KC_PPLS,  _______, \
        _______, _______, _______, _______, _______, _______,       _______,  _______,    KC_4,    KC_5,    KC_6,   KC_ENT,  _______, \
          _______, _______, _______,                                                            KC_1, KC_2,  KC_3,  _______, \
                                      _______, _______, _______,      _______, _______, _______, KC_0, KC_0, KC_PDOT \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
