/*
Copyright 2021 Salicylic_Acid

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

#define NCL_OFF QK_KB_0
#define NCL_ON QK_KB_1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,--------------------------------------------------------------|   |--------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,     XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, JP_COLN,       JP_AT,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_MINS,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, JP_CIRC,      JP_YEN,    KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, JP_LBRC,     JP_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
        MO(2), JP_ZKHK,   KC_UP, KC_LGUI, KC_LALT, JP_MHEN,  KC_SPC,      NCL_ON,   MO(2), KC_RGUI, KC_RALT,   KC_UP,  KC_APP, KC_RCTL,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LEFT, KC_DOWN, KC_RGHT,                                                           KC_LEFT, KC_DOWN, KC_RGHT
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'
  ),
 [1] = LAYOUT(
  //,--------------------------------------------------------------|   |--------------------------------------------------------------.
      _______,    NG_1,    NG_2,    NG_3,    NG_4,    NG_5, _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T, _______,     _______,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, NG_LBRC,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G, _______,     _______,    NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B, _______,     _______,    NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, NCL_OFF,NG_SHFTL,    NG_SHFTR, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______,                                                           _______, _______, _______
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'

  ),
  [2] = LAYOUT(
  //,--------------------------------------------------------------|   |--------------------------------------------------------------.
       KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_PSCR, KC_SCRL, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PGUP, KC_QUOT, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, UG_TOGG, UG_NEXT, _______, UG_SATD, UG_SATU, _______,     _______, _______, _______,  KC_END, KC_PGDN, _______, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, UG_VALD, KC_VOLU, UG_VALU, UG_HUED, UG_HUEU, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_MPRV, KC_VOLD, KC_MNXT,                                                           _______, _______, _______
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'
  ),
  [3] = LAYOUT(
  //,--------------------------------------------------------------|   |--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX,                                                           XXXXXXX, XXXXXXX, XXXXXXX
  //|--------------------------------------------------------------|   |--------------------------------------------------------------'
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
