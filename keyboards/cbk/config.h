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

/* Serial settings */
#define USE_SERIAL
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN GP3
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_USB_DETECT
#define SERIAL_USE_MULTI_TRANSACTION
/* communication between sides */
#define SERIAL_PIO_USE_PIO1

/* Double tap reset button to enter bootloader */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define MASTER_LEFT
#define USB_POLLING_INTERVAL_MS    10

#define TAPPING_TERM_PER_KEY

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
/* pin assign */
// right
// D0 -> GP26
// D1 -> GP27
// D2 -> GP28
// D3 -> GP29
// D4 -> GP6
// D5 -> GP7
// D6 -> GP0
// left
// D7 -> GP1
// D8 -> GP2
// D9 -> GP4
// D10 -> GP3