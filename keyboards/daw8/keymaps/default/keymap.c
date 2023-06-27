// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
    * ,---------------------------.
    * | top 0 | top 1 | encoder 0 |
    * +-------+-------+-----------+
    * | mid 0 | mid 1 | encoder 1 |
    * +-------+-------+-----------+-------.
    * | bot 0 | bot 1 |   bot 2   | bot 3 |
    * '-----------------------------------'
    * encoder 1 key press is not working... 
    */
    [0] = LAYOUT_8_rotary(
        LCTL(KC_Z),LCTL(KC_Y),KC_MUTE, \
        KC_WBAK,   KC_WFWD,   XXXXXXX, \
        KC_MPRV,   KC_MSTP,   KC_MPLY,   KC_MNXT
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}