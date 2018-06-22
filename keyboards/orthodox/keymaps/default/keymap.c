/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,

	MAC_F_Q,
	MAC_F_W,
	MAC_F_E,
	MAC_F_R,
	MAC_F_T,

	MAC_F_A,
	MAC_F_S,
	MAC_F_D,
	MAC_F_F,
	MAC_F_G,

	MAC_F_V,
	MAC_F_B,

	MAC_F_SPC,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LS__SPC MT(MOD_LSFT, KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UP, \
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_LSFT, KC_BSPC,          KC_INS,  KC_RSFT,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   RAISE, KC_LALT,              KC_RALT, KC_ENT, KC_RSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DOWN \
  ),
  [_COLEMAK] = LAYOUT(\
    KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_UP, \
    KC_BSPC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,             KC_LSFT, KC_BSPC,          KC_INS,  KC_RSFT,          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER, RAISE, KC_LALT,                  KC_RALT, KC_ENT, KC_RSPC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_DOWN \
  ),

  [_LOWER] = LAYOUT( \
    KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                                KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_BSPC, \
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_LSFT, _______,          _______, KC_RSFT,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
    _______, KC_GRV,  KC_BSLS, KC_EQL,  KC_HOME, KC_END,  _______, _______, _______,          _______, _______, _______, KC_PGUP, KC_PGDN, KC_LBRC, KC_RBRC, KC_MINS,  _______ \
  ),

  [_RAISE] = LAYOUT( \
    KC_TILDE,  MAC_F_Q, MAC_F_W, MAC_F_E, MAC_F_R, MAC_F_T,                                                                   KC_ESC, _______, _______, _______, _______,    KC_BSPC, \
    KC_DEL,  MAC_F_A, MAC_F_S, MAC_F_D, MAC_F_F, MAC_F_G,            KC_CAPS, _______,          _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_QUOT, KC_BSLS, \
    KC_VOLU, KC_VOLD, _______, _______, MAC_F_V, MAC_F_B,  _______, _______, _______,          KC_HOME, KC_PGDN, KC_END, _______,  _______, _______, _______,  _______, _______ \
  ),

  [_ADJUST] = LAYOUT( \
    _______, RESET,   _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, KC_DEL,  \
    _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,          _______, _______,          _______, _______,          AG_SWAP, QWERTY , COLEMAK, _______,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;
    break;
#if 0
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    } else {
      layer_off(_ADJUST);
    }
    return false;
    break;
#endif

        case MAC_F_Q:
		SEND_STRING(SS_LALT(SS_LSFT("q")));
		return false;
        case MAC_F_W:
		SEND_STRING(SS_LALT("w"));
		return false;
        case MAC_F_E:
		SEND_STRING(SS_LALT("e"));
		return false;
        case MAC_F_R:
		SEND_STRING(SS_LALT("r"));
		return false;
        case MAC_F_T:
		SEND_STRING(SS_LALT("t"));
		return false;
        case MAC_F_A:
		SEND_STRING(SS_LALT("1"));
		return false;
        case MAC_F_S:
		SEND_STRING(SS_LALT("2"));
		return false;
        case MAC_F_D:
		SEND_STRING(SS_LALT("3"));
		return false;
        case MAC_F_F:
		SEND_STRING(SS_LALT("4"));
		return false;
        case MAC_F_G:
	       SEND_STRING(SS_LALT("5"));
	       return false;
        case MAC_F_V:
	       SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
	       return false;
        case MAC_F_B:
	       SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
	       return false;
        case MAC_F_SPC:
	       //SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_SPACE))));
	       SEND_STRING(SS_LALT(SS_LSFT(" ")));
	       return false;
  }
  return true;
}
