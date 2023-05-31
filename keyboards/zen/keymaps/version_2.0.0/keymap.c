#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Layers
enum layers {
  L_QWERTY = 0,
  L_MAC,
  L_WIN,
  L_LOWER,
  L_RAISE,
  L_CONF
};

enum taps {
  TD_LANG = 0
};

enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  QWERTY,
	// momentaly
  LOWER,
  RAISE,
  CONF,
  // os
  MAC,
  WIN,
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
#define ML_LOW MO(L_LOWER)
#define ML_RAI MO(L_RAISE)
#define ML_CNF MO(L_CONF)
#define LANG TD(TD_LANG)
#define JA_ZKHK LALT(KC_GRV) //全角半角

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.              .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  |  -=  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |  @`  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | LANG |   A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |  ;+  |  :*  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |              |   N  |   M  |  ,<  |  .>  |  UP  |RShift|
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |LCtrl | CONF |      |      | LOWER| SPACE| Bksp ||  TAB |  ENT | RAISE|  APP | LEFT | DOWN | RIGHT|
 * `------------------------------------------------''------------------------------------------------
 *
 */
[L_QWERTY] = KEYMAP( \
  KC_GESC,    KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  \
  KC_TAB,     KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JA_AT,    \
  TD(TD_LANG),KC_A,    KC_S,    KC_D,     KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JA_CLON,  \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,                    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,  \
  KC_LCTL,    ML_CNF,  _______, _______,  ML_LOW,  KC_SPC, KC_BSPC, KC_TAB, KC_ENT,  ML_RAI,  KC_APP,  KC_LEFT, KC_DOWN, KC_RIGHT  \
),
/* LOWER
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |      |      |      |      |      |              |      |      |      |      |  ^~  |  \|  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |  [{  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |  ]}  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |  /?  |  \_  |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */
[L_LOWER] = KEYMAP( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JA_HAT,  JA_ENVL, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JA_LBRC, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JA_RBRC, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, JA_ENUN, \
  _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),
/* RAISE
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |  F12 |      |      |      | Home | PgUp |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      | End  | PgDn |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |MsBt1 |MsBt2 |      |      |      |              |      |      |      |      | MsU  |      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  DEL ||      |      |      |      | MsL  | MsD  | MsR  |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */
[L_RAISE] = KEYMAP( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, \
  _______, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R  \
),
/* MAC
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | LANG |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |  OPT |  GUI |      |      |      |      ||      |      |      |      |      |      |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */

[L_MAC] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  LANG,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
/* WIN
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | ZKHK |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      | GUI  | LALT |      |      |      ||      |      |      |      |      |      |      |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */

[L_WIN] = KEYMAP( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  JA_ZKHK, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
/* CONF
 * ,-----------------------------------------.              .-----------------------------------------.
 * |      | RESET| MAC  | WIN  |      |      |              |      | RESET| MAC  | WIN  |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------+
 * |      |RGBMOD|RGBSAI|RGBVAI|RGBHUI|      |              |      |RGBMOD|RGBSAI|RGBVAI|RGBHUI|      |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |RGBTOG|RGBSAD|RGBVAD|RGBHUD|      |              |      |RGBTOG|RGBSAD|RGBVAD|RGBHUD|      |
 * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * `------------------------------------------------''------------------------------------------------'
 * 
 */

[L_CONF] = KEYMAP( \
  _______, RESET,   MAC,     WIN,     _______, _______,                   _______, RESET,   MAC,     WIN,     _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, RGB_MOD, RGB_SAI, RGB_VAI, RGB_HUI, _______,                   _______, RGB_MOD, RGB_SAI, RGB_VAI, RGB_HUI, _______, \
  _______, RGB_TOG, RGB_SAD, RGB_VAD, RGB_HUD, _______,                   _______, RGB_TOG, RGB_SAD, RGB_VAD, RGB_HUD, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void switch_layer (uint8_t layer, bool on) {
  if (on) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
};

void type_code(uint8_t keycode){
  register_code (keycode);
  unregister_code (keycode);
};

void set_eisu(void){
  type_code (KC_MHEN);
  type_code (KC_LANG2);
};

void set_kana(void){
  type_code (KC_HENK);
  type_code (KC_LANG1);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // lang
    case EISU:
      if (record->event.pressed) {
        set_eisu();
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        set_kana();
      }
      return false;
      break;
    //layout
    case QWERTY:
      if (record->event.pressed) {
        layer_move(L_QWERTY);
      }
      return false;
      break;
    //momentary layer
    case LOWER:
      switch_layer(L_LOWER, record->event.pressed);
      return false;
      break;
    case RAISE:
      switch_layer(L_RAISE, record->event.pressed);
      return false;
      break;
    case CONF:
      switch_layer(L_CONF, record->event.pressed);
      return false;
      break;
    //os
    case MAC:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<L_MAC);
      }
      return false;
      break;
    case WIN:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<L_WIN);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  persistant_default_layer_set(1UL<<L_WIN);
  layer_move(L_QWERTY);
};

// control IME
void dance_lang (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    set_eisu();
  } else {
    set_kana();
  }
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LANG]  = ACTION_TAP_DANCE_FN (dance_lang)
};