/* Copyright 2020 zeriyoshi
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
 
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [0] = LAYOUT(
                                 KC_W,                               KC_P, \
                     KC_A,       KC_S,       KC_D,       KC_L,       KC_SCLN,    KC_QUOT, \
         KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_COMM,    KC_DOT,     MO(1),    KC_RSFT, \
                                             KC_V,       KC_M
     ),
     [1] = LAYOUT(
                                 KC_UP,                              KC_P, \
                     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_LSFT,      KC_SCLN,    KC_RSFT, \
         KC_TAB,     KC_1,       KC_2,       KC_ESCAPE,       KC_F9,    KC_F10,     KC_NO,    KC_ENTER, \
                                             KC_SPACE,       KC_ENTER
     )
 };