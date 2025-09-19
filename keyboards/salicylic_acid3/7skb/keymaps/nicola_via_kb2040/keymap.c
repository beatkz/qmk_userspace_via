#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "sendstring_japanese.h"

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
// NICOLA
  _NICOLA, // NICOLA親指シフト入力レイヤー
// NICOLA
  _FN1,
  _FN2,
};

#define NCL_OFF QK_KB_0
#define NCL_ON  QK_KB_1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS, KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN1),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LALT, KC_LGUI,  KC_SPC,  KC_SPC,               NCL_ON,  KC_SPC,          KC_RGUI, KC_RALT
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_NICOLA] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,    NG_1,   NG_2,    NG_3,    NG_4,    NG_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_Q,   NG_W,    NG_E,    NG_R,    NG_T,        NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, NG_LBRC, NG_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_A,   NG_S,    NG_D,    NG_F,    NG_G,        NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, NG_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______,    NG_Z,   NG_X,    NG_C,    NG_V,    NG_B,        NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, NCL_OFF,NG_SHFTL,             NG_SHFTR, _______,         _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),
  [_FN1] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_FN2),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_PSCR, KC_SCRL,KC_PAUSE,   KC_UP, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          KC_STOP, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN2] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
     TG(_FN2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          KC_STOP, XXXXXXX
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN1:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _NICOLA:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _FN2:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 11);
#endif
return state;
}

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

        layer_on(_FN1);
      } else {
        layer_off(_FN1);

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
    // NICOLA-A for JP KB Env
    // NICOLA-A for JP KB Env
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
