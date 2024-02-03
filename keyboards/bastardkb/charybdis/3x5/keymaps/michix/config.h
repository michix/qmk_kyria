#pragma once

#undef MASTER_RIGHT
#define MASTER_LEFT

/* Trackball */
#ifndef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_ENABLE
#endif
#undef POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_LEFT

/* Trackball angle adjustment. */
/* #define ROTATIONAL_TRANSFORM_ANGLE -25 */
#undef ROTATIONAL_TRANSFORM_ANGLE
#define ROTATIONAL_TRANSFORM_ANGLE 40
#define POINTING_DEVICE_INVERT_Y
#undef POINTING_DEVICE_INVERT_X

/* See https://docs.qmk.fm/#/feature_pointing_device?id=pointing-device-auto-mouse */
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

/* RGB settings. */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_LED_COUNT 36
#    define RGB_MATRIX_SPLIT \
        { 18, 18 }
#endif

/* #define EE_HANDS */

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150
//#define TAPPING_TERM_PER_KEY

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
/* #define SPLIT_USB_DETECT */

