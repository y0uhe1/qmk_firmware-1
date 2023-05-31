#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// JA alias
#define JA_CLON KC_QUOT // : and *
#define JA_AT   KC_LBRC // @ and `
#define JA_HAT  KC_EQL // ^ and ~
#define JA_ENUN KC_RO // \ and _
#define JA_ENVL KC_JYEN // \ and |
#define JA_LBRC KC_RBRC // [ and {
#define JA_RBRC KC_BSLS // ] and }
#define JA_ZKHK LALT(KC_GRV) //全角半角
#define LOW MO(_LOWER)
#define RAI MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.              .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |  @`  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |  ;+  |  :*  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |              |   N  |   M  |  ,<  |  .>  |  /?  |  _\  |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * | Ctrl |  OS  | Alt  |  GUI | LOWER| Space|Delete|| Enter| Space| RAISE|  -=  |  ^~  |  ¥|  | Ctrl |
 * `------------------------------------------------''------------------------------------------------
 */
[_QWERTY] = KEYMAP( \
  KC_GESC,    KC_1,    KC_2,    KC_3,      KC_4,   KC_5,                       KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,     KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,                       KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    JA_AT,    \
  KC_CAPS,    KC_A,    KC_S,    KC_D,      KC_F,   KC_G,                       KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, JA_CLON,  \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,      KC_V,   KC_B,                       KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JA_ENUN,  \
  KC_LCTL,    KC_LGUI, KC_LALT, KC_LGUI,   LOW,    KC_SPC,  KC_DEL,  KC_ENT,   KC_SPACE,   RAI,     KC_MINS, JA_HAT,  JA_ENVL, KC_RCTL   \
),
/* LOWER
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |      |      |      |      |      |              |      |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |  ]}  |  4   |  5   |  6   | Home | PgUp |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |jp/en |      |      |      |      |      |              |  [{  |  1   |  2   |  3   | End  | PgDn |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |  0   |      |      |  Up  |      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |      | Left | Down | Right|
 * `------------------------------------------------''------------------------------------------------'
 * 
 */
[_LOWER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______, \
  _______, _______, _______, _______, _______, _______,                   JA_RBRC, KC_4,    KC_5,    KC_6,    KC_HOME, KC_PGUP, \
  JA_ZKHK, _______, _______, _______, _______, _______,                   JA_LBRC, KC_1,    KC_2,    KC_3,    KC_END,  KC_PGDN, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_0,    _______, _______, KC_UP,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
),
/* RAISE
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |              |      |RGBSAI|RGBVAI|RGBHUI|      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |jp/en |  F6  |  F7  |  F8  |  F9  | F10  |              |      |RGBSAD|RGBVAD|RGBHUD|      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |RGBMOD|RGBTOG|      |      |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */
[_RAISE] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     _______, RGB_SAI, RGB_VAI, RGB_HUI, _______, _______, \
  JA_ZKHK, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    _______, RGB_SAD, RGB_VAD, RGB_HUD, _______, _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_TOG, _______, _______  \
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}