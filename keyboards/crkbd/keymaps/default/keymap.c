#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum _layers {
	_QWERTY,
	_COLEMAK,
	_NUM,
	_FN,
	_ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,

  // my
	KC_MAC_Q,
	KC_MAC_W,
	KC_MAC_E,
	KC_MAC_R,
	KC_MAC_T,
	KC_MAC_A,
	KC_MAC_S,
	KC_MAC_D,
	KC_MAC_F,
	KC_MAC_G,
	KC_MAC_V,
	KC_MAC_B,
	KC_MAC_SPC,

        KC_COLEMAK,
        KC_QWERTY,
        KC_BACKLIT,
        KC_RGBRST
};

#define KC_____  KC_TRNS
#define KC_XXXX  KC_NO
#define KC_RST   RESET
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_MOD
//#define KC_CTLTB CTL_T(KC_TAB)
//#define KC_GUIEI GUI_T(KC_LANG2)
//#define KC_ALTKN ALT_T(KC_LANG1)

#define KC_M_NUM    MO(_NUM)
#define KC_M_FN     MO(_FN)
#define KC_M_ADJ    MO(_ADJUST)
#define KC_M_CA     LCTL(KC_A)
#define KC_M_CB     LCTL(KC_B)

// XXX - control
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  INS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       BSPC,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN, LCTL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH, RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LALT, M_NUM, M_FN,      ENT, SPC, RALT \
                              //`--------------------'  `--------------------'
  ),
  [_COLEMAK] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     F,     P,     G,                      J,     L,     U,     Y,  SCLN,  INS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       BSPC,     A,     R,     S,     T,     D,                      H,     N,     E,     I,     O, LCTL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      K,     M,  COMM,   DOT,  SLSH, RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LALT, M_NUM, M_FN,      ENT, SPC, RALT \
                              //`--------------------'  `--------------------'
  ),

  [_NUM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ____,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,    F9,   F10,  F11,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        DEL,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  F12,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       ____,   GRV,  BSLS,   EQL,  HOME,   END,                   CLCK,  QUOT,  LBRC,  RBRC, MINUS, CLCK,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   ____, ____,  ____,      ____, ____, ____ \
                              //`--------------------'  `--------------------'
  ),

  [_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
       ____, MAC_Q, MAC_W, MAC_E, MAC_R, MAC_T,                    ESC,  M_CA,  M_CB,  ____,  ____, ____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       ____, MAC_A, MAC_S, MAC_D, MAC_F, MAC_G,                   LEFT,  DOWN,    UP, RIGHT,  ____, ____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       ____,  ____,  ____,  ____, MAC_V, MAC_B,                   HOME,  PGDN,  PGUP,   END,  ____, ____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  ____, ____,  ____,       TAB, ____, ____ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     RGBRST,  ____,  ____,  ____,  ____,  ____,                    RST,   XXXX,  XXXX,  XXXX, XXXX, ____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXX, VOLU,                    XXXX,   XXXX,  XXXX,  XXXX,  XXXX, ____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LSMOD,  LHUD,  LSAD,  LVAD, XXXX, VOLD,                  QWERTY,COLEMAK,  XXXX,  XXXX,  XXXX, ____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  ____, ____,  ____,     ____, ____, ____ \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

#if 0
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
#endif 

uint32_t layer_state_set_user(uint32_t state) {
	return update_tri_layer_state(state, _NUM, _FN, _ADJUST);
}


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();

    uint8_t layer = biton32(layer_state);
    //uint8_t modifiers = get_mods();
    
    switch (layer) {
    	case _QWERTY:
	    //set_led_off;
            //set_led_green;
            break;
        case _FN:
            //set_led_blue;
            break;
        case _NUM:
            //set_led_red;
            break;
        default:
            break;
    }

   //if ((host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) set_led_green;
   //if (modifiers & MOD_BIT(KC_CAPS)) set_led_red;
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  } else {
      return true;
  }
#if 0
    case KC_NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        update_tri_layer_RGB(_NUM, _FN, _ADJUST);
      } else {
        layer_off(_NUM);
        update_tri_layer_RGB(_NUM, _FN, _ADJUST);
      }
      return false;
      break;
    case KC_FN:
      if (record->event.pressed) {
        layer_on(_FN);
        update_tri_layer_RGB(_NUM, _FN, _ADJUST);
      } else {
        layer_off(_FN);
        update_tri_layer_RGB(_NUM, _FN, _ADJUST);
      }
      return false;
      break;
#endif

  switch (keycode) {
      case KC_QWERTY:
          set_single_persistent_default_layer(_QWERTY);
          return false;
      case KC_COLEMAK:
          set_single_persistent_default_layer(_COLEMAK);
          return false;

      case RGB_MOD:
#ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
#endif
          return false;
      case KC_RGBRST:
#ifdef RGBLIGHT_ENABLE
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
#endif
          return false;

      case KC_MAC_Q:
          SEND_STRING(SS_LALT(SS_LSFT("q")));
          return false;
      case KC_MAC_W:
          SEND_STRING(SS_LALT("w"));
          return false;
      case KC_MAC_E:
          SEND_STRING(SS_LALT("e"));
          return false;
      case KC_MAC_R:
          SEND_STRING(SS_LALT("r"));
          return false;
      case KC_MAC_T:
          SEND_STRING(SS_LALT("t"));
          return false;
      case KC_MAC_A:
          SEND_STRING(SS_LALT("1"));
          return false;
      case KC_MAC_S:
          SEND_STRING(SS_LALT("2"));
          return false;
      case KC_MAC_D:
          SEND_STRING(SS_LALT("3"));
          return false;
      case KC_MAC_F:
          SEND_STRING(SS_LALT("4"));
          return false;
      case KC_MAC_G:
          SEND_STRING(SS_LALT("5"));
          return false;
      case KC_MAC_V:
          SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
          return false;
      case KC_MAC_B:
          SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
          return false;
      case KC_MAC_SPC:
          //SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_SPACE))));
          SEND_STRING(SS_LALT(SS_LSFT(" ")));
          return false;
  }
  return true;
}
