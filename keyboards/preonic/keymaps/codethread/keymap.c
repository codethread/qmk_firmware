#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// https://docs.qmk.fm/#/keycodes?id=midi

#define MAC_SHOW_APPS KC_F14

#define K_A LSFT_T(KC_A)
#define K_S LALT_T(KC_S)
#define K_D LCTL_T(KC_D)
#define K_F LGUI_T(KC_F)

#define K_J LGUI_T(KC_J)
#define K_K LCTL_T(KC_K)
#define K_L LALT_T(KC_L)
#define K_SEMI LSFT_T(KC_SCLN)

// clang-format off
enum preonic_layers {
  _QWERTY,
  _SYMBOLS,
  _NUMBS,
  _NAV,
  _ADJUST,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌─────┬─────┬─────┬─────┬──────────────┬────────────┐   ┌────────────────┬─────────────────┬─────┬─────┬────────┬──────┐
//        │ esc │  1  │  2  │  3  │      4       │     5      │   │       6        │        7        │  8  │  9  │   0    │ f12  │
//        ├─────┼─────┼─────┼─────┼──────────────┼────────────┤   ├────────────────┼─────────────────┼─────┼─────┼────────┼──────┤
//        │ tab │  q  │  w  │  e  │      r       │     t      │   │       y        │        u        │  i  │  o  │   p    │ ent  │
//        ├─────┼─────┼─────┼─────┼──────────────┼────────────┤   ├────────────────┼─────────────────┼─────┼─────┼────────┼──────┤
//        │  ^  │ K_A │ K_S │ K_D │     K_F      │     g      │   │       h        │       K_J       │ K_K │ K_L │ K_SEMI │  '   │
//        ├─────┼─────┼─────┼─────┼──────────────┼────────────┤   ├────────────────┼─────────────────┼─────┼─────┼────────┼──────┤
//        │  󰘶  │  z  │  x  │  c  │      v       │     b      │   │       n        │        m        │  ,  │  .  │   /    │ rsft │
//        ├─────┼─────┼─────┼─────┼──────────────┼────────────┤   ├────────────────┼─────────────────┼─────┼─────┼────────┼──────┤
//        │     │     │     │  󰘳  │ MO(_SYMBOLS) │ MO(_NUMBS) │   │ LT(_NAV, bspc) │ LT(_NUMBS, "_") │    │     │        │      │
//        └─────┴─────┴─────┴─────┴──────────────┴────────────┘   └────────────────┴─────────────────┴─────┴─────┴────────┴──────┘
[_QWERTY] = LAYOUT_preonic_grid(
      KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4         , KC_5       ,     KC_6              , KC_7               , KC_8    , KC_9    , KC_0    , KC_F12 ,
      KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R         , KC_T       ,     KC_Y              , KC_U               , KC_I    , KC_O    , KC_P    , KC_ENT ,
      KC_LCTL , K_A     , K_S     , K_D     , K_F          , KC_G       ,     KC_H              , K_J                , K_K     , K_L     , K_SEMI  , KC_QUOT,
      KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V         , KC_B       ,     KC_N              , KC_M               , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
      _______ , _______ , _______ , KC_LGUI , MO(_SYMBOLS) , MO(_NUMBS) ,     LT(_NAV, KC_BSPC) , LT(_NUMBS, KC_SPC) , KC_HYPR , _______ , _______ , _______
),

//        ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────────────┬──────┬─────┬─────┬─────┬─────┐
//        │     │ f1  │ f2  │ f3  │ f4  │ f5  │   │     f6      │  f7  │ f8  │ f9  │ f10 │ f11 │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────────────┼──────┼─────┼─────┼─────┼─────┤
//        │     │     │  *  │  _  │  %  │  @  │   │     ../     │  [   │  ]  │  $  │     │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────────────┼──────┼─────┼─────┼─────┼─────┤
//        │     │  !  │  =  │  (  │  )  │  ~  │   │      -      │  {   │  }  │ =>  │  \  │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────────────┼──────┼─────┼─────┼─────┼─────┤
//        │     │     │  ^  │  &  │  +  │     │   │             │  |   │  `  │  #  │     │     │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────────────┼──────┼─────┼─────┼─────┼─────┤
//        │     │     │     │     │     │     │   │ MO(_ADJUST) │ bspc │     │     │     │     │
//        └─────┴─────┴─────┴─────┴─────┴─────┘   └─────────────┴──────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT_preonic_grid(
      _______ , KC_F1      , KC_F2         , KC_F3         , KC_F4      , KC_F5    ,     KC_F6       , KC_F7           , KC_F8            , KC_F9     , KC_F10       , KC_F11 ,
      _______ , _______    , KC_ASTERISK   , KC_UNDERSCORE , KC_PERCENT , KC_AT    ,     UPDIR       , KC_LEFT_BRACKET , KC_RIGHT_BRACKET , KC_DOLLAR , _______      , _______,
      _______ , KC_EXCLAIM , KC_EQUAL      , KC_LPRN       , KC_RPRN    , KC_TILDE ,     KC_MINUS    , KC_LCBR         , KC_RCBR          , ARROW     , KC_BACKSLASH , _______,
      _______ , _______    , KC_CIRCUMFLEX , KC_AMPR       , KC_PLUS    , _______  ,     _______     , KC_PIPE         , KC_GRAVE         , KC_HASH   , _______      , _______,
      _______ , _______    , _______       , _______       , _______    , _______  ,     MO(_ADJUST) , KC_BSPC         , _______          , _______   , _______      , _______
),

//        ┌─────┬──────┬──────┬──────┬──────┬─────┐   ┌─────┬──────┬──────┬──────┬──────┬─────┐
//        │     │      │      │      │      │     │   │     │      │      │      │      │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │ f11 │  f1  │  f2  │  f3  │  f4  │ f5  │   │ f6  │  f7  │  f8  │  f9  │ f10  │ f13 │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │     │ 󰘶(1) │ ⎇(2) │ ^(3) │ 󰘳(4) │  5  │   │  6  │ 󰘳(7) │ ^(8) │ ⎇(9) │ 󰘶(0) │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │     │      │      │      │      │     │   │     │      │      │      │      │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
//        │     │      │      │      │      │     │   │     │      │      │      │      │     │
//        └─────┴──────┴──────┴──────┴──────┴─────┘   └─────┴──────┴──────┴──────┴──────┴─────┘
[_NUMBS] = LAYOUT_preonic_grid(
      _______ , _______      , _______      , _______      , _______      , _______ ,     _______ , _______      , _______      , _______      , _______      , _______,
      KC_F11  , KC_F1        , KC_F2        , KC_F3        , KC_F4        , KC_F5   ,     KC_F6   , KC_F7        , KC_F8        , KC_F9        , KC_F10       , KC_F13 ,
      _______ , LSFT_T(KC_1) , LALT_T(KC_2) , LCTL_T(KC_3) , LGUI_T(KC_4) , KC_5    ,     KC_6    , LGUI_T(KC_7) , LCTL_T(KC_8) , LALT_T(KC_9) , LSFT_T(KC_0) , _______,
      _______ , _______      , _______      , _______      , _______      , _______ ,     _______ , _______      , _______      , _______      , _______      , _______,
      _______ , _______      , _______      , _______      , _______      , _______ ,     _______ , _______      , _______      , _______      , _______      , _______
),

//        ┌─────┬───────────────┬─────┬────────┬─────────────┬─────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//        │     │               │     │        │             │     │   │      │      │      │      │     │     │
//        ├─────┼───────────────┼─────┼────────┼─────────────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │     │ MAC_SHOW_APPS │     │  G(-)  │    G(+)     │     │   │      │      │      │      │     │     │
//        ├─────┼───────────────┼─────┼────────┼─────────────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │     │       󰘶       │  ⎇  │   ^    │      󰘳      │     │   │ left │ down │  up  │ rght │ ent │     │
//        ├─────┼───────────────┼─────┼────────┼─────────────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │     │               │     │ LSG(`) │    G(`)     │     │   │ G([) │ G({) │ G(}) │ G(]) │     │     │
//        ├─────┼───────────────┼─────┼────────┼─────────────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │     │               │     │        │ MO(_ADJUST) │     │   │      │      │      │      │     │     │
//        └─────┴───────────────┴─────┴────────┴─────────────┴─────┘   └──────┴──────┴──────┴──────┴─────┴─────┘
[_NAV] = LAYOUT_preonic_grid(
      _______ , _______       , _______ , _______       , _______     , _______ ,     _______            , _______    , _______    , _______             , _______ , _______,
      _______ , MAC_SHOW_APPS , _______ , G(KC_MINS)    , G(KC_PLUS)  , _______ ,     _______            , _______    , _______    , _______             , _______ , _______,
      _______ , KC_LSFT       , KC_LALT , KC_LCTL       , KC_LGUI     , _______ ,     KC_LEFT            , KC_DOWN    , KC_UP      , KC_RIGHT            , KC_ENT  , _______,
      _______ , _______       , _______ , LSG(KC_GRAVE) , G(KC_GRAVE) , _______ ,     G(KC_LEFT_BRACKET) , G(KC_LCBR) , G(KC_RCBR) , G(KC_RIGHT_BRACKET) , _______ , _______,
      _______ , _______       , _______ , _______       , MO(_ADJUST) , _______ ,     _______            , _______    , _______    , _______             , _______ , _______
),

//        ┌─────────┬─────┬─────┬──────┬──────┬─────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//        │ QK_BOOT │     │     │      │      │     │   │      │      │      │      │     │     │
//        ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │         │     │     │ G(-) │ G(+) │     │   │ wh_u │ btn1 │ btn2 │ wh_d │     │     │
//        ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │         │     │     │ vold │ volu │     │   │ ms_l │ ms_d │ ms_u │ ms_r │     │     │
//        ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │         │     │     │      │      │     │   │ mprv │ mply │ mstp │ mnxt │     │     │
//        ├─────────┼─────┼─────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │         │     │     │      │      │     │   │      │      │      │      │     │     │
//        └─────────┴─────┴─────┴──────┴──────┴─────┘   └──────┴──────┴──────┴──────┴─────┴─────┘
[_ADJUST] = LAYOUT_preonic_grid(
      QK_BOOT , _______ , _______ , _______           , _______         , _______ ,     _______             , _______             , _______       , _______             , _______ , _______,
      _______ , _______ , _______ , G(KC_MINUS)       , G(KC_PLUS)      , _______ ,     KC_MS_WH_UP         , KC_BTN1             , KC_BTN2       , KC_MS_WH_DOWN       , _______ , _______,
      _______ , _______ , _______ , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , _______ ,     KC_MS_LEFT          , KC_MS_DOWN          , KC_MS_UP      , KC_MS_RIGHT         , _______ , _______,
      _______ , _______ , _______ , _______           , _______         , _______ ,     KC_MEDIA_PREV_TRACK , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_STOP , KC_MEDIA_NEXT_TRACK , _______ , _______,
      _______ , _______ , _______ , _______           , _______         , _______ ,     _______             , _______             , _______       , _______             , _______ , _______
)
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // If you find that you frequently trigger the modifier of your mod-tap(s) by accident,
    // for example, that's a sign that your tapping term may be too low so tap DT_UP a few
    // times to increase the tapping term until that no longer happens. On the flip side,
    // if you get superfluous characters when you actually intended to momentarily activate
    // a layer, tap DT_DOWN to lower the tapping term.
    switch (keycode) {
        case K_A:
        case K_S:
        case K_D:
        case K_F:

        case K_J:
        case K_K:
        case K_L:
        case K_SEMI:

        case LALT_T(KC_5):
        case LCTL_T(KC_3):
        case LGUI_T(KC_1):

        case LGUI_T(KC_0):
        case LCTL_T(KC_2):
        case LALT_T(KC_4):

            // found 200 pretty good just dropping a little
            // found 220 almost perfect but hitting mods on works like useCallback, useState it seems (maybe i was tired)
            // found 240 almost perfect but hitting mods on test
            return 260;
        case LCTL_T(KC_ESC):
            return 100;
        default:
            // default 200
            // 140 works well for most keys
            // 100,pretty darn tough, need to really tap that mofo
            return 140;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Get current mod and one-shot mod states.
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case UPDIR: // Types ../ to go up a directory on the shell.
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case ARROW: // Arrow macro, types -> or =>.
            if (record->event.pressed) {
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) { // Is shift held?
                    // Temporarily delete shift.
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_SHIFT);
                    SEND_STRING("->");
                    register_mods(mods); // Restore mods.
                } else {
                    SEND_STRING("=>");
                }
            }
            return false;
    }
    return true;
}

/*
qmk:json:start
{
  "comment_preview": {
    "keymap_overrides": {
      "UPDIR": "../",
      "ARROW": "=>",
      "KC_SPC": "\"_\"",
      "KC_MEH": "MEH",
      "KC_HYPR": ""
    }
  }
}
qmk:json:end
*/
