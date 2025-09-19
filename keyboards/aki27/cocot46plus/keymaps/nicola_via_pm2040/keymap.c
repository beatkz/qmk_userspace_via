/*
Copyright 2022 aki27

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

// NICOLA親指シフト
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
#include "nicola.h"
NGKEYS nicola_keys;

enum NICOLA_Stats_Keys {
    NCL_OFF = QK_KB_7,
    NCL_ON
};
// NICOLA親指シフト

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE,
    _NICOLA,
    _LOWER,
    _RAISE,
    _TRACKBALL,
    _L4,
    _L5
};

#define LW_MHEN LT(1,KC_INT5)  // lower
#define RS_HENK LT(2,KC_INT4)  // raise
#define DEL_ALT ALT_T(KC_DEL)

// In the buttom row, KC_MS_BTN3 binds middle-click to the encoder's button press
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN,  KC_ENT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LALT, KC_LGUI,   LW_MHEN,  KC_SPC,    JP_LBRC,              JP_RBRC,    NCL_ON, KC_BSPC, KC_RGUI, KC_RALT,
                                                                 XXXXXXX,    SCRL_MO,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
   [_NICOLA] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                                          NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                                          NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                                          NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, NCL_OFF, NG_SHFTL,     _______,           _______, NG_SHFTR, _______, _______,  _______,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
   TO(_RAISE),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   JP_AT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, _______, _______, MS_BTN2, MS_BTN1, _______,                                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, JP_COLN, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, _______, _______, _______, _______, _______,                                       KC_HOME,  KC_END, S(KC_TAB), KC_TAB, _______, _______,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______,  _______,   _______,             _______, _______,  KC_DEL, _______, _______,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
    TO(_BASE),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_PMNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                        KC_TAB,   KC_P4,   KC_P5,   KC_P6, KC_PAST, KC_PENT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _______, _______, _______, _______,  KC_F11,  KC_F12,                                       _______,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______,   TT(4), _______,      _______,           _______,   KC_P0, _______, KC_PDOT,  _______,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, UG_VALU, UG_SATU, UG_HUEU, UG_NEXT,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, UG_VALD, UG_SATD, UG_HUED, UG_PREV,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,     MS_BTN1,             MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
   [_L4] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______, _______,      _______,           _______,  _______, _______, _______,  _______,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
   [_L5] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        _______, _______, _______, _______,      _______,           _______,  _______, _______, _______,  _______,
                                                                 XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),

};

// Same function on all layers for now.
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [2] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [3] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [4] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [5] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [6] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(MS_WHLD);
        } else {
            tap_code(MS_WHLU);
        }
    }
    return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _NICOLA:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_PURPLE, 0, 2); // 例: NICOLA レイヤー用の色
        #endif
        break;
    case _LOWER:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        #endif
        //cocot_setcroll_mode(true);
        break;
    case _RAISE:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_RED, 0, 2);
        #endif
        //cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        #endif
        //cocot_set_scroll_mode(false);
        break;
    default:
        #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        #endif
        //cocot_set_scroll_mode(false);
        break;
    }
    #ifdef RGBLIGHT_ENABLE
    rgblight_set_effect_range( 2, 10);
    #endif
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

// NICOLA親指シフト
static bool nicola_active = false;
static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0; // fn_pressed の押下時刻を保持
// NICOLA親指シフト

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    // NICOLA親指シフト
    case NCL_OFF:
      if (record->event.pressed) {
        fn_pressed = true;
        fn_pressed_time = timer_read(); // 押下時刻を記録
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        layer_off(_NICOLA);
        nicola_off();
        nicola_active = false;
        // NCL_ON 直後（TAPPING_TERM 以内）の場合、IME をオフにする
        if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) < TAPPING_TERM)) {
            #ifdef OS_WINDOWS
            tap_code(KC_INT5); // 無変換キーで IME をオフ
            #elif OS_MAC
            tap_code(KC_LNG2); // Mac の日本語入力オフ
            #endif
        } else {
            #ifdef OS_WINDOWS
            tap_code(KC_INT4); // 変換キーで IME をオン
            #elif OS_MAC
            tap_code(KC_LNG1); // Mac の日本語入力オン
            #endif
        }
        fn_pressed = false;
      }
      return false;
      break;
    case NCL_ON:
      if (record->event.pressed) {
        nicola_on();
        layer_on(_NICOLA);
        nicola_active = true; // NICOLA モード状態を更新
        fn_pressed = true; // NCL_ON でも fn_pressed を設定
        fn_pressed_time = timer_read(); // 押下時刻を記録
        #ifdef OS_WINDOWS
        tap_code(KC_INT4); // 変換キーで IME をオン
        #elif OS_MAC
        tap_code(KC_LNG1); // Mac の日本語入力オン
        #endif
      }
      return false;
      break;
    // NICOLA親指シフト

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

// タイマーによる fn_pressed のリセット
void matrix_scan_user(void) {
    if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) >= TAPPING_TERM)) {
        fn_pressed = false; // TAPPING_TERM 経過後に fn_pressed をリセット
    }
}

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}
