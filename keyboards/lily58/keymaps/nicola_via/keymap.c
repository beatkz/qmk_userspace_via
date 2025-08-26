 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>
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

enum layer_number {
  _QWERTY = 0,
  _NICOLA,
  _FN1,
  _FN2,
};

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |   FN1| /Space  /       \NCL_ON\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                       KC_LALT, KC_LGUI, FN1, KC_SPC,   NCL_ON,   FN2, KC_RGUI, KC_RALT
),
/* NICOLA
 * 単独
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  １  |  ２  |  ３  |  ４  |  ５  |                    |  ６  |  ７  |  ８  |  ９  |  ０  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  。  |  か  |  た  |  こ  |  さ  |                    |  ら  |  ち  |  く  |  つ  |  、  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  う  |  し  |  て  |  け  |  せ  |-------.    ,-------|  は  |  と  |  き  |  い  |  ん  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  。  |  ひ  |  す  |  ふ  |  へ  |-------|    |-------|  め  |  そ  |  ね  |  ほ  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |NCLOFF| /親指L  /       \ 親指R\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * 左シフト同時押し
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ？  |  ・  |  ～  |  「  |  」  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ぁ  |  え  |  り  |  ゃ  |  れ  |                    |  ぱ  |  ぢ  |  ぐ  |  づ  |  ぴ  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  を  |  あ  |  な  |  ゅ  |  も  |-------.    ,-------|  ば  |  ど  |  ぎ  |  ぽ  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ぅ  |  ー  |  ろ  |  や  |  ぃ  |-------|    |-------|  ぷ  |  ぞ  |  ぺ  |  ぼ  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |NCLOFF| /親指L  /       \ 親指R\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * 右シフト同時押し
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ？  |  ・  |  ～  |  「  |  」  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  が  |  だ  |  ご  |  ざ  |                    |  よ  |  に  |  る  |  ま  |  ぇ  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ヴ  |  じ  |  で  |  げ  |  ぜ  |-------.    ,-------|  み  |  お  |  の  |  ょ  |  っ  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  び  |  ず  |  ぶ  |  べ  |-------|    |-------|  ぬ  |  ゆ  |  む  |  わ  |  ぉ  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |NCLOFF| /親指L  /       \ 親指R\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'

 */
  [_NICOLA] = LAYOUT(
  _______,    NG_1,    NG_2,    NG_3,    NG_4,    NG_5,                   _______, _______, _______, _______, _______, _______,
  _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                      NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, NG_LBRC,
  _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                      NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, _______,
  _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,  _______, _______,    NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, _______,
                             _______, _______, NCL_OFF, NG_SHFTL, NG_SHFTR,  _______, _______, _______
  ),
/* FN1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |   FN1| /Space  /       \NCL_ON\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_FN1] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, _______, _______, _______, _______,   _______, _______, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* FN2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |   FN1| /Space  /       \NCL_ON\  | FN2  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_FN2] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_GRAVE, KC_PLUS, KC_LCBR, KC_RCBR, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
)

};

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

void oled_write_layer_state(void){
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case _FN1:
        oled_write_ln_P(PSTR("Fn1"), false);
        break;
    case _FN2:
        oled_write_ln_P(PSTR("Fn2"), false);
        break;
    case _NICOLA:
        oled_write_ln_P(PSTR("Nicola"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_write_host_led_state(void) {
    const led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("NL:"), false);
    oled_write_P(led_state.num_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" CL:"), false);
    oled_write_P(led_state.caps_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" SL:"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("on") : PSTR("-"), false);
}

static unsigned int type_count = 0;
void count_type(void) {
    type_count++;
}

void oled_write_type_count(void) {
    static char type_count_str[7];
    oled_write_P(PSTR("Type count: "), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_layer_state();
    oled_write_host_led_state();
    oled_write_type_count();
  } else {
      render_logo();
  }
    return false;
}
#endif // OLED_ENABLE

// NICOLA親指シフト
static bool nicola_active = false;
static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0; // fn_pressed の押下時刻を保持
// NICOLA親指シフト

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    #ifdef OLED_ENABLE
    count_type();
    #endif
  }

  switch (keycode) {
    // NICOLA親指シフト
    case NCL_OFF:
        if (record->event.pressed) {
            fn_pressed = true;
            fn_pressed_time = timer_read(); // 押下時刻を記録
            layer_on(_FN1); // レイヤー 2 をオン
        } else {
            layer_off(_FN1); // レイヤー 2 をオフ

            // NCL_ON 直後（TAPPING_TERM 以内）の場合のみ、NICOLA モードと IME をオフ
            if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) < TAPPING_TERM)) {
                layer_off(_NICOLA); // _NICOLA レイヤーをオフ
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
            layer_on(_NICOLA); // _NICOLA レイヤーをオン
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
