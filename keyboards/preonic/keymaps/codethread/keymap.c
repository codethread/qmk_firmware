#include QMK_KEYBOARD_H
#include "muse.h"

// https://docs.qmk.fm/#/keycodes?id=midi

enum preonic_layers {
  _QWERTY,
  _SHIFTED,
  _LOWER,
  _ARROWS,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌─────────────┬──────┬───────────┬───────────┬─────────────────┬───────────────────┐   ┌───────────────────┬─────────────────┬───────────┬───────────┬─────┬─────────────┐
//        │     esc     │  1   │     2     │     3     │        4        │         5         │   │         6         │        7        │     8     │     9     │  0  │     f12     │
//        ├─────────────┼──────┼───────────┼───────────┼─────────────────┼───────────────────┤   ├───────────────────┼─────────────────┼───────────┼───────────┼─────┼─────────────┤
//        │     tab     │  q   │     w     │     e     │        r        │         t         │   │         y         │        u        │     i     │     o     │  p  │      _      │
//        ├─────────────┼──────┼───────────┼───────────┼─────────────────┼───────────────────┤   ├───────────────────┼─────────────────┼───────────┼───────────┼─────┼─────────────┤
//        │ CTL_T(esc)  │  a   │     s     │     d     │        f        │         g         │   │         h         │        j        │     k     │     l     │  ;  │     "'"     │
//        ├─────────────┼──────┼───────────┼───────────┼─────────────────┼───────────────────┤   ├───────────────────┼─────────────────┼───────────┼───────────┼─────┼─────────────┤
//        │    lsft     │  z   │ LCTL_T(x) │ LALT_T(c) │    LGUI_T(v)    │         b         │   │         n         │    RGUI_T(m)    │ RALT_T(,) │ RCTL_T(.) │  /  │    rsft     │
//        ├─────────────┼──────┼───────────┼───────────┼─────────────────┼───────────────────┤   ├───────────────────┼─────────────────┼───────────┼───────────┼─────┼─────────────┤
//        │ MO(_ADJUST) │ lctl │   lalt    │   lgui    │ LT(_LOWER, ent) │ LT(_SHIFTED, tab) │   │ LT(_ARROWS, bspc) │ LT(_LOWER, spc) │    esc    │           │     │ MO(_ARROWS) │
//        └─────────────┴──────┴───────────┴───────────┴─────────────────┴───────────────────┘   └───────────────────┴─────────────────┴───────────┴───────────┴─────┴─────────────┘
[_QWERTY] = LAYOUT_preonic_grid(
      KC_ESC        , KC_1    , KC_2         , KC_3         , KC_4               , KC_5                 ,     KC_6                 , KC_7               , KC_8            , KC_9           , KC_0    , KC_F12       ,
      KC_TAB        , KC_Q    , KC_W         , KC_E         , KC_R               , KC_T                 ,     KC_Y                 , KC_U               , KC_I            , KC_O           , KC_P    , KC_UNDERSCORE,
      CTL_T(KC_ESC) , KC_A    , KC_S         , KC_D         , KC_F               , KC_G                 ,     KC_H                 , KC_J               , KC_K            , KC_L           , KC_SCLN , KC_QUOT      ,
      KC_LSFT       , KC_Z    , LCTL_T(KC_X) , LALT_T(KC_C) , LGUI_T(KC_V)       , KC_B                 ,     KC_N                 , RGUI_T(KC_M)       , RALT_T(KC_COMM) , RCTL_T(KC_DOT) , KC_SLSH , KC_RSFT      ,
      MO(_ADJUST)   , KC_LCTL , KC_LALT      , KC_LGUI      , LT(_LOWER, KC_ENT) , LT(_SHIFTED, KC_TAB) ,     LT(_ARROWS, KC_BSPC) , LT(_LOWER, KC_SPC) , KC_ESC          , _______        , _______ , MO(_ARROWS)
),

//        ┌────────────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬────────┐
//        │    esc     │  1   │  2   │  3   │  4   │  5   │   │  6   │  7   │  8   │  9   │  0   │  f12   │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼────────┤
//        │    tab     │ S(q) │ S(w) │ S(e) │ S(r) │ S(t) │   │ S(y) │ S(u) │ S(i) │ S(o) │ S(p) │  ent   │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼────────┤
//        │ CTL_T(esc) │ S(a) │ S(s) │ S(d) │ S(f) │ S(g) │   │ S(h) │ S(j) │ S(k) │ S(l) │ S(;) │ S("'") │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼────────┤
//        │    lsft    │ S(z) │ S(x) │ S(c) │ S(v) │ S(b) │   │ S(n) │ S(m) │ S(,) │ S(.) │ S(/) │  rsft  │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼────────┤
//        │            │      │      │      │      │      │   │      │      │      │      │      │        │
//        └────────────┴──────┴──────┴──────┴──────┴──────┘   └──────┴──────┴──────┴──────┴──────┴────────┘
[_SHIFTED] = LAYOUT_preonic_grid(
      KC_ESC        , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8       , KC_9      , KC_0       , KC_F12    ,
      KC_TAB        , S(KC_Q) , S(KC_W) , S(KC_E) , S(KC_R) , S(KC_T) ,     S(KC_Y) , S(KC_U) , S(KC_I)    , S(KC_O)   , S(KC_P)    , KC_ENT    ,
      CTL_T(KC_ESC) , S(KC_A) , S(KC_S) , S(KC_D) , S(KC_F) , S(KC_G) ,     S(KC_H) , S(KC_J) , S(KC_K)    , S(KC_L)   , S(KC_SCLN) , S(KC_QUOT),
      KC_LSFT       , S(KC_Z) , S(KC_X) , S(KC_C) , S(KC_V) , S(KC_B) ,     S(KC_N) , S(KC_M) , S(KC_COMM) , S(KC_DOT) , S(KC_SLSH) , KC_RSFT   ,
      _______       , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______    , _______   , _______    , _______
),

//        ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬──────┬───────────┬─────┐
//        │ f14 │ f1  │ f2  │ f3  │ f4  │ f5  │   │ f6  │ f7  │ f8  │  f9  │    f10    │ f11 │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼───────────┼─────┤
//        │     │     │  *  │  _  │  %  │  @  │   │     │  [  │  ]  │  $   │           │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼───────────┼─────┤
//        │     │  !  │  =  │  (  │  )  │  ~  │   │  -  │  {  │  }  │  >   │ bACKSLASH │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼───────────┼─────┤
//        │     │     │  ^  │  &  │  +  │     │   │     │  |  │  `  │ '--' │           │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼───────────┼─────┤
//        │     │     │     │     │     │     │   │     │     │     │      │           │     │
//        └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴──────┴───────────┴─────┘
[_LOWER] = LAYOUT_preonic_grid(
      KC_F14  , KC_F1      , KC_F2         , KC_F3         , KC_F4          , KC_F5    ,     KC_F6    , KC_F7               , KC_F8                , KC_F9     , KC_F10       , KC_F11 ,
      _______ , _______    , KC_ASTERISK   , KC_UNDERSCORE , KC_PERCENT     , KC_AT    ,     _______  , KC_LEFT_BRACKET     , KC_RIGHT_BRACKET     , KC_DOLLAR , _______      , _______,
      _______ , KC_EXCLAIM , KC_EQUAL      , KC_LEFT_PAREN , KC_RIGHT_PAREN , KC_TILDE ,     KC_MINUS , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_GT     , KC_BACKSLASH , _______,
      _______ , _______    , KC_CIRCUMFLEX , KC_AMPR       , KC_PLUS        , _______  ,     _______  , KC_PIPE             , KC_GRAVE             , KC_HASH   , _______      , _______,
      _______ , _______    , _______       , _______       , _______        , _______  ,     _______  , _______             , _______              , _______   , _______      , _______
),

//        ┌─────┬─────┬─────┬────────┬──────┬─────┐   ┌──────┬────────┬────────┬──────┬─────┬─────┐
//        │     │     │     │        │      │     │   │      │        │        │      │     │     │
//        ├─────┼─────┼─────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │     │     │  G(+)  │ G(-) │     │   │ G([) │ LSG([) │ LSG(]) │ G(]) │     │     │
//        ├─────┼─────┼─────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │     │     │ LSG(`) │ G(`) │     │   │ left │  down  │   up   │ rght │     │     │
//        ├─────┼─────┼─────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │     │     │        │      │     │   │      │  f14   │        │      │     │     │
//        ├─────┼─────┼─────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │     │     │        │      │     │   │      │        │        │      │     │     │
//        └─────┴─────┴─────┴────────┴──────┴─────┘   └──────┴────────┴────────┴──────┴─────┴─────┘
[_ARROWS] = LAYOUT_preonic_grid(
      _______ , _______ , _______ , _______       , _______     , _______ ,     _______            , _______              , _______               , _______             , _______ , _______,
      _______ , _______ , _______ , G(KC_PLUS)    , G(KC_MINUS) , _______ ,     G(KC_LEFT_BRACKET) , LSG(KC_LEFT_BRACKET) , LSG(KC_RIGHT_BRACKET) , G(KC_RIGHT_BRACKET) , _______ , _______,
      _______ , _______ , _______ , LSG(KC_GRAVE) , G(KC_GRAVE) , _______ ,     KC_LEFT            , KC_DOWN              , KC_UP                 , KC_RIGHT            , _______ , _______,
      _______ , _______ , _______ , _______       , _______     , _______ ,     _______            , KC_F14               , _______               , _______             , _______ , _______,
      _______ , _______ , _______ , _______       , _______     , _______ ,     _______            , _______              , _______               , _______             , _______ , _______
),

//        ┌─────────┬────────┬────────┬───────┬────────┬──────┐   ┌────────┬────────┬────────┬──────┬─────┬─────┐
//        │ QK_BOOT │   f1   │   f2   │  f3   │   f4   │  f5  │   │   f6   │   f7   │   f8   │  f9  │ f10 │ f11 │
//        ├─────────┼────────┼────────┼───────┼────────┼──────┤   ├────────┼────────┼────────┼──────┼─────┼─────┤
//        │ RGB_TOG │        │  mstp  │ mprv  │  mnxt  │ mply │   │        │  btn1  │  btn2  │ btn3 │     │     │
//        ├─────────┼────────┼────────┼───────┼────────┼──────┤   ├────────┼────────┼────────┼──────┼─────┼─────┤
//        │ RGB_MOD │        │        │       │  lalt  │ lgui │   │  ms_l  │  ms_d  │  ms_u  │ ms_r │     │     │
//        ├─────────┼────────┼────────┼───────┼────────┼──────┤   ├────────┼────────┼────────┼──────┼─────┼─────┤
//        │         │ MUV_DE │ MUV_IN │ MU_ON │ MU_OFF │      │   │ MI_OFF │ LSG([) │ LSG(]) │      │     │     │
//        ├─────────┼────────┼────────┼───────┼────────┼──────┤   ├────────┼────────┼────────┼──────┼─────┼─────┤
//        │         │        │        │ vold  │        │      │   │        │        │  volu  │      │     │     │
//        └─────────┴────────┴────────┴───────┴────────┴──────┘   └────────┴────────┴────────┴──────┴─────┴─────┘
[_ADJUST] = LAYOUT_preonic_grid(
      QK_BOOT , KC_F1   , KC_F2   , KC_F3             , KC_F4   , KC_F5               ,     KC_F6      , KC_F7                , KC_F8                 , KC_F9       , KC_F10  , KC_F11 ,
      RGB_TOG , _______ , KC_MSTP , KC_MPRV           , KC_MNXT , KC_MEDIA_PLAY_PAUSE ,     _______    , KC_BTN1              , KC_BTN2               , KC_BTN3     , _______ , _______,
      RGB_MOD , _______ , _______ , _______           , KC_LALT , KC_LGUI             ,     KC_MS_LEFT , KC_MS_DOWN           , KC_MS_UP              , KC_MS_RIGHT , _______ , _______,
      _______ , MUV_DE  , MUV_IN  , MU_ON             , MU_OFF  , _______             ,     MI_OFF     , LSG(KC_LEFT_BRACKET) , LSG(KC_RIGHT_BRACKET) , _______     , _______ , _______,
      _______ , _______ , _______ , KC_AUDIO_VOL_DOWN , _______ , _______             ,     _______    , _______              , KC_AUDIO_VOL_UP       , _______     , _______ , _______
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
            update_tri_layer(_LOWER, _ARROWS, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _ARROWS, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_ARROWS);
            update_tri_layer(_LOWER, _ARROWS, _ADJUST);
          } else {
            layer_off(_ARROWS);
            update_tri_layer(_LOWER, _ARROWS, _ADJUST);
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
    if (IS_LAYER_ON(_ARROWS)) {
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
