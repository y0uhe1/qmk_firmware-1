// Copyright 2023 y0uhe1 (@y0uhe1)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#include "config_common.h"

/* Serial communication */
// #define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP10
// #define SERIAL_USART_RX_PIN GP10

/* Double tap reset button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#undef DIRECT_PINS
#define DIRECT_PINS { \
    { GP6, GP28, GP26 }, \
    { GP7, GP29, GP27 }, \
    { GP0, GP1, GP2 } \
}

#undef DIRECT_PINS_RIGHT
#define DIRECT_PINS_RIGHT { \
    { GP26, GP28, GP6 }, \
    { GP27, GP29, GP7 }, \
    { GP2, GP1, GP0 } \
}

#define MASTER_LEFT
#define USB_POLLING_INTERVAL_MS    10

// GP26 -> D0
// GP27 -> D1
// GP28 -> D2
// GP29 -> D3
// GP6 -> D4
// GP7 -> D5
// GP0 -> D6

// GP3 -> D10
// GP4 -> D9
// GP2 -> D8
// GP1 -> D7