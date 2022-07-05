#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
    //           ,           ,           ,           ,  F                   ,  G             /* | */  ,  H                    ,  J                   ,                 ,           ,           ,  ,
  KC_ESC         ,  KC_1     ,  KC_2     ,  KC_3     ,  KC_4                ,  KC_5          /* | */  ,  KC_6                 ,  KC_7                ,  KC_8           ,  KC_9     ,  KC_0     ,  KC_F12,
  KC_TAB         ,  KC_Q     ,  KC_W     ,  KC_E     ,  KC_R                ,  KC_T          /* | */  ,  KC_Y                 ,  KC_U                ,  KC_I           ,  KC_O     ,  KC_P     ,  KC_ENT,
  CTL_T(KC_ESC)  ,  KC_A     ,  KC_S     ,  KC_D     ,  KC_F                ,  KC_G          /*---*/  ,  KC_H                 ,  KC_J                ,  KC_K           ,  KC_L     ,  KC_SCLN  ,  KC_QUOT,
  KC_LSFT        ,  KC_Z     ,  KC_X     ,  KC_C     ,  KC_V                ,  KC_B          /* | */  ,  KC_N                 ,  KC_M                ,  KC_COMM        ,  KC_DOT   ,  KC_SLSH  ,  KC_RSFT,
  _______        ,  KC_LCTL  ,  KC_LALT  ,  KC_LGUI  ,  LT(_LOWER, KC_ENT)  ,  SFT_T(KC_TAB) /* | */  ,  LT(_RAISE, KC_BSPC)  ,  LT(_LOWER, KC_SPC)  ,  ALT_T(KC_ESC)  ,  KC_LALT  ,  KC_LCTL  ,  MO(_RAISE)
),

[_LOWER] = LAYOUT_preonic_grid(
    //     ,              ,                 ,                 ,  F               ,  G        /* | */  ,  H         ,  J                    ,                        ,             ,                ,  ,
  KC_F14   ,  KC_F1       ,  KC_F2          ,  KC_F3          ,  KC_F4           ,  KC_F5    /* | */  ,  KC_F6     ,  KC_F7                ,  KC_F8                 ,  KC_F9      ,  KC_F10        ,  KC_F11,
  _______  ,  _______     ,  KC_ASTERISK    ,  KC_UNDERSCORE  ,  KC_PERCENT      ,  KC_AT    /* | */  ,  _______   ,  KC_LEFT_BRACKET      ,  KC_RIGHT_BRACKET      ,  KC_DOLLAR  ,  _______       ,  _______,
  _______  ,  KC_EXCLAIM  ,  KC_EQUAL       ,  KC_LEFT_PAREN  ,  KC_RIGHT_PAREN  ,  KC_TILDE /*---*/  ,  KC_MINUS  ,  KC_LEFT_CURLY_BRACE  ,  KC_RIGHT_CURLY_BRACE  ,  KC_GT      ,  KC_BACKSLASH  ,  _______,
  _______  ,  _______     ,  KC_CIRCUMFLEX  ,  KC_AMPR        ,  KC_PLUS         ,  _______  /* | */  ,  _______   ,  KC_PIPE              ,  KC_GRAVE              ,  KC_HASH    ,  _______       ,  _______,
  _______  ,  _______     ,  _______        ,  _______        ,  MO(_ADJUST)     ,  _______  /* | */  ,  _______   ,  MO(_ADJUST)          ,  _______               ,  _______    ,  _______       ,  _______
),

[_RAISE] = LAYOUT_preonic_grid(
    //     ,           ,           ,           ,  F        ,  G        /* | */  ,  H        ,  J        ,           ,            ,           ,  ,
  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  /* | */  ,  _______  ,  _______  ,  _______  ,  _______   ,  _______  ,  _______,
  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  /* | */  ,  _______  ,  _______  ,  _______  ,  _______   ,  _______  ,  _______,
  _______  ,  _______  ,  KC_NUHS  ,  KC_HASH  ,  _______  ,  _______  /*---*/  ,  KC_LEFT  ,  KC_DOWN  ,  KC_UP    ,  KC_RIGHT  ,  _______  ,  _______,
  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  /* | */  ,  _______  ,  _______  ,  _______  ,  _______   ,  _______  ,  _______,
  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  /* | */  ,  _______  ,  _______  ,  _______  ,  _______   ,  _______  ,  _______
),

[_ADJUST] = LAYOUT_preonic_grid(
    //     ,           ,           ,           ,  F        ,  G        /* | */              ,  H        ,  J                     ,                         ,            ,           ,  ,
  QK_BOOT  ,  KC_F1    ,  KC_F2    ,  KC_F3    ,  KC_F4    ,  KC_F5    /* | */              ,  KC_F6    ,  KC_F7                 ,  KC_F8                  ,  KC_F9     ,  KC_F10   ,  KC_F11   ,
  RGB_TOG  ,  _______  ,  KC_MSTP  ,  KC_MPRV  ,  KC_MNXT  ,  KC_MEDIA_PLAY_PAUSE /* | */   ,  _______  ,  G(KC_SPC)             ,  TERM_OFF               ,  _______   ,  _______  ,  _______,
  RGB_MOD  ,  _______  ,  _______  ,  _______  ,  KC_LALT  ,  KC_LGUI              /*---*/  ,  KC_LEFT  ,  KC_DOWN               ,  KC_DOWN                ,  KC_RIGHT  ,  _______  ,  _______,
  _______  ,  MUV_DE   ,  MUV_IN   ,  MU_ON    ,  MU_OFF   ,  _______  /* | */              ,  MI_OFF   ,  LSG(KC_LEFT_BRACKET)  ,  LSG(KC_RIGHT_BRACKET)  ,  _______   ,  _______  ,  _______,
  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  /* | */              ,  _______  ,  _______               ,  _______                ,  _______   ,  _______  ,  _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
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
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
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
