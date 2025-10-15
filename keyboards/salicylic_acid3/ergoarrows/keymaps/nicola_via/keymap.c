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
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// NICOLA親指シフト
#include "timer.h" // タイマー機能のために追加
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
#include "nicola.h"
NGKEYS nicola_keys;

enum NICOLA_Stats_Keys {
    NCL_OFF = QK_KB_0,
    NCL_ON
};
// NICOLA親指シフト

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
            layer_on(2); // レイヤー 2 をオン
        } else {
            layer_off(2); // レイヤー 2 をオフ
            // NCL_ON 直後（TAPPING_TERM 以内）の場合のみ、NICOLA モードと IME をオフ
            if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) < TAPPING_TERM)) {
                layer_off(1); // _NICOLA レイヤーをオフ
                nicola_off(); // NICOLA モードをオフ
                nicola_active = false; // NICOLA モード状態を更新
                #ifdef OS_WINDOWS
                tap_code(KC_INT5); // 無変換キーで IME をオフ
                #elif OS_MAC
                tap_code(KC_LNG2); // Mac の日本語入力オフ
                #endif
            }
            // NICOLA モードがオンの場合、IME 制御キーを送信せず、モードとレイヤーを維持
            fn_pressed = false;
        }
        return false;
        break;

    case NCL_ON:
        if (record->event.pressed) {
            nicola_on(); // NICOLA モードをオン
            layer_on(1); // _NICOLA レイヤーをオン
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
        if (record->event.pressed) {
            fn_pressed = false; // 他のキー押下で fn_pressed をリセット
        }
        break;
    }

    // NICOLA親指シフト
    // NICOLA モードがアクティブな場合、NICOLA 専用のキー処理を行う
    bool continue_processing = true;
    if (nicola_active) {
        nicola_mode(keycode, record);
        continue_processing = process_nicola(keycode, record);
    }
    return continue_processing;
    // NICOLA親指シフト
}

// タイマーによる fn_pressed のリセット
void matrix_scan_user(void) {
    if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) >= TAPPING_TERM)) {
        fn_pressed = false; // TAPPING_TERM 経過後に fn_pressed をリセット
    }
}
