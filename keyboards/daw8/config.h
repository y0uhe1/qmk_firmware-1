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

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

#define ENCODERS_PAD_A { GP1, GP4 }
#define ENCODERS_PAD_B { GP2, GP3 }

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