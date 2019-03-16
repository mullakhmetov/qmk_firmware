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
    * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  | ]} RCTL|
    * |--------+------+------+------+------+------| END  |           |PGDown|------+------+------+------+------+--------|
    * | LSFT   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  | '" RSFT|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      | Caps | LAlt |  cmd |                                       |  Up  | Down | Left |Right |Enter |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,---------------.
    *                                        |      | Mute |       | Play |Ctrl/Esc|
    *                                 ,------|------|------|       |------+--------+------.
    *                                 |      |      | Vol+ |       | Next |        |      |
    *                                 | Space|Backsp|------|       |------|  Del   |Enter |
    *                                 |  L1  |ace   | Vol- |       | Prev |        |      |
    *                                 `--------------------'       `----------------------'
    */
    // left hand
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_BSLS,
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME,
    KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
    OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_END,
    KC_NO,   KC_APP, KC_CAPS, KC_LALT, KC_LGUI,

                                                  // left thumb cluster
                                                         KC_NO,  KC_MUTE,
                                                                 KC_VOLU,
                                                LT(SYMB,KC_SPC), KC_BSPC, KC_VOLD,
    // right hand
    KC_MINS, KC_6,  KC_7,    KC_8,    KC_9,    KC_0,                 KC_EQL,
    KC_PGUP, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,                 KC_LBRC,
    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL,KC_RBRC),
    KC_PGDN, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,              MT(MOD_RSFT,KC_QUOT),
    KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_ENT,

    // right thumb cluster
    KC_MPLY, KC_NO,
    KC_MFFD,
    KC_MRWD, KC_DEL, KC_ENT
  ),
  [SYMB] = LAYOUT_ergodox(
    /* Symbols layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |      |  {   |   }  | ' "  |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |  ([  |  )]  | - _  |      |------|           |------|      |  4   |  5   |  6   |  -   |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      | < <= | > >= | = != |      |      |           |      |      |  1   |  2   |  3   |  =   |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |      |  0   |  .   |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // left hand
    KC_ESC, KC_F1, KC_F2, KC_F3,                    KC_F4,                    KC_F5,         KC_F6,
    KC_NO,  KC_NO, KC_NO, KC_LCBR,                  KC_RCBR,                  TD(TD_QUOTES), KC_NO,
    KC_NO,  KC_NO, KC_NO, TD(TD_L_PARENTH_BRACKET), TD(TD_R_PARENTH_BRACKET), TD(TD_MINUS_UNDERSCORE),
    KC_NO,  KC_NO, KC_NO, TD(TD_LT_LTE),            TD(TD_GT_GTE),            TD(TD_EQ_NEQ), KC_NO,
    KC_NO,  KC_NO, KC_NO, KC_NO,                    KC_NO,

                                    // left thumb cluster
                                           KC_NO,  KC_NO,
                                                   KC_NO,
                                     KC_NO, KC_NO, KC_NO,
    // right hand
    KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
    KC_NO, KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
    KC_NO, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_NO,
    KC_NO, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
    KC_NO, KC_P0,   KC_PDOT, KC_NO,   KC_NO,

    // right thumb cluster
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, KC_NO
  )
};