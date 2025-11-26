/* Copyright 2023 Hanachi-ap
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
enum layer_names {
    _BASE,
    _L1,
    _L2,
    _L3,
    _L4,
    _L5,
    _L6,
    _L7,
    _L8,
    _FN,
    _SYS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_90_ansi(
    KC_NO,          KC_DEL,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_DEL,
    KC_1,   KC_6,   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0 ,    KC_MINS,  KC_EQUAL,  KC_BSPC,
    KC_2,   KC_7,   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,
    KC_3,   KC_8,   KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_4,   KC_9,   KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_GRV,   KC_RSFT,
    KC_5,   KC_0,   KC_LCTL,   KC_LGUI, KC_LALT,     LCTL_T(KC_SPC),  LSFT_T(KC_SPC),   MO(_SYS),  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT ,
                                                     KC_LCTL,  MO(_FN),    // Thumb Extension Keys
                                               KC_NO, MS_WHLL,MS_BTN3,MS_WHLR,KC_NO  //Wheel knobs is  not standard equipment
    ),
[_L1] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L2] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L3] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L4] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L5] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L6] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L7] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_L8] = LAYOUT_90_ansi(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
                                                           _______, _______,
                                               _______, _______,_______,_______,_______
    ),
[_FN] = LAYOUT_90_ansi(
    KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LCAP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ,
                                                           KC_NO, KC_NO,
                                               KC_NO, KC_NO,KC_NO,KC_NO,KC_NO
    ),
[_SYS] = LAYOUT_90_ansi(
    KC_NO,            TO(_BASE), TO(1),  TO(2),   TO(3),   TO(4),   TO(5),   TO(6),   TO(7),   TO(8)  , KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP,
    UG_TOGG, KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    UG_NEXT, UG_PREV,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    UG_HUEU, UG_HUED, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    UG_SATU, UG_SATD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    UG_VALU, UG_VALD, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_VOLD, KC_VOLU, KC_MNXT ,
                                                           KC_NO, KC_NO,
                                               KC_NO, KC_NO,KC_NO,KC_NO,KC_NO
    ),
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM layer_0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {2,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS(
    {4,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_5[] = RGBLIGHT_LAYER_SEGMENTS(
    {5,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_6[] = RGBLIGHT_LAYER_SEGMENTS(
    {6,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_7[] = RGBLIGHT_LAYER_SEGMENTS(
    {7,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM layer_8[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,   1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {51, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {88, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_scllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {89, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_0,
    layer_1,
    layer_2,
    layer_3,
    layer_4,
    layer_5,
    layer_6,
    layer_7,
    layer_8,
    rgb_caps_layer,
    rgb_numlock_layer,
    rgb_scllock_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _L1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _L2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _L3));
    rgblight_set_layer_state(4, layer_state_cmp(state, _L4));
    rgblight_set_layer_state(5, layer_state_cmp(state, _L5));
    rgblight_set_layer_state(6, layer_state_cmp(state, _L6));
    rgblight_set_layer_state(7, layer_state_cmp(state, _L7));
    rgblight_set_layer_state(8, layer_state_cmp(state, _L8));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(9, IS_HOST_LED_ON(USB_LED_CAPS_LOCK));
    rgblight_set_layer_state(10, IS_HOST_LED_ON(USB_LED_NUM_LOCK));
    rgblight_set_layer_state(11, IS_HOST_LED_ON(USB_LED_SCROLL_LOCK));

    return true;
}
#endif

#define _X NO_LED
led_config_t g_led_config = { {
// Key Matrix to LED Index
  { _X, _X,  0, 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  _X},
  { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, _X},
  { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, _X},
  { 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, _X, _X},
  { 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, _X, _X},
  { 76, 77, 78, 79, 80, 81, 82, 83, 84, _X, 85, 86, 87, 88, 89, _X, _X},
}, {

// LED Index to Physical Position
                   {30, 0}, {47, 0}, {61, 0}, {75, 0}, {89, 0}, {106, 0}, {120, 0}, {134, 0}, {148, 0}, {165, 0}, {179, 0}, {193, 0}, {207, 0}, {224, 0},
{0, 12}, {14, 12}, {30, 12}, {44, 12}, {58, 12}, {71, 12}, {85, 12}, {99, 12}, {113, 12}, {127, 12}, {141, 12}, {155, 12}, {169, 12}, {182, 12}, {196, 12}, {217, 12},
{0, 23}, {14, 23}, {33, 23}, {51, 23}, {65, 23}, {78, 23}, {92, 23}, {106, 23}, {120, 23}, {134, 23}, {148, 23}, {162, 23}, {175, 23}, {189, 23}, {203, 23}, {220, 23},
{0, 33}, {14, 33}, {35, 33}, {54, 33}, {68, 33}, {82, 33}, {96, 33}, {110, 33}, {123, 33}, {137, 33}, {151, 33}, {165, 33}, {179, 33}, {193, 33}, {215, 33},
{0, 43}, {14, 43}, {39, 43}, {61, 43}, {75, 43}, {89, 43}, {103, 43}, {117, 43}, {130, 43}, {144, 43}, {158, 43}, {172, 43}, {186, 43}, {200, 43}, {219, 43},
{0, 54}, {14, 54}, {32, 54}, {49, 54}, {66, 54}, {96, 54}, {108, 64}, {125, 64}, {137, 54}, {167, 54}, {182, 54}, {196, 54}, {210, 54}, {224, 54}
}, {
      4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,  4,4,4,4,4,4,4
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    int is_layer = get_highest_layer(layer_state | default_layer_state);
    if (is_layer >= 1 && is_layer <=8)
    {
        rgb_matrix_set_color(is_layer, 0,100, 0);
    }
    return true;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [_L1]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L2]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L3]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L4]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L5]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L6]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L7]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_L8]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SYS]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
