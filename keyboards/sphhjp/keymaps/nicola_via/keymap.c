#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "sendstring_japanese.h"

#define KC_POWER KC_KB_POWER
#define KC_VOLUP KC_KB_VOLUME_UP
#define KC_VOLDW KC_KB_VOLUME_DOWN
#define KC_VOLMT KC_KB_MUTE
#define KC_MD_EJ KC_MEDIA_EJECT

enum layers{
    BASE,
    NICOLA,
    FUNC,
    RAISE1,
    RAISE2,
};

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

#define NCL_OFF QK_KB_0
#define NCL_ON  QK_KB_1

/* modify this keymap to customize. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    /* Left */                                                             /* Right */
    KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,           KC_7,   KC_8,    KC_9,    KC_0,    JP_MINS,  JP_CIRC, JP_YEN,  KC_BSPC,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     JP_AT,   JP_LBRC, KC_ENT,
    KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,   KC_J,    KC_K,    KC_L,    JP_SCLN,  JP_COLN, JP_RBRC,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,   KC_M,    JP_COMM, JP_DOT,  JP_SLSH,  JP_BSLS, KC_UP,   KC_RSFT,
    MO(FUNC),  JP_ZKHK, KC_LGUI, KC_LALT, JP_MHEN, KC_SPC,                 NCL_ON, JP_HENK, JP_KANA, KC_RALT, MO(FUNC), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [NICOLA] = LAYOUT(
    /* Left */                                                             /* Right */
    _______,    NG_1,    NG_2,    NG_3,    NG_4,    NG_5,   KC_6,           KC_7,   KC_8,    KC_9,    KC_0,    JP_MINS,  JP_CIRC, JP_YEN,  _______,
    _______,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                   NG_Y,   NG_U,    NG_I,    NG_O,    NG_P,     NG_LBRC, NG_RBRC, _______,
    _______,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                   NG_H,   NG_J,    NG_K,    NG_L,    NG_SCLN,  NG_QUOT, JP_RBRC,
    _______,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                   NG_N,   NG_M,    NG_COMM, NG_DOT,  NG_SLSH,  JP_BSLS, _______, _______,
    _______, _______, _______, _______, NCL_OFF, NG_SHFTL,              NG_SHFTR, _______, _______,  _______,  _______,  _______, _______, _______
  ),
  [FUNC] = LAYOUT(
    /* Left */                                                             /* Right */
    KC_POWER, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,      KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_F11,   KC_F12,   KC_INS,    KC_DEL,
    KC_CAPS,  _______,  _______,  _______,  _______,  _______,             _______, _______,     KC_PSCR, KC_SCRL, KC_PAUS,  KC_UP,    _______,   _______,
    _______,  KC_VOLDW, KC_VOLUP, KC_VOLMT, KC_MD_EJ, _______,             KC_PAST, KC_PSLS,     KC_HOME, KC_PGUP, KC_LEFT,  KC_RIGHT, _______,
    _______,  _______,  _______,  _______,  _______,  _______,             KC_PPLS, KC_KP_MINUS, KC_END,  KC_PGDN, KC_DOWN,  _______,  KC_RSFT,   _______,
    MO(FUNC), _______,  _______,  _______,  _______,  _______,             _______, _______,     _______, _______, MO(FUNC), KC_DEL,   KC_RGUI,   KC_RCTL
  ),
  [RAISE1] = LAYOUT(
    /* Left */                                                             /* Right */
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [RAISE2] = LAYOUT(
    /* Left */                                                             /* Right */
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______
  )
};

static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NCL_OFF:
      // NICOLA親指シフト
      if (record->event.pressed) {
        fn_pressed = true;
        fn_pressed_time = record->event.time;

        layer_on(FUNC);
      } else {
        layer_off(FUNC);

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

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(NICOLA);
  // NICOLA親指シフト
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
