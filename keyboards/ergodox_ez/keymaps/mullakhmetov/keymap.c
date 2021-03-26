#include QMK_KEYBOARD_H

#include "tap_dances.c"

#define BASE 0 // default layer
#define SYMB 1 // symbol


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
    /* Base layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   `~   |  1!  |  2@  |  3#  |  4$  |  5%  |  \|  |           |  -_  |  6^  |  7&  |  8*  |  9(  |  0)  |  =+    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   E  |   R  |   T  | HOME |           | PGUp |   Y  |   U  |   I  |   O  |   P  |  [{    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  | ]}     |
    * |--------+------+------+------+------+------| END  |           |PGDown|------+------+------+------+------+--------|
    * | LSFT   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  | '"     |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |  `~  |      | Caps | LAlt |  cmd |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,---------------.
    *                                        |      | Mute |       | Play |        |
    *                                 ,------|------|------|       |------+--------+------.
    *                                 |      |      | Vol+ |       | Next |        |      |
    *                                 | Space| \SYMB|------|       |------|  SYMB  |Enter |
    *                                 |      |      | Vol- |       | Prev |        |      |
    *                                 `--------------------'       `----------------------'
    */
    // left hand
    KC_NONUS_BSLASH, KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_BSLS,
    KC_TAB,          KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_HOME,
    KC_LCTL,         KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
    OSM(MOD_LSFT),   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_END,
    KC_GRV,          KC_NO,  KC_CAPS, KC_LALT, KC_LGUI,

                                                  // left thumb cluster
                                                                       KC_NO, KC_MUTE,
                                                                              KC_VOLU,
                                                     KC_SPC, LT(SYMB, KC_NO), KC_VOLD,
    // right hand
    KC_MINS, KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_PGUP, KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,
             KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_RBRC,
    KC_PGDN, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
             KC_MINS, KC_NO, KC_NO,   KC_NO,   KC_NO,

    // right thumb cluster
    KC_MPLY, KC_NO,
    KC_MFFD,
    KC_MRWD, TO(SYMB), KC_ENT
  ),
  [SYMB] = LAYOUT_ergodox(
    /* Symbols layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      | bspc |      |      | del  |------|           |------| left | down |  up  |right |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      | BASE |------|       |------|      |Enter |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // left hand
    KC_ESC, KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5,  KC_F6,
    KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,
    KC_NO,  KC_NO, KC_BSPC, KC_NO, KC_NO, KC_DEL,
    KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,
    KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,

                                    // left thumb cluster
                                           KC_NO,  KC_NO,
                                                   KC_NO,
                                  KC_NO, TO(BASE), KC_NO,
    // right hand
    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,

    // right thumb cluster
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, KC_ENT
  )
};