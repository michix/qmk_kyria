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
#include QMK_KEYBOARD_H
#include "features/casemodes.h"
#include <keymap_german.h>

enum layers {
    _QWERTY = 0,
    _DE,
    _COLEMAK_DH,
    _HANDS_DOWN,
    _HANDS_DOWN_NEU,
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
        tap_code16(KC_LEFT_GUI);
      }
      break;
    case CB_LWIN_R:
      if (pressed) {
        tap_code16(KC_LEFT_GUI);
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

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_sethsv(HSV_GREEN);
    rgblight_mode(RGBLIGHT_MODE_BREATHING);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _LAYER1:
            rgblight_sethsv(HSV_SPRINGGREEN);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _LAYER2:
            rgblight_sethsv(HSV_AZURE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _LAYER3:
            rgblight_sethsv(HSV_ORANGE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _LAYER4:
            rgblight_sethsv(HSV_PURPLE);
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        default:
            switch (biton32(default_layer_state)) {
                case _QWERTY:
                    rgblight_sethsv(HSV_GREEN);
                    rgblight_mode(RGBLIGHT_MODE_BREATHING);
                    break;
                case _COLEMAK_DH:
                    rgblight_sethsv(HSV_YELLOW);
                    rgblight_mode(RGBLIGHT_MODE_BREATHING);
                    break;
                case _HANDS_DOWN:
                    rgblight_sethsv(HSV_CYAN);
                    rgblight_mode(RGBLIGHT_MODE_BREATHING);
                    break;
                case _HANDS_DOWN_NEU:
                    rgblight_sethsv(HSV_WHITE);
                    rgblight_mode(RGBLIGHT_MODE_BREATHING);
                    break;
                default:
                    rgblight_sethsv(HSV_RED);
                    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                    break;
            }
            break;
    }
    return state;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  NO    |
 * |        |    <TAB>    |      |      |      |                              |   Y  |   U  |   I  |   O  |   P  |  NO    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Q    |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  P     |
 * | 2:ESC  |LShift|  ALT | GUI  | CTRL |      |                              |      | CTRL |  GUI |  ALT |RShift|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  | ESC  |COLEMA|  |      | TAB  |   N  |   M  | ,  < | . >  | /  ? | /  ?   |
 * |        |      |      |      |ALTGR |      |      |      |  |      |      |      |ALTGR |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC  |Space |Enter |      |  |      |Del   |Backsp|Teams |      |
 *                        |      |      |Layr2 |Layr4 | ESC  |  | TAB  |Layr3 |Layr1 |Mute  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
      KC_Q, HOME_A, HOME_S, HOME_D, HOME_F, KC_G,       KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_P,
      _______, KC_Z, KC_X, KC_C, HOME_V, KC_B, KC_ESC, DF(_COLEMAK_DH), _______, KC_TAB, KC_N, HOME_M, KC_COMM, KC_DOT, KC_SLSH, _______,

      RGB_MODE_FORWARD,  KC_ESC, LT(_LAYER2, KC_SPC), LT(_LAYER4, KC_ENT), KC_ESC,
      KC_TAB, LT(_LAYER1, KC_BACKSPACE), LT(_LAYER3, KC_DEL), RCS(KC_M), RGB_MODE_REVERSE
    ),
 /*
  * Layer: DE
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |  Ü   |      |  Ö   |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |  Ä   |  ß   |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_DE] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_BSLS,
      KC_EXLM, LCTL(LGUI(KC_LEFT)), LSFT(LGUI(KC_LEFT)), LSFT(LGUI(KC_RIGHT)), LCTL(LGUI(KC_RIGHT)),KC_QUOT,                                                    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RSFT,   KC_BSLS,
      _______, LGUI(KC_LEFT), LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), LGUI(KC_RIGHT), KC_GRV, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END,   KC_BSLS, KC_NO,
                                 _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______
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
      _______, KC_1, KC_2,  KC_3, KC_4,  KC_5,                                                  KC_6, KC_7, KC_8, KC_9,  KC_0, _______,
      KC_1, HOME2_A, HOME2_S, HOME2_D, HOME2_F, KC_EQUAL,                                     KC_MINS, HOME2_J, HOME2_K,  HOME2_L, HOME2_SCLN, KC_COMM,
      _______, KC_LCBR, LSFT(KC_COMM), LSFT(KC_DOT), KC_RCBR, KC_PIPE, _______, _______, _______, KC_QUOT, KC_DOT, KC_1,  KC_2, KC_3, KC_SLSH, _______,
                                 _______, _______, _______, _______, _______,  _______,  KC_ENT, KC_0, _______, _______
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
      _______, KC_F1, KC_F2,  KC_F3, KC_F4,  KC_F5,                                                  KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, _______,
      KC_F1, KC_F11, KC_F12, _______, _______, KC_PSCR,                      _______, KC_F4, KC_F5,  KC_F6, _______,   KC_F10,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,  KC_F2, KC_F3, _______, _______,
                                 _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______
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
      _______, _______, 	  _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,
      _______, KC_MS_BTN5, KC_MS_BTN4, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      _______, KC_MUTE, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Base Layer: COLEMAK_DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  NO    |
 * |        |    <TAB>    |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Q    |   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |  O   |  ; :   |
 * | 2:ESC  |LShift|  ALT | GUI  | CTRL |      |                              |      | CTRL |  GUI |  ALT |RShift|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   D  |   V  | ESC  |QWERTY|  |      | TAB  |   K  |   H  | ,  < | . >  | /  ? |        |
 * |        |      |      |      |ALTGR |      |      |      |  |      |      |      |ALTGR |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC  |Space |Enter |      |  |      |Del   |Backsp|Teams |      |
 *                        |      |      |Layr2 |Layr4 | ESC  |  | TAB  |Layr3 |Layr1 |Mute  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
      KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B,                            /* split */ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_NO,
      KC_Q, HOME_CM_A, HOME_CM_R, HOME_CM_S, HOME_CM_T, KC_G,  /* split */ KC_M, HOME_CM_N, HOME_CM_E, HOME_CM_I, HOME_CM_O, KC_SCLN,
      _______, KC_Z, KC_X, KC_C, HOME_CM_D, KC_V, KC_ESC, DF(_HANDS_DOWN), /* split */ _______, KC_TAB, KC_K, HOME_CM_H, KC_COMM, KC_DOT, KC_SLSH, _______,

      RGB_MODE_FORWARD,  KC_ESC, LT(_LAYER2, KC_SPC), LT(_LAYER4, KC_ENT), KC_ESC,
      KC_TAB, LT(_LAYER3, KC_DEL), LT(_LAYER1, KC_BACKSPACE), RCS(KC_M), RGB_MODE_REVERSE
    ),
/*
 * Base Layer: HANDS DOWN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   C  |   H  |   P  |   V  |                              |   K  |   Y  |   O  |   J  | /  ? |  NO    |
 * |        |    <TAB>    |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Q    |   R  |   S  |  N   |   T  |   G  |                              |   W  |   U  |   E  |   I  |  A   | /  ?   |
 * | 2:ESC  |LShift|  ALT | GUI  | CTRL |      |                              |      | CTRL |  GUI |  ALT |RShift|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   X  |   M  |   L  |   D  |   B  | ESC  |QWERTY|  |      | TAB  |   Z  |   F  | '  " | , <  | . >  |        |
 * |        |      |      |      |ALTGR |      |      |      |  |      |      |      |ALTGR |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC  |Space |Enter |      |  |      |Del   |Backsp|Teams |      |
 *                        |      |      |Layr2 |Layr4 | ESC  |  | TAB  |Layr3 |Layr1 |Mute  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // See http://www.keyboard-layout-editor.com/#/gists/ccde36fea8e8641760bf8b8f2532698e
    [_HANDS_DOWN] = LAYOUT(
      KC_ESC, KC_Q, KC_C, KC_H, KC_P, KC_V,                            /* split */ KC_K, KC_Y, KC_O, KC_J, KC_SLSH, KC_NO,
      KC_Q, HOME_HD_R, HOME_HD_S, HOME_HD_N, HOME_HD_T, KC_G,  /* split */ KC_W, HOME_HD_U, HOME_HD_E, HOME_HD_I, HOME_HD_A, KC_SLSH,
      _______, KC_X, KC_M, KC_L, HOME_HD_D, KC_B, KC_ESC, DF(_HANDS_DOWN_NEU), /* split */ _______, KC_TAB, KC_Z, HOME_HD_F, KC_SCLN, KC_COMM, KC_DOT, _______,

      RGB_MODE_FORWARD,  KC_ESC, LT(_LAYER2, KC_SPC), LT(_LAYER4, KC_ENT), KC_ESC,
      KC_TAB, LT(_LAYER3, KC_DEL), LT(_LAYER1, KC_BACKSPACE), RCS(KC_M), RGB_MODE_REVERSE
    ),
/*
 * Base Layer: HANDS DOWN Neu
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |   F  |   M  |   P  |   V  |                              |   /  |   .  |   Q  |   ;  |      |        |
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   W    |   R  |   S  |  N   |   T  |   G  |                              |   ,  |   A  |   E  |   I  |  H   |   J    |
 * | 2:ESC  |LShift|  ALT | GUI  | CTRL |      |                              |      | CTRL |  GUI |  ALT |RShift|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   X  |   C  |   L  |   D  |   B  | ESC  |QWERTY|  |      | TAB  |   Z  |   U  |   O  |   Y  |  K   |        |
 * |        |      |      |      |ALTGR |      |      |      |  |      |      |      |ALTGR |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC  |Space |Enter |      |  |      |Del   |Backsp|Teams |      |
 *                        |      |      |Layr2 |Layr4 | ESC  |  | TAB  |Layr3 |Layr1 |Mute  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // See http://www.keyboard-layout-editor.com/#/gists/ccde36fea8e8641760bf8b8f2532698e
    [_HANDS_DOWN_NEU] = LAYOUT(
      KC_NO, KC_NO, KC_F, KC_M, KC_P, KC_V,                /* split */ KC_SLSH, KC_DOT, KC_Q, KC_SCLN, KC_NO, KC_NO,
      KC_W, HOME_HDN_R, HOME_HDN_S, HOME_HDN_N, HOME_HDN_T, KC_G,  /* split */ KC_COMM, HOME_HDN_A, HOME_HDN_E, HOME_HDN_I, HOME_HDN_H, KC_J,
      KC_NO, KC_X, KC_C, KC_L, HOME_HDN_D, KC_B, KC_ESC, DF(_QWERTY), /* split */ KC_NO, KC_TAB, KC_Z, HOME_HDN_U, KC_O, KC_Y, KC_K, KC_NO,

      RGB_MODE_FORWARD,  KC_ESC, LT(_LAYER2, KC_SPC), LT(_LAYER4, KC_ENT), KC_ESC,
      KC_TAB, LT(_LAYER3, KC_DEL), LT(_LAYER1, KC_BACKSPACE), RCS(KC_M), RGB_MODE_REVERSE
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    oled_write_P(PSTR("Kyria by SplitKB"), false);
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

void set_led_color(uint8_t hue, uint8_t sat, uint8_t val) {
    /*rgblight_sethsv_range(hue, sat, val, 0, RGBLED_NUM/2);*/
    /*rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.*/
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.3\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _LAYER1:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _LAYER3:
            oled_write_P(PSTR("F-Keys\n"), false);
            break;
        case _LAYER4:
            oled_write_P(PSTR("Media/Mouse\n"), false);
            break;
        case _HANDS_DOWN:
            oled_write_P(PSTR("Hands Down\n"), false);
            break;
        case _HANDS_DOWN_NEU:
            oled_write_P(PSTR("Hands Down Neu\n"), false);
            break;
        default:
            switch (biton32(default_layer_state)) {
                case _QWERTY:
                    oled_write_P(PSTR("Default\n"), false);
                    break;
                case _COLEMAK_DH:
                    oled_write_P(PSTR("Colemak DH\n"), false);
                    break;
                case _HANDS_DOWN:
                    oled_write_P(PSTR("Hands Down\n"), false);
                    break;
                case _HANDS_DOWN_NEU:
                    oled_write_P(PSTR("Hands Down Neu\n"), false);
                    break;
                default:
                    oled_write_P(PSTR("Undefined\n"), false);
                    break;
            }
            break;
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    /*oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);*/
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(caps_word_enabled() ? PSTR("CAPWRD ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return true;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    /*if (index == 0) {*/
        /*// Volume control*/
        /*if (clockwise) {*/
            /*tap_code(KC_VOLU);*/
        /*} else {*/
            /*tap_code(KC_VOLD);*/
        /*}*/
    /*}*/
    /*else if (index == 1) {*/
        if (! clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    /*}*/
    return false;
}
#endif
