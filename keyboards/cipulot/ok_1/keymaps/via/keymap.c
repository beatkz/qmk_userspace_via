/* Copyright 2024 Cipulot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

// clang-format off
enum layers{
    _MAC_BASE,
    _MAC_FN,
    _WIN_BASE,
    _WIN_FN
};

enum custom_keycodes {
    MAC = QK_KB_0,
    WIN = QK_KB_1,
    MACFN = QK_KB_2,
    WINFN = QK_KB_3,
    SNIP = QK_KB_4,
    OPT = QK_KB_5,
    CTLR = QK_KB_6,
    CMD = QK_KB_7
};
// clang-format on

//#define MAC PDF(_MAC_BASE)
//#define WIN PDF(_WIN_BASE)

//#define MACFN MO(_MAC_FN)
//#define WINFN MO(_WIN_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_MAC_BASE] = LAYOUT(
        KC_ESC,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        MACFN,      CTLR,    OPT,     CMD,                KC_SPC,                        CMD,  OPT,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_MAC_FN] = LAYOUT(
        _______, KC_BRID, KC_BRIU, KC_MCTL, _______,   _______,   _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, SNIP,
        _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, WIN,     _______, _______,   _______,   _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______,   _______,   NK_TOGG, _______, _______, _______, _______, _______,  RM_VALU,
        _______, _______, _______, _______,                       _______,                   _______, _______, RM_PREV,  RM_VALD,  RM_PREV
    ),
    [_WIN_BASE] = LAYOUT(
        KC_ESC,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        WINFN,      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_WIN_FN] = LAYOUT(
        _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, SNIP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, MAC,     _______, _______, _______, _______, RM_VALU,
        _______, _______, _______, _______,                   _______,                   _______, _______, RM_PREV, RM_VALD, RM_PREV
    ),
    // clang-format on
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC_BASE);
            }
            return false;
        case WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN_BASE);
            }
            return false;
        case MACFN:
            if (record->event.pressed) {
                layer_on(_MAC_FN);
            } else {
                layer_off(_MAC_FN);
            }
            return false;
        case WINFN:
            if (record->event.pressed) {
                layer_on(_WIN_FN);
            } else {
                layer_off(_WIN_FN);
            }
            return false;
        case OPT:
            if (record->event.pressed) {
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
            }
            return false;
        case CTLR:
            if (record->event.pressed) {
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
            }
            return false;
        case CMD:
            if (record->event.pressed) {
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
            }
            return false;
        case SNIP:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_WIN_FN)) {
                    tap_code(KC_PSCR);
                } else if (IS_LAYER_ON(_MAC_FN)) {
                    tap_code16(LSFT(LGUI(KC_3)));
                }
            }
            return false;

        default:
            return true;
    }
}
