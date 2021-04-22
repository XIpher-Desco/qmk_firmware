p/* Copyright 2020 yushakobo
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LAYER_HUB,
    _CLISTA,
    _CLISTA2,
    _BLENDER,
    _BLENDER2,
    _BLENDER3,
    _DCSWORLD,
    _MEDIA,
    _LED_FUNC
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    YUSHAURL = SAFE_RANGE,
    XI_KEY_00,
    XI_KEY_01,
    XI_KEY_02,
    XI_KEY_10,
    XI_KEY_11,
    XI_KEY_12,
    XI_KEY_20,
    XI_KEY_21,
    XI_KEY_22
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        TG(_LAYER_HUB), KC_MS_BTN3, KC_MS_BTN4,
        KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,
        KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),
    [_LAYER_HUB] = LAYOUT(
        _______, TG(_LAYER_HUB), TG(_LED_FUNC),
        TG(_CLISTA), _______, TG(_DCSWORLD),
        TG(_BLENDER), _______, TG(_MEDIA)
    ),
    [_CLISTA] = LAYOUT(
        TG(_CLISTA), C(KC_Z), C(KC_S),
        KC_P, KC_E, RCS(KC_Z),
        MO(_CLISTA2), C(KC_D), KC_M
    ),
    [_CLISTA2] = LAYOUT(
        TG(_CLISTA2), KC_W, C(KC_S),
        KC_LSFT, KC_B, KC_G,
        _______, KC_LCTL, KC_LALT
    ),
    [_BLENDER] = LAYOUT(
        TG(_BLENDER), C(KC_Z), TG(_BLENDER3),
        KC_G, KC_R, KC_S,
        MT(MOD_LSFT, KC_X), MT(MOD_LCTL, KC_Y), MO(_BLENDER2)
        // MT(MOD_LSFT, KC_X), MT(MOD_LCTL, KC_Y), MT(MOD_LALT, KC_Z)
    ),
    [_BLENDER2] = LAYOUT(
        KC_NO, KC_W, C(KC_S),
        KC_X, KC_Y, KC_Z,
        KC_E, S(KC_A), _______
    ),
    [_BLENDER3] = LAYOUT(
        TG(_BLENDER3), KC_W, TG(_BLENDER3),
        KC_KP_7, KC_KP_5, KC_Z,
        KC_KP_1, KC_KP_3, KC_KP_DOT
    ),
        [_DCSWORLD] = LAYOUT(
        TG(_DCSWORLD), KC_F15, KC_F16,
        KC_F19, KC_F20, KC_F21,
        KC_F22, KC_F23, KC_F24
    ),
    [_MEDIA] = LAYOUT(
        TG(_MEDIA), CMB_TOG, KC_AUDIO_MUTE,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
        KC_7, KC_MEDIA_STOP, KC_9
    ),

    [_LED_FUNC] = LAYOUT(
        RGB_TOG,   TG(_LED_FUNC), RGB_MOD,
        RGB_HUI,   RGB_SAI,    RGB_VAI,
        RGB_HUD,   RGB_SAD,    RGB_VAD
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case YUSHAURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://yushakobo.jp/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
        case XI_KEY_00:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                tap_code(KC_1);
            } else {
                // when keycode QMKURL is released
            }
            return false;
        case XI_KEY_01:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                tap_code(KC_2);
            } else {
                // when keycode QMKURL is released
            }
            return false;
        case XI_KEY_02:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                tap_code(KC_3);
            } else {
                // when keycode QMKURL is released
            }
            return false;
        default:
            return true;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    // _BASE Leyer
    if (IS_LAYER_ON(_BASE)){
        if (index == 0) { // Left encoder
            if (clockwise) {
                tap_code(KC_MS_WH_RIGHT);
            } else {
                tap_code(KC_MS_WH_LEFT);
            }
        }
        else if (index == 1) { // Right encoder
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        }
    }
    // _CLISTA Leyer
    if (IS_LAYER_ON(_CLISTA)){
        if (index == 0) { // Left encoder
            if (clockwise) {
                tap_code(KC_MS_WH_UP);
            } else {
                tap_code(KC_MS_WH_DOWN);
            }
        }
        else if (index == 1) { // Right encoder
            if (clockwise) {
                tap_code(KC_EQL);
            } else {
                tap_code(KC_MINS);
            }
        }
    }
    // MEDIA Leyer
    if (IS_LAYER_ON(_MEDIA)){
        if (index == 0) { // Left encoder
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
        else if (index == 1) { // Right encoder
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    // LED Leyer
    if (IS_LAYER_ON(_LED_FUNC)){
        if (index == 0) { // Left encoder
            if (clockwise) {
                // 時計回り
                rgblight_increase_val_noeeprom();
            } else {
                // 反時計回り
                rgblight_decrease_val_noeeprom();
            }
        }
        else if (index == 1) { // Right encoder
            if (clockwise) {
                // 時計回り
                rgblight_decrease_hue_noeeprom();
            } else {
                // 反時計回り
                rgblight_increase_hue_noeeprom();
            }
        }
    }
    if (IS_LAYER_ON(_DCSWORLD)){
        if (index == 0) { // Left encoder
            if (clockwise) {
                // 時計回り
                tap_code(KC_F13);
            } else {
                // 反時計回り
                tap_code(KC_F14);
            }
        }
        else if (index == 1) { // Right encoder
            if (clockwise) {
                // 時計回り
                tap_code(KC_F17);
            } else {
                // 反時計回り
                tap_code(KC_F18);
            }
        }
    }
}

    // _BASE,
    // _LAYER_HUB,
    // _CLISTA,
    // _BLENDER,
    // _BLENDER2,
    // _MEDIA,
    // _LED_FUNC
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    // INSERT CODE HERE: turn off all leds

    switch (layer) {
        case _BASE:
            rgblight_sethsv_at(HSV_BLUE, 1);
            break;
        case _LAYER_HUB:
            rgblight_sethsv_at(HSV_RED, 1);
            break;
        case _CLISTA:
            rgblight_sethsv_at(HSV_WHITE, 1);
            break;        
        case _CLISTA2:
            rgblight_sethsv_at(HSV_CYAN, 1);
            break;
        case _BLENDER:
            rgblight_setrgb_at(RGB_ORANGE, 1);
            break;
        case _BLENDER2:
            rgblight_setrgb_at(RGB_ORANGE, 1);
            break;
        case _MEDIA:
            rgblight_sethsv_at(HSV_GREEN, 1);
            break;
        case _DCSWORLD:
            rgblight_sethsv_at(HSV_TEAL, 1);
            break;
        case _LED_FUNC:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_2
            // rgblight_sethsv_at(HSV_PURPLE, 1);
            break;
        // add case for each layer
    }
};

// layer combos
// enum combos {
//   ROTARY_CONBO,
//   TEST_CONBO
// };

// const uint16_t PROGMEM comb_keys_rotary[] = {XI_KEY_00, XI_KEY_02, COMBO_END};
// const uint16_t PROGMEM comb_keys_test[] = {KC_4, KC_6, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [ROTARY_CONBO] = COMBO_ACTION( comb_keys_rotary),
//   [TEST_CONBO] = COMBO_ACTION( comb_keys_test)
// };

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case ROTARY_CONBO:
//       if (pressed) {
//         layer_invert(_LED_FUNC);
//       }
//       break;
//     case TEST_CONBO:
//       if (pressed) {
//         layer_invert(_LED_FUNC);
//       }
//       break;
//   }
// }

// caps, numlock status led
/*
const rgblight_segment_t PROGMEM quick7_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {9,1,HSV_WHITE},
    {12,1,HSV_WHITE}
);
const rgblight_segment_t PROGMEM quick7_numlock[] = RGBLIGHT_LAYER_SEGMENTS(
    {10,1,HSV_BLUE},
    {11,1,HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM quick7_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    quick7_capslock,
    quick7_numlock
);

void keyboard_post_init_user(void){
    rgblight_layers = quick7_rgb_layers;
}

bool led_update_user(led_t led_state){
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}
*/