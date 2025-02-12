/* Copyright 2021 ai03
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
#include "keymap_japanese.h"
#include "sendstring_japanese.h"

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

#define NCL_OFF QK_KB_0
#define NCL_ON QK_KB_1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_SCLN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MINS,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_UP,   MO(2),
        KC_LCTL, KC_LGUI, KC_LALT,KC_LNG1,    JP_MHEN,    KC_SPC,     NCL_ON,    MO(2), KC_LNG2, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T, _______,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,  _______,
        _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G, _______,    NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN,  _______,
        _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B, _______,    NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH,  _______,
        _______, _______, _______,_______,    NCL_OFF,   NG_SHFTL,     NG_SHFTR, _______, _______, _______, _______, _______
   ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,   _______,   _______, _______,   _______,    _______, _______, _______, _______
    )
};

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(1);
  // NICOLA親指シフト
}

static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NCL_OFF:
      // NICOLA親指シフト
      if (record->event.pressed) {
        fn_pressed = true;
        fn_pressed_time = record->event.time;

        layer_on(2);
      } else {
        layer_off(2);

        if(fn_pressed
        && (TIMER_DIFF_16(record->event.time, fn_pressed_time) < TAPPING_TERM)){
            nicola_off();
        }
        fn_pressed = false;
      }
      // NICOLA親指シフト
      return false;
      break;
    case NCL_ON:
      if (record->event.pressed) {
        // NICOLA親指シフト
        nicola_on();
        fn_pressed = false;
        // NICOLA親指シフト
      }
      return false;
      break;
    default:
        if(record->event.pressed){
            fn_pressed = false;
        }
        break;
  }

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false) return false;
  // NICOLA親指シフト

  return true;
}
