// Copyright 2023 yushakobo (@yushakobo)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_LGUI, MO(1),   KC_RCTL
    ),
    [1] = LAYOUT_60_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

void oled_write_layer_state(void){
    // Host Keyboard Layer Status
    oled_write_P(PSTR("L:"), false);

    switch (get_highest_layer(layer_state)) {
    case 0:
        oled_write_ln_P(PSTR("---"), false);
        break;
    case 1:
        oled_write_ln_P(PSTR("1--"), false);
        break;
    case 2:
        oled_write_ln_P(PSTR("-2-"), false);
        break;
    case 3:
        oled_write_ln_P(PSTR("--3"), false);
        break;
    default:
        oled_write_ln_P(PSTR("---"), false);
    }
}

void oled_write_host_led_state(void) {
    const led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("NL:"), false);
    oled_write_P(led_state.num_lock ? PSTR("On") : PSTR("- "), false);
    oled_write_P(PSTR("CL:"), false);
    oled_write_P(led_state.caps_lock ? PSTR("On") : PSTR("- "), false);
    oled_write_P(PSTR("SL:"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("On") : PSTR("- "), false);
}

// MIDI状態の出力関数
static void oled_write_midi_status(void) {
#ifdef MIDI_ADVANCED
    char buf[8];

    // --- Octave ---
    oled_write_P(PSTR("O:"), false);
    itoa(midi_config.octave - 2, buf, 10);
    oled_write(buf, false);
    oled_write_P(PSTR("\n"), false);

    // --- Transposition ---
    oled_write_P(PSTR("T:"), false);
    itoa(midi_config.transpose, buf, 10);
    oled_write(buf, false);
    oled_write_P(PSTR("\n"), false);

    // --- Velocity ---
    oled_write_P(PSTR("V:"), false);
    itoa(midi_config.velocity, buf, 10);
    oled_write(buf, false);
    oled_write_P(PSTR("\n"), false);
#else
    oled_write_P(PSTR("MIDI\nOFF\n"), false);
#endif
}

static unsigned int type_count = 0;
void count_type(void) {
    type_count++;
}

void oled_write_type_count_portrait(void) {
    static char type_count_str[5];
    oled_write_P(PSTR("Types"), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}

bool oled_task_user(void) {
    oled_write_layer_state();
    oled_write_host_led_state();
    oled_write_midi_status();
    oled_write_type_count_portrait();
    return false;
}
#endif // OLED_ENABLE
