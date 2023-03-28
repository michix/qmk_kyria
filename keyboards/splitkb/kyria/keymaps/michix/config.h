/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//Save space: https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
  //#define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_HUE_STEP 17
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
  #define RGBLIGHT_LIMIT_VAL 90
  #define RGBLIGHT_LAYERS
#endif

#define EE_HANDS

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150
//#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
//#define PERMISSIVE_HOLD
//#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define COMBO_TERM 30

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_V RALT_T(KC_V)
// Home Row Mod noch working with shifted 9
#define HOME2_A KC_LPRN
#define HOME2_S LGUI_T(KC_LBRC)
#define HOME2_D LSFT_T(KC_RBRC)
// Home Row Mod noch working with shifted 0
#define HOME2_F KC_RPRN
#define HOME_CM_A LSFT_T(KC_A)
#define HOME_CM_R LALT_T(KC_R)
#define HOME_CM_S LGUI_T(KC_S)
#define HOME_CM_T LCTL_T(KC_T)
#define HOME_CM_D RALT_T(KC_D)
#define HOME_HD_R LSFT_T(KC_R)
#define HOME_HD_S LALT_T(KC_S)
#define HOME_HD_N LGUI_T(KC_N)
#define HOME_HD_T LCTL_T(KC_T)
#define HOME_HD_D RALT_T(KC_D)
#define HOME_HDN_R LSFT_T(KC_R)
#define HOME_HDN_S LALT_T(KC_S)
#define HOME_HDN_N LGUI_T(KC_N)
#define HOME_HDN_T LCTL_T(KC_T)
#define HOME_HDN_D RALT_T(KC_D)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RGUI_T(KC_L)
#define HOME_SCLN LALT_T(KC_SCLN)
#define HOME_M RALT_T(KC_M)
#define HOME2_J RCTL_T(KC_4)
#define HOME2_K RSFT_T(KC_5)
#define HOME2_L LALT_T(KC_6)
#define HOME2_SCLN RSFT_T(KC_KP_PLUS)
#define HOME_CM_N RCTL_T(KC_N)
#define HOME_CM_E RGUI_T(KC_E)
#define HOME_CM_I LALT_T(KC_I)
#define HOME_CM_O RSFT_T(KC_O)
#define HOME_CM_H RALT_T(KC_H)
#define HOME_HD_U RCTL_T(KC_U)
#define HOME_HD_E RGUI_T(KC_E)
#define HOME_HD_I LALT_T(KC_I)
#define HOME_HD_A RSFT_T(KC_A)
#define HOME_HD_F RALT_T(KC_F)
#define HOME_HDN_A RCTL_T(KC_A)
#define HOME_HDN_E RGUI_T(KC_E)
#define HOME_HDN_I LALT_T(KC_I)
#define HOME_HDN_H RSFT_T(KC_H)
#define HOME_HDN_U RALT_T(KC_U)

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
// The following makes the keyboard unresponsive...
//#define NO_USB_STARTUP_CHECK
