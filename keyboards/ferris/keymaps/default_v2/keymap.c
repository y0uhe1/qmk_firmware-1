#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT( \
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,   KC_U,       KC_I,            KC_O,           KC_P, \
  LSFT_T(KC_A), LT(3,KC_S),   LT(2,KC_D),   LT(1,KC_F),   KC_G,    KC_H,   LT(4,KC_J), LT(5,KC_K),      LT(6,KC_L),     RSFT_T(KC_SCLN), \
  LCTL_T(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), KC_V,         KC_B,    KC_N,   KC_M,       RALT_T(KC_COMM), RGUI_T(KC_DOT), RCTL_T(KC_SLSH), \
                                            MEH_T(KC_SPC),KC_BSPC, KC_TAB, KC_ENT \
),

[_LAYER1] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,       RSFT(KC_MINS), KC_EQL,        RSFT(KC_JYEN), KC_DEL, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RSFT(KC_RBRC), KC_QUOT,       KC_LBRC,       RSFT(KC_LBRC), XXXXXXX, \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, RSFT(KC_BSLS), RSFT(KC_SCLN), RSFT(KC_QUOT), RSFT(KC_RO),   XXXXXXX, \
                             _______, _______, _______, _______ \
),

[_LAYER2] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,   KC_8, KC_9, KC_DEL, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PEQL, KC_4,   KC_5, KC_6, XXXXXXX, \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, KC_0,    KC_1,   KC_2, KC_3, XXXXXXX, \
                             _______, _______, _______, _______ \
),

[_LAYER3] = LAYOUT( \
  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______ \
),

[_LAYER4] = LAYOUT( \
  KC_ESC,       LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_INT3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,      LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
  LALT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_BSLS, XXXXXXX, XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL, \
                                        _______, _______, _______, _______ \
),

[_LAYER5] = LAYOUT( \
  KC_ESC,       KC_F9, KC_F10, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,      KC_F5, KC_F6,  KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
  LALT(KC_GRV), KC_F1, KC_F2,  KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL, \
                               _______, _______, _______, _______ \
),

[_LAYER6] = LAYOUT( \
  KC_ESC,       KC_WH_L, KC_MS_U, KC_WH_R, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,      KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
  LALT(KC_GRV), KC_BTN1, KC_WH_U, KC_WH_D, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, \
                                  _______, _______, _______, _______ \
) 
};