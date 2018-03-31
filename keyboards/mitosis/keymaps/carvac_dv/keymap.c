// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include QMK_KEYBOARD_H

enum mitosis_layers
{
	_QWERTY,
	_COLEMAK,
	_NUM,
	_FN,
	_ADJUST,
};

enum mitosis_macros
{
	MAC_F_Q = SAFE_RANGE,
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

	COLEMAK,
	QWERTY,
};

#if 0
qk_tap_dance_action_t tap_dance_actions[] = {
	[0] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_RSFT),
};
#endif

//Mousekeys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------..--------------------------------------------.
 * | Q      | W      | E      | R      | T      || Y      | U      | I      | O      | P      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | A      | S      | D      | F      | G      || J      | H      | K      | L      | ;      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | Z      | X      | C      | V      | B      || N      | M      | ,      | .      | /      |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        | LCTRL  |  BSPC  || LSHIFT |  INS   |   ESC  |   UP   |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        | LALT   | -NUM-  | -FN-   ||  ENTER |  SPACE |  RALT  |  DOWN  |
 *          '-----------------------------------''-----------------------------------'
 */
[_QWERTY] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    },
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN },
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
  {XXXXXXX, KC_TAB, _______,  KC_LSFT, KC_BSPC,        KC_INS,  KC_RSFT, KC_QUOT, KC_UP,   XXXXXXX },
  {XXXXXXX, KC_LCTL, KC_LALT, MO(_NUM),MO(_FN),        KC_ENT,  KC_SPC, KC_RALT, KC_DOWN, XXXXXXX }
},

  [_COLEMAK] = {
    {KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   	KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN},
    {KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   	KC_H,    KC_N,    KC_E,    KC_I,    KC_O},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   	KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
    {XXXXXXX, KC_TAB,  _______, KC_LSFT, KC_BSPC,       KC_INS,  KC_RSFT, KC_QUOT, KC_UP,   XXXXXXX },
    {XXXXXXX, KC_LCTL, KC_LALT, MO(_NUM),MO(_FN),       KC_ENT,  KC_SPC, KC_RALT, KC_DOWN, XXXXXXX }
  },



/* Number layout, for data entry and programming purposes (Dvorak result in parens)
 * .--------------------------------------------..--------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     || F6     | F7     | F8     | F9     | F10    |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | 1      | 2      | 3      | 4      | 5      || 6      | 7      | 8      | 9      | 0      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | `      |    \   |    =   |  HOME  |  END   ||   UP   |  DOWN  |   [    |   ]    |   -    |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          | F11    | F12    |  TAB   |  DEL   ||        |        |        |   '    |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        |        ||        |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */
[_NUM] = { /* Number layout along the home row for maximum speed*/
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10  },
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0    },
  {KC_GRV,  KC_BSLS, KC_EQL,  KC_HOME, KC_END,        _______, KC_QUOT, KC_LBRC, KC_RBRC, KC_MINS },
  {XXXXXXX, KC_F11,  KC_F12,  _______, KC_DEL,        _______, _______, _______, _______, XXXXXXX },
  {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }
},


/* Fn layout, for typing purposes (Dvorak result in parens)
 * .--------------------------------------------..--------------------------------------------.
 * | `      |        | MS_U   |        |        || WH_U   | WH_L   | BTN3   | WH_R   | [ (/?) |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | ESC    | MS_L   | MS_D   | MS_R   |        || WH_D   | BTN1   | BTN2   |        | ' (-_) |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | APP    | MPRV   | MPLY   | MSTP   | MNXT   ||        | BSPC   | DEL    | INS    | \      |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          | VOLU   |        |        |        ||        |        | PGUP   |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          | VOLD   |        |        |        ||        | HOME   | PGDN   | END    |
 *          '-----------------------------------''-----------------------------------'
 */

[_FN] = { /* Function Layer, primary alternative layer featuring numpad on right hand,
                                   cursor keys on left hand, and all symbols*/
  {MAC_F_Q, MAC_F_W, MAC_F_E, MAC_F_R, MAC_F_T,        KC_ESC, _______, _______, _______, _______ },
  {MAC_F_A, MAC_F_S, MAC_F_D, MAC_F_F, MAC_F_G,       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______ },
  {_______, _______, _______, MAC_F_V, MAC_F_B,       KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______ },
  {XXXXXXX, KC_VOLU, _______, KC_CAPS, _______,       _______, _______, _______, _______, XXXXXXX },
  {XXXXXXX, KC_VOLD, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }
},

[_ADJUST] = {
  {_______, _______, _______, _______, _______,       RESET,   _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ },
  {XXXXXXX, _______, _______, _______, _______,       QWERTY,  COLEMAK, _______, _______, XXXXXXX },
  {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX }
},

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    //uint8_t modifiers = get_mods();
    
    switch (layer) {
    	case _QWERTY:
	    set_led_off;
            set_led_green;
    		break;
        case _FN:
            set_led_blue;
            break;
        case _NUM:
            set_led_red;
            break;
        default:
            break;
    }

   //if ((host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) set_led_green;
   //if (modifiers & MOD_BIT(KC_CAPS)) set_led_red;
};

uint32_t layer_state_set_user(uint32_t state) {
	return update_tri_layer_state(state, _NUM, _FN, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
  case COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;

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
	default:
               return true;
    };
}

