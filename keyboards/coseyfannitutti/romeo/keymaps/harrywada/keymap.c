/* Copyright 2019 COSEYFANNITUTTI
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

#define _BASE  0
#define _NUMS  1
#define _FUNCS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Bspc│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │Caps  │ A │ S │ D │ F │ G │ H │ J │ K │ L │   Enter│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──────┤
     * │Shift   │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│ ?/Sft│
     * ├────┬───┼───┴┬──┴───┴─┬─┴─┬─┴───┴───┴┬──┴─┬─┴─┬────┤
     * │Ctrl│Gui│Alt │        │Num│          │Alt │Gui│Ctrl│
     * └────┴───┴────┴────────┴───┴──────────┴────┴───┴────┘
     */
    [_BASE] = LAYOUT_all(
            KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,      KC_Y,    KC_U,   KC_I,  KC_O,    KC_P,    KC_BSPC,
            KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,      KC_H,    KC_J,   KC_K,  KC_L,             KC_ENT,
            KC_LSFT, XXXXXXX, KC_Z,    KC_X,   KC_C,   KC_V,      KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
            KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,         MO(_NUMS),          KC_SPC,        KC_RALT, KC_RGUI, KC_RCTL ),

    /* Numbers Layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * │~ `  │! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│  \ |│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │   │   │   │   │   │   │_ -│+ =│: ;│     " '│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──────┤
     * │        │   │   │   │   │   │   │   │{ [│} ]│      │
     * ├────┬───┼───┴┬──┴───┴─┬─┴─┬─┴───┴───┴┬──┴─┬─┴─┬────┤
     * │    │   │    │Func    │   │Func      │    │   │    │
     * └────┴───┴────┴────────┴───┴──────────┴────┴───┴────┘
     */
    [_NUMS] = LAYOUT_all(
            KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSLS,
            _______, _______, _______, _______,    _______, _______, _______, KC_MINS,    KC_EQL,  KC_SCLN,          KC_QUOT,
            _______, _______, _______, _______,    _______, _______, _______, _______,    _______, KC_LBRC, KC_RBRC, _______,
            _______, _______, _______, MO(_FUNCS),          _______,          MO(_FUNCS),          _______, _______, _______ ),

    /* Functions Layer
     * ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
     * │F1   │ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│  F12│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │      │Prv│Ply│Stp│Nxt│   │ ← │ ↓ │ ↑ │ → │   PrtSc│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──────┤
     * │        │PgD│PgU│   │   │Bck│Fwd│Mut│VlD│VlU│      │
     * ├────┬───┼───┴┬──┴───┴─┬─┴─┬─┴───┴───┴┬──┴─┬─┴─┬────┤
     * │    │   │    │        │   │          │    │   │    │
     * └────┴───┴────┴────────┴───┴──────────┴────┴───┴────┘
     */
    [_FUNCS] = LAYOUT_all(
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
            _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,          KC_PSCR,
            _______, _______, KC_PGDN, KC_PGUP, _______, _______, KC_MRWD, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, _______,
            _______, _______, _______, _______,          _______,          _______,          _______, _______, _______ )
};
