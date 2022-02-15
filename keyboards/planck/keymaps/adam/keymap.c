#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

#include "adam.h"


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _AP2,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9,
  _LAYER10,
  _LAYER11,
};


// TD(TD_MEDIA) doesn't work on planck - seems to be exactly the same where it does work
// feels like it must be something in rules or config, but KC_MPLY works, and other TD calls work

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// we have 2 x 2u on the bottom row, alternating dead keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,      
    LT(4,KC_ESCAPE),KC_A,           LT(5,KC_S),     LT(9,KC_D),     LSFT_T(KC_F),   LT(7,KC_G),     LSFT_T(KC_H),   LT(8,KC_J),     LT(10,KC_K),    KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       RSFT_T(KC_BSLASH),
    KC_LCTRL,       KC_LGUI,        TT(6),          KC_LALT,        KC_NO,          LT(1,KC_ENTER), KC_NO,          LSFT_T(KC_SPACE), KC_LEFT,      KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,      
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          TD(TD_F5_F6),   KC_UNDS,        KC_UNDS,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_PIPE,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_AUDIO_MUTE,  KC_LABK,        KC_RABK,        KC_QUES,        KC_DQUO,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, MO(3),          KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LALT(KC_RIGHT)
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           LALT(KC_F4),    KC_5,           KC_6,           KC_7,           KC_VOLD,        KC_VOLU,        TD(TD_MEDIA),    KC_DELETE,      
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_MINUS,       KC_EQUAL,       KC_LBRACKET,    KC_RBRACKET,    KC_BSLASH,      
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH,      KC_MEDIA_PREV_TRACK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    DYN_REC_START1, DYN_MACRO_PLAY1,DYN_REC_START2, DYN_MACRO_PLAY2,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,    
    DYN_REC_STOP,   KC_TRANSPARENT, TG(6),          AU_OFF,         AU_ON,          KC_TRANSPARENT, KC_TRNS,        RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RESET,          
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_MOD,         KC_TRANSPARENT, KC_TRNS,        RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,        LCA(KC_DEL),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // with 2 x 2u, there's no easy way to get to raise 
  [_AP2] = LAYOUT_planck_grid(
    KC_TRANSPARENT, LCTL(LGUI(KC_LEFT)),LCTL(LGUI(KC_RIGHT)),KC_TRANSPARENT, LALT(KC_F4),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS,        RESET,          
    KC_TRANSPARENT, MO(1),              MO(2),               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
 

  // S - numbers
  [_LAYER5] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTERISK, KC_7,           KC_8,           KC_9,          KC_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  TG(6),          KC_TAB,         KC_TRANSPARENT, KC_UNDERSCORE, KC_MINUS,       KC_4,           KC_5,           KC_6,           KC_PLUS,     KC_EQUAL,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,        KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LCTRL,       KC_NO,         KC_0,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // game - note that to get here you need to tap fn 5 times - because it's TT not TG
  [_LAYER6] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,      
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLASH,      
    KC_LCTRL,       KC_NO,          KC_TRANSPARENT, KC_LALT,        KC_NO,          KC_SPACE,       KC_NO,          LT(11,KC_ENTER),KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  //  g - brackets
  [_LAYER7] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ARRAY,     KC_LBRACKET,    KC_RBRACKET,    ARRAY_INSIDE,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     KC_TRANSPARENT, JSARROW,     KC_LPRN,        KC_RPRN,        KC_LCBR,        KC_RCBR,        BRACKETS,     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LT,        KC_GT,        END_TAG,     KC_GT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // J - launch
  [_LAYER8] = LAYOUT_planck_grid(
    KC_TRANSPARENT, LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_E),     LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     LGUI(KC_7),     LGUI(KC_8),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LCTL),  KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_F),     KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        LGUI(KC_L),     KC_LALT,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_BSPC,        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // D - nav
  [_LAYER9] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_W),     KC_TRANSPARENT, LCTL(KC_R),     LCTL(KC_T),     KC_TRANSPARENT, KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESC,         KC_DELETE,      KC_TRANSPARENT, KC_LSHIFT,      LCTL(KC_TAB),   KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         LCTL(KC_L),     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_V),     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_U),     KC_BSPC,     LSFT(LCTL(KC_U) ),     LCTL(KC_SLASH), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LCTRL,       KC_NO,          LCTL(KC_C),     LCTL(KC_X),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS
  ),

  // K 
  [_LAYER10] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESC,         KC_TRANSPARENT, KC_BSPC,        KC_BSPC,        LALT(KC_LEFT),  KC_TRANSPARENT, KC_LCTRL,       KC_TRANSPARENT, LCTL(KC_L),     OSM(MOD_LALT),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_SLASH), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_BSPC,        KC_NO,          KC_TRNS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // game macro
  [_LAYER11] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};


/*
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {170,147,121}, {170,147,121}, {197,247,137}, {197,247,137}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {197,247,137}, {197,247,137}, {170,147,121}, {170,147,121}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137}, {197,247,137} },

    [2] = { {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {197,247,137}, {154,255,255}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137}, {143,124,137} },

    [3] = { {0,205,155}, {85,203,158}, {0,205,155}, {85,203,158}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {134,255,213}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186}, {16,213,186} },

    [4] = { {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,234}, {32,255,234}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,234}, {0,204,255}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,234}, {32,255,234}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,234,147}, {0,234,147}, {105,255,255}, {35,255,255}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {105,255,255}, {105,255,255}, {105,255,255}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147}, {0,234,147} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,0,0}, {170,147,121}, {170,147,121}, {170,147,121}, {170,147,121}, {170,147,121}, {170,147,121}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
*/


// this isn't going to work because this function is in adam.c
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_LEFT));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(100) SS_LSFT(SS_TAP(X_0)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_SLASH));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

*/

// do I want to just comment this out?


#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif


// this seems like kind of a waste?
// I can just do mo(3) from the opposite keys
/*
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

*/

// not clear if we really want to keep bspc and tab
// but single quote is very handy
#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_cut[]          = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_copy[]         = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[]        = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_bspc[]         = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[]          = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_single_quote[] = {KC_L, KC_SCLN, COMBO_END};
// this doesn't seem to work - probably because f is already overloaded?
// const uint16_t PROGMEM combo_another_bspc[] = {KC_F, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};

enum combo_events { ZX_CUT, XC_COPY, CV_PASTE };

combo_t key_combos[COMBO_COUNT] = {
    [ZX_CUT] = COMBO_ACTION(combo_cut), [XC_COPY] = COMBO_ACTION(combo_copy), [CV_PASTE] = COMBO_ACTION(combo_paste), COMBO(combo_bspc, KC_BSPC), COMBO(combo_tab, KC_TAB), COMBO(combo_single_quote, KC_QUOTE),
};

// note that that this is using the index into key_combos, which is assumed to be the enum
// not clear if we can acutally mix enums and the combo macro...
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CV_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case XC_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
        case ZX_CUT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
    }
}
#endif
