#include QMK_KEYBOARD_H

#define _ALPHA1 0
#define _ALPHA2 1
#define _SYM1 2
#define _SYM2 3
#define _NUM 4
#define _SYS 5
#define _FUNC 6
#define _ALPHA1CAP 7
#define _ALPHA2CAP 8

enum custom_keycodes {
    ALPHA1 = SAFE_RANGE,
    ALPHA2,
    SYM1,
    SYM2,
    NUM,
    SYS,
    FUNC,
    ALPHA1CAP,
    ALPHA2CAP
};

// combo
const uint16_t PROGMEM caps_combo[] = {LT(_SYS, KC_T), LT(_SYM1, KC_N), LT(_SYM2, KC_S), COMBO_END};
const uint16_t PROGMEM func_combo[] = {LT(_SYM2, KC_O), LT(_SYM1, KC_E), LT(_SYS, KC_A), COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),
    COMBO(func_combo, OSL(_FUNC))
};

// tap dance
enum {
    TD_MINS,
    TD_EQL,
    TD_LBRC,
    TD_INT3,
    TD_QUOT,
    TD_SCLN,
    TD_RBRC,
    TD_BSLS,
    TD_SLSH,
    TD_COMM,
    TD_DOT,
    TD_LEFT,
    TD_CV,
    TD_HOMEDEL,
    TD_ENDW,
    TD_CTLAGRV,
};

// tap hold
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {// list all tap dance keycodes with tap-hold configurations
        case TD(TD_MINS):
        case TD(TD_EQL):
        case TD(TD_LBRC):
        case TD(TD_INT3):
        case TD(TD_QUOT):
        case TD(TD_SCLN):
        case TD(TD_RBRC):
        case TD(TD_BSLS):
        case TD(TD_SLSH):
        case TD(TD_COMM):
        case TD(TD_DOT):
        case TD(TD_LEFT):
        case TD(TD_CV):
        case TD(TD_HOMEDEL):
        case TD(TD_ENDW):
        case TD(TD_CTLAGRV):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_MINS] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, RSFT(KC_MINS)), // tap -, hold =
    [TD_EQL] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, RSFT(KC_EQL)),    // tap ^, hold ~
    [TD_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, RSFT(KC_LBRC)), // tap @, hold `
    [TD_INT3] = ACTION_TAP_DANCE_TAP_HOLD(KC_INT3, RSFT(KC_INT3)), // tap "\", hold |
    [TD_QUOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, RSFT(KC_QUOT)), // tap :, hold *
    [TD_SCLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, RSFT(KC_SCLN)), // tap ;, hold +
    [TD_RBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_RBRC, RSFT(KC_RBRC)), // tap {, hold }
    [TD_BSLS] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSLS, RSFT(KC_BSLS)), // tap [, hold ]
    [TD_SLSH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, RSFT(KC_SLSH)), // tap /, hold ?
    [TD_COMM] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, RSFT(KC_COMM)), // tap ,, hold <
    [TD_DOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, RSFT(KC_DOT)),    // tap ., hold >
    [TD_LEFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT, KC_TAB),        // tap left, hold tab
    [TD_CV] = ACTION_TAP_DANCE_TAP_HOLD(RCTL(KC_V), RCTL(KC_C)),   // tap paste, hold copy
    [TD_HOMEDEL] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, KC_DEL),     // tap home, hold del
    [TD_ENDW] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, RCTL(KC_W)),     // tap end, hold ctrl+w
    [TD_CTLAGRV] = ACTION_TAP_DANCE_TAP_HOLD(KC_LCTL, LALT(KC_GRV)),   // tap end, hold ctrl+w
};
// Symbols for JIS
#define JP_UNDR RSFT(KC_INT1) // _

#define MT_TAB_KANA MT(KC_TAB, LALT(KC_GRV))

// #define MT_LSFT_AL1 MT(KC_LSFT, TO(_ALPHA1))
// TODO: ctrl+shif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // |               |               |               |               |               |               |               |               |
    [_ALPHA1] = LAYOUT_split_3x3( \
                        CTL_T(KC_P),    GUI_T(KC_U),    ALT_T(KC_Y),    ALT_T(KC_D),    GUI_T(KC_H),    CTL_T(KC_G), \
                        LT(_SYM2, KC_O),LT(_SYM1, KC_E),LT(_SYS, KC_A), LT(_SYS, KC_T), LT(_SYM1, KC_N),LT(_SYM2, KC_S), \
        LT(_NUM, KC_I),                 MEH_T(KC_SPC),  QK_REP,         OSL(_ALPHA1CAP),OSL(_ALPHA2),                   LT(_NUM, KC_R) \
    ),
    // |               |               |               |               |               |               |               |               |
    [_ALPHA2] = LAYOUT_split_3x3( \
                        KC_Q,           KC_W,           KC_F,           KC_J,           KC_K,           KC_L, \
                        KC_X,           KC_C,           KC_V,           KC_B,           KC_M,           KC_COMM, \
        KC_Z,                           OSM(KC_LSFT),   XXXXXXX,        XXXXXXX,        OSL(_ALPHA2CAP),                KC_DOT \
    ),
    // |               |               |               |               |               |               |               |               |
    [_SYM1] = LAYOUT_split_3x3( \
                        LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     RSFT(KC_4),     RSFT(KC_5),     RSFT(KC_6), \
                        LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     RSFT(KC_0),     KC_MINS,        RSFT(KC_MINS), \
        KC_LCTL,                        KC_LSFT,        _______,        XXXXXXX,        KC_RALT,                        KC_LCTL \
    ),
    [_SYM2] = LAYOUT_split_3x3( \
                        TD(TD_RBRC),    TD(TD_SCLN),    TD(TD_EQL),     TD(TD_EQL),     TD(TD_INT3),    TD(TD_LBRC), \
                        TD(TD_BSLS),    TD(TD_QUOT),    TD(TD_COMM),    TD(TD_DOT),     JP_UNDR,        TD(TD_SLSH), \
        _______,                        _______,        _______,        XXXXXXX,        KC_RALT,                        _______ \
    ),
    // |               |               |               |               |               |               |               |               |
    [_NUM] = LAYOUT_split_3x3( \
                        CTL_T(KC_1),    GUI_T(KC_2),    ALT_T(KC_3),    ALT_T(KC_4),    GUI_T(KC_5),    CTL_T(KC_6), \
                        KC_7,           KC_8,           KC_9,           KC_0,           KC_PDOT,        KC_PPLS, \
        KC_MINS,                        _______,        _______,        XXXXXXX,        KC_RALT,                        RSFT(KC_MINS) \
    ),
    // |               |               |               |               |               |               |               |               |
    [_SYS] = LAYOUT_split_3x3( \
                        KC_ESC,         RCTL(KC_Z),     RCTL(KC_Y),     TD(TD_CV),      KC_UP,          KC_BSPC, \
                        TD(TD_HOMEDEL), TD(TD_ENDW),    RCTL(KC_F),     TD(TD_LEFT),    KC_DOWN,        KC_RIGHT, \
        TD(TD_CTLAGRV),                 _______,        _______,        XXXXXXX,        KC_RALT,                        KC_ENT \
    ),
    // |               |               |               |               |               |               |               |               |
    [_FUNC] = LAYOUT_split_3x3( \
                        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6, \
                        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12, \
        KC_LCTL,                        _______,        _______,        XXXXXXX,        _______,                        KC_LCTL \
    ),
    // |               |               |               |               |               |               |               |               |
    [_ALPHA1CAP] = LAYOUT_split_3x3( \
                        LSFT(KC_P),     LSFT(KC_U),     LSFT(KC_Y),     RSFT(KC_D),     RSFT(KC_H),     RSFT(KC_G), \
                        LSFT(KC_O),     LSFT(KC_E),     LSFT(KC_A),     RSFT(KC_T),     RSFT(KC_N),     RSFT(KC_S),       \
        LSFT(KC_I),                     _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,                         RSFT(KC_R) \
    ),
    // |               |               |               |               |               |               |               |               |
    [_ALPHA2CAP] = LAYOUT_split_3x3( \
                        LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_F),     RSFT(KC_J),     RSFT(KC_K),     RSFT(KC_L), \
                        LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     RSFT(KC_B),     RSFT(KC_M),     RSFT(KC_COMM), \
        LSFT(KC_Z),                     _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,                         RSFT(KC_DOT) \
    ),
};
