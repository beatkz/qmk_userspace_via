/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#define TAPPING_TERM 200
#define NCL_OFF QK_KB_0
#define NCL_ON QK_KB_1

enum layer_number {
    _QWERTY = 0,
    _NICOLA,
    _RAISE,
    _LOWER,
};

#define KC_L_SPC LT(_LOWER, KC_SPC)  // lower
#define KC_R_ENT LT(_RAISE, KC_ENT)  // raise
#define KC_G_JA LGUI_T(KC_LNG1)     // cmd or win
#define KC_G_EN LGUI_T(KC_LNG2)     // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC)      // ctrl
#define KC_A_DEL ALT_T(KC_DEL)       // alt

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+---------+--------+---------+--------+--------.
       KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
       KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_BSPC, KC_BSPC, KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_DEL , KC_DEL , KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/                 \--------+---------+--------+---------+--------+--------'
                        KC_A_DEL, KC_G_EN, KC_L_SPC,KC_C_BS,                   KC_C_BS, NCL_ON  , KC_G_JA, KC_A_DEL
    //                `----------+--------+--------+--------'                 `--------+---------+--------+---------'
    ),

    [_NICOLA] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+---------+--------+---------+--------+--------.
       _______, NG_Q   , NG_W   , NG_E   , NG_R   , NG_T   ,                   NG_Y   , NG_U    , NG_I   , NG_O    , NG_P   , _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
       _______, NG_A   , NG_S   , NG_D   , NG_F   , NG_G   , _______, _______, NG_H   , NG_J    , NG_K   , NG_L    , NG_SCLN, _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+---------+--------+---------+--------+--------|
       _______, NG_Z   , NG_X   , NG_C   , NG_V   , NG_B   , _______, _______, NG_N   , NG_M    , NG_COMM, NG_DOT  , NG_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+---------+--------+---------+--------+--------'
                         _______, NCL_OFF, NG_SHFTL,_______,                   _______, NG_SHFTR, _______, _______
    //                `----------+--------+--------+--------'                 `--------+---------+--------+---------'
    ),

    [_RAISE] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
       _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,                   KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_LPRN, KC_HASH, KC_DLR , KC_DQT , KC_QUOT, KC_TILD, _______, _______, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_GRV , KC_RPRN,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, KC_LCBR, KC_LBRC, _______, _______, KC_RBRC, KC_RCBR, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                         _______, _______, _______, _______,                   _______, _______, _______, QK_BOOT
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),

    [_LOWER] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                 ,--------+--------+--------+--------+--------+--------.
       KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   _______, KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/                 \--------+--------+--------+--------+--------+--------'
                       QK_BOOT  , _______, _______, _______,                   _______, _______, _______, _______
    //                  `--------+--------+--------+--------'                 `--------+--------+--------+--------'
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO)      },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
};
#endif

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
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

        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);

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
