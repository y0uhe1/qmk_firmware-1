/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// Underglow configuration
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#undef DIRECT_PINS
#define DIRECT_PINS { \
    { D4, E6, B3, D2, F6 }, \
    { C6, B4, B2, F4, F7 }, \
    { D7, B5, B6, F5, B1 }, \
    { D0, D1, NO_PIN, NO_PIN, NO_PIN } \
}

#undef DIRECT_PINS_RIGHT
#define DIRECT_PINS_RIGHT { \
    { F6, D2, B3, E6, D4 }, \
    { F7, F4, B2, B4, C6 }, \
    { B1, F5, B6, B5, D7 }, \
    { D1, D0, NO_PIN, NO_PIN, NO_PIN } \
}

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3

#define MOUSEKEY_INERTIA
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY             0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL          16
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED         32
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX       32
#undef MOUSEKEY_FRICTION
#define MOUSEKEY_FRICTION          24
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA        1

#define MASTER_LEFT
#define USB_POLLING_INTERVAL_MS    10