/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include QMK_KEYBOARD_H
#include "features/casemodes.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// Automatically enable sniping-mode on the pointer layer.
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LAYER4

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// #define ESC_MED LT(LAYER_MEDIA, KC_ESC)
// #define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
// #define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
// #define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
// #define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define _L_PTR(KC) LT(_LAYER4, KC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum layers {
    _QWERTY = 0,
    // _DE,
    // _COLEMAK_DH,
    // _HANDS_DOWN,
    // _HANDS_DOWN_NEU,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4
};

/* Combos */
enum combo_events {
  CB_COPY,
  CB_CUT,
  CB_PASTE,
  CB_TAB,
  CB_ESC,
  CB_CAPSLOCK,
  CB_MINUS,
  CB_EQUALS,
  CB_UNDERSCORE,
  CB_QUOT,
  CB_DQUOT,
  CB_BTICK,
  CB_EXCL,
  CB_PIPE,
  CB_BSLASH,
  CB_BSPC,
  CB_LSHFT,
  CB_RSHFT,
  CB_ENTER,
  CB_DEL,
  CB_FLAYER,
  CB_LWIN_L,
  CB_LWIN_R,
  CB_OSS_L,
  CB_OSS_R,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM copy_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {HOME_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM dquot_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM btick_combo[] = {KC_C, HOME_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {HOME_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM bslash_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM lshft_combo[] = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM rshft_combo[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM del_combo[] = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM flayer_combo[] = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM oss_combo_l[] = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM oss_combo_r[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM lwin_combo_l[] = {HOME_A, HOME_S, HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM lwin_combo_r[] = {HOME_J, HOME_K, HOME_L, HOME_SCLN, COMBO_END};

combo_t key_combos[] = {
  [CB_COPY] = COMBO_ACTION(copy_combo),
  [CB_CUT] = COMBO_ACTION(cut_combo),
  [CB_PASTE] = COMBO_ACTION(paste_combo),
  [CB_TAB] = COMBO_ACTION(tab_combo),
  [CB_ESC] = COMBO_ACTION(esc_combo),
  [CB_CAPSLOCK] = COMBO_ACTION(capslock_combo),
  [CB_MINUS] = COMBO_ACTION(minus_combo),
  [CB_EQUALS] = COMBO_ACTION(equals_combo),
  [CB_UNDERSCORE] = COMBO_ACTION(underscore_combo),
  [CB_QUOT] = COMBO_ACTION(quot_combo),
  [CB_DQUOT] = COMBO_ACTION(dquot_combo),
  [CB_BTICK] = COMBO_ACTION(btick_combo),
  [CB_EXCL] = COMBO_ACTION(excl_combo),
  [CB_PIPE] = COMBO_ACTION(pipe_combo),
  [CB_BSLASH] = COMBO_ACTION(bslash_combo),
  [CB_LSHFT] = COMBO_ACTION(lshft_combo),
  [CB_RSHFT] = COMBO_ACTION(rshft_combo),
  [CB_BSPC] = COMBO_ACTION(bspc_combo),
  [CB_ENTER] = COMBO_ACTION(enter_combo),
  [CB_DEL] = COMBO_ACTION(del_combo),
  [CB_FLAYER] = COMBO_ACTION(flayer_combo),
  [CB_OSS_L] = COMBO_ACTION(oss_combo_l),
  [CB_OSS_R] = COMBO_ACTION(oss_combo_r),
  [CB_LWIN_L] = COMBO_ACTION(lwin_combo_l),
  [CB_LWIN_R] = COMBO_ACTION(lwin_combo_r),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CB_COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case CB_CUT:
      if (pressed) {
        tap_code16(LCTL(KC_X));
      }
      break;
    case CB_PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
    case CB_TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case CB_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case CB_CAPSLOCK:
      if (pressed) {
        toggle_caps_word();
      }
      break;
    case CB_MINUS:
      if (pressed) {
        tap_code16(KC_MINS);
      }
      break;
    case CB_EQUALS:
      if (pressed) {
        tap_code16(KC_EQUAL);
      }
      break;
    case CB_UNDERSCORE:
      if (pressed) {
        tap_code16(KC_UNDS);
      }
      break;
    case CB_QUOT:
      if (pressed) {
        tap_code16(KC_QUOT);
      }
      break;
    case CB_DQUOT:
      if (pressed) {
        tap_code16(KC_DQUO);
      }
      break;
    case CB_BTICK:
      if (pressed) {
        tap_code16(KC_GRV);
      }
      break;
    case CB_EXCL:
      if (pressed) {
        tap_code16(KC_EXLM);
      }
      break;
    case CB_PIPE:
      if (pressed) {
        tap_code16(KC_PIPE);
      }
      break;
    case CB_BSLASH:
      if (pressed) {
        tap_code16(KC_BSLS);
      }
      break;
    case CB_LSHFT:
      if (pressed) {
          set_oneshot_mods(MOD_BIT(KC_LSFT));
      }
      break;
    case CB_RSHFT:
      if (pressed) {
          set_oneshot_mods(MOD_BIT(KC_RSFT));
      }
      break;
    case CB_BSPC:
      if (pressed) {
        tap_code16(KC_BSPC);
      }
      break;
    case CB_ENTER:
      if (pressed) {
        tap_code16(KC_ENTER);
      }
      break;
    case CB_DEL:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;
    case CB_FLAYER:
      if (pressed) {
        set_oneshot_layer(_LAYER3, ONESHOT_START);
      }
      break;
    case CB_OSS_L:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
      }
      break;
    case CB_OSS_R:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_RSFT));
      }
      break;
    case CB_LWIN_L:
      if (pressed) {
        tap_code16(KC_APPLICATION);
      }
      break;
    case CB_LWIN_R:
      if (pressed) {
        tap_code16(KC_APPLICATION);
      }
      break;
  }
}

/* Tap dancing */
/*enum {*/
    /*TD_Q_ESC*/
/*};*/

/*qk_tap_dance_action_t tap_dance_actions[] = {*/
    /*[TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)*/
/*};*/

/*https://github.com/andrewjrae/kyria-keymap*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_V:
            return TAPPING_TERM + 100;
        case HOME_M:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_D:
        case HOME_K:
        case HOME_V:
        case HOME_M:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Always use Combos from QWERTY layer
#define COMBO_ONLY_FROM_LAYER _QWERTY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * -----------------------------------.                              ,-----------------------------------
 * |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |
 * |    <TAB>    |      |      |      |                              |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|                              |------+------+------+------+------+
 * |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |
 * |LShift|  ALT | GUI  | CTRL |      |                              |      | CTRL |  GUI |  ALT |RShift|
 * +------+------+------+------+------+                              +------+------+------+------+------+
 * |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  | ,  < | . >  | /  ? |
 * |      |      |      |ALTGR |      |                              |      |ALTGR |      |      |      |
 * --------------+------+------+------+------|         |------+------+------+------+------+--------------
 *                             |Space |Space |         |backsp|Backsp|Backsp|
 *                             |Layr2 |Layr4 |         |Layr4 |Layr3 |Layr1 |
 *                             --------------|         `---------------------
 */
    [_QWERTY] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_Q   , KC_W   , KC_E   , KC_R   , KC_T ,      KC_Y , KC_U   , KC_I    , KC_O   , KC_P      ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      HOME_A , HOME_S , HOME_D , HOME_F , KC_G ,      KC_H , HOME_J , HOME_K  , HOME_L , HOME_SCLN ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_Z   , KC_X   , KC_C   , HOME_V , KC_B ,      KC_N , HOME_M , KC_COMM , KC_DOT , _L_PTR(KC_SLSH),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯

      LT(_LAYER2, KC_SPACE), LT(_LAYER4, KC_SPACE),   LT(_LAYER4, KC_BACKSPACE), LT(_LAYER1, KC_BACKSPACE), LT(_LAYER3, KC_BACKSPACE)
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
    ),
/*
 * Layer1: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |  ^   |  &   |  *   |  (   |  )   |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   !    |  {   |  [   |  ]   |  }   |  '"  |                              |  <-  |  v   |  ^   |  ->  |  NO  |  | \   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  (   |  <   |  >   |  )   |  `   |      |      |  |      |      | HOME |PGDOWN|PGUP  | END  |  \   |   NO   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LAYER1] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────╮
      KC_EXLM             , KC_AT               , KC_HASH              , KC_DLR               , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN  , KC_RPRN ,
  // ├─────────────────────────────────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────┤
      LCTL(LGUI(KC_LEFT)) , LSFT(LGUI(KC_LEFT)) , LSFT(LGUI(KC_RIGHT)) , LCTL(LGUI(KC_RIGHT)) , KC_QUOT , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_RSFT ,
  // ├─────────────────────────────────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────┤
      LGUI(KC_LEFT)       , LSFT(LCTL(KC_TAB))  , LCTL(KC_TAB)         , LGUI(KC_RIGHT)       , KC_GRV  , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , KC_BSLS ,
  // ├─────────────────────────────────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────┤
                                                                            _______, _______,             _______,  _______, _______
                                                      //                   ╰───────────────────────────╯ ╰───────────────────────────╯
    ),
/*
 * Layer2: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   1    |  (   |  [   |  ]   |  )   |  =   |                              |  -   |  4   |  5   |  6   |  +   |   ,    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  {   |  <   |  >   |  }   |  |   |      |      |  |      | '"   |  .   |  1   |  2   |  3   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |Enter |  0   |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LAYER2] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────╮
      KC_1    , KC_2          , KC_3         , KC_4    , KC_5     , KC_6    , KC_7    , KC_8    , KC_9    , KC_0       ,
  // ├───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────┤
      HOME2_A , HOME2_S       , HOME2_D      , HOME2_F , KC_EQUAL , KC_MINS , HOME2_J , HOME2_K , HOME2_L , HOME2_SCLN ,
  // ├───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────┤
      KC_LCBR , LSFT(KC_COMM) , LSFT(KC_DOT) , KC_RCBR , KC_PIPE  , KC_DOT  , KC_1    , KC_2    , KC_3    , KC_SLSH    ,
  // ╰───────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────╯
                                    KC_NO, KC_NO,                   KC_ENT, KC_0, KC_NO
             //                    ╰─────────────────────────────╯ ╰───────────────────────────╯
    ),
/*
 * Layer3: Function Keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F1    |  F11 |  F12 |      |      |PRINT |                              |  -   |  F4  |  F5  |  F6  |      |  F10   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LAYER3] = LAYOUT(
  // ╭───────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7 , KC_F8 , KC_F9 , KC_F10  ,
  // ├───────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_F11  , KC_F12  , _______ , _______ , KC_PSCR , _______ , KC_F4 , KC_F5 , KC_F6 , _______ ,
  // ├───────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      _______ , _______ , _______ , _______ , _______ , _______ , KC_F1 , KC_F2 , KC_F3 , _______ ,
  // ╰───────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        _______, _______,               _______,  _______, _______
  //                   ╰─────────────────────────────╯ ╰───────────────────────────╯
    ),
/*
 * Layer4: media, mouse
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Btn5 | Btn3 | Btn2 | Btn1 | Btn4 |                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Mute |      | VolDn| VolUp|      |      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LAYER4] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
      QK_BOOT    , _______    , _______    , _______    , _______    , _______       , _______       , _______     , _______        , QK_BOOT ,
  // ├──────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
      KC_MS_BTN5 , KC_MS_BTN4 , KC_MS_BTN2 , KC_MS_BTN1 , KC_MS_BTN3 , KC_WH_L       , KC_WH_D       , KC_WH_U     , KC_WH_R        , _______ ,
  // ├──────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
      KC_MUTE    , _______    , KC_VOLD    , KC_VOLU    , _______    , KC_MS_WH_LEFT , KC_MS_WH_DOWN , KC_MS_WH_UP , KC_MS_WH_RIGHT , _______ ,
  // ╰──────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                                       _______, _______,               _______, KC_MS_BTN1, KC_MS_BTN2
               //                     ╰─────────────────────────────╯ ╰───────────────────────────╯
    ),

};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_LAYER4);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(_LAYER4);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif