#include QMK_KEYBOARD_H

// https://docs.qmk.fm/#/keycodes?id=midi

// clang-format off
enum preonic_layers {
  _QWERTY,
  _SYMBOLS,
  _NUMBERS,
  _NAV,
  _ADJUST,
  _MOUSE,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌──────┬───────────┬───────────┬───────────┬──────────────┬──────┐   ┌────────────────┬───────────┬───────────┬───────────┬───────────┬──────┐
//        │ esc  │     1     │     2     │     3     │      4       │  5   │   │       6        │     7     │     8     │     9     │     0     │ f12  │
//        ├──────┼───────────┼───────────┼───────────┼──────────────┼──────┤   ├────────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │ tab  │     q     │     w     │     e     │      r       │  t   │   │       y        │     u     │     i     │     o     │     p     │ ent  │
//        ├──────┼───────────┼───────────┼───────────┼──────────────┼──────┤   ├────────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │ lctl │ LSFT_T(a) │ LALT_T(s) │ LCTL_T(d) │  LGUI_T(f)   │  g   │   │       h        │ LGUI_T(j) │ LCTL_T(k) │ LALT_T(l) │ LSFT_T(;) │  '   │
//        ├──────┼───────────┼───────────┼───────────┼──────────────┼──────┤   ├────────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │ lsft │     z     │     x     │     c     │      v       │  b   │   │       n        │     m     │     ,     │     .     │     /     │ rsft │
//        ├──────┼───────────┼───────────┼───────────┼──────────────┼──────┤   ├────────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │      │           │           │   lgui    │ MO(_SYMBOLS) │ lsft │   │ LT(_NAV, bspc) │    "_"    │           │           │           │      │
//        └──────┴───────────┴───────────┴───────────┴──────────────┴──────┘   └────────────────┴───────────┴───────────┴───────────┴───────────┴──────┘
[_QWERTY] = LAYOUT_preonic_grid(
      KC_ESC  , KC_1         , KC_2         , KC_3         , KC_4         , KC_5    ,     KC_6              , KC_7         , KC_8         , KC_9         , KC_0            , KC_F12 ,
      KC_TAB  , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T    ,     KC_Y              , KC_U         , KC_I         , KC_O         , KC_P            , KC_ENT ,
      KC_LCTL , LSFT_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LGUI_T(KC_F) , KC_G    ,     KC_H              , LGUI_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , LSFT_T(KC_SCLN) , KC_QUOT,
      KC_LSFT , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B    ,     KC_N              , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         , KC_RSFT,
      _______ , _______      , _______      , KC_LGUI      , MO(_SYMBOLS) , KC_LSFT ,     LT(_NAV, KC_BSPC) , KC_SPC       , _______      , _______      , _______         , _______
),

//        ┌─────┬────────────┬─────┬─────┬─────┬─────┐   ┌─────────────┬─────┬─────┬─────┬─────┬─────┐
//        │ f14 │     f1     │ f2  │ f3  │ f4  │ f5  │   │     f6      │ f7  │ f8  │ f9  │ f10 │ f11 │
//        ├─────┼────────────┼─────┼─────┼─────┼─────┤   ├─────────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │ TG(_MOUSE) │  *  │  _  │  %  │  @  │   │     ../     │  [  │  ]  │  $  │     │     │
//        ├─────┼────────────┼─────┼─────┼─────┼─────┤   ├─────────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │     !      │  =  │  (  │  )  │  ~  │   │      -      │  {  │  }  │ =>  │  \  │     │
//        ├─────┼────────────┼─────┼─────┼─────┼─────┤   ├─────────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │            │  ^  │  &  │  +  │     │   │             │  |  │  `  │  #  │     │     │
//        ├─────┼────────────┼─────┼─────┼─────┼─────┤   ├─────────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │            │     │     │     │     │   │ MO(_ADJUST) │     │     │     │     │     │
//        └─────┴────────────┴─────┴─────┴─────┴─────┘   └─────────────┴─────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT_preonic_grid(
      KC_F14  , KC_F1      , KC_F2         , KC_F3         , KC_F4          , KC_F5    ,     KC_F6       , KC_F7               , KC_F8                , KC_F9     , KC_F10       , KC_F11 ,
      _______ , TG(_MOUSE) , KC_ASTERISK   , KC_UNDERSCORE , KC_PERCENT     , KC_AT    ,     UPDIR       , KC_LEFT_BRACKET     , KC_RIGHT_BRACKET     , KC_DOLLAR , _______      , _______,
      _______ , KC_EXCLAIM , KC_EQUAL      , KC_LEFT_PAREN , KC_RIGHT_PAREN , KC_TILDE ,     KC_MINUS    , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , ARROW     , KC_BACKSLASH , _______,
      _______ , _______    , KC_CIRCUMFLEX , KC_AMPR       , KC_PLUS        , _______  ,     _______     , KC_PIPE             , KC_GRAVE             , KC_HASH   , _______      , _______,
      _______ , _______    , _______       , _______       , _______        , _______  ,     MO(_ADJUST) , _______             , _______              , _______   , _______      , _______
),

//        ┌─────┬──────┬──────┬──────┬─────────────┬─────┐   ┌──────┬────────┬────────┬──────┬─────┬─────┐
//        │     │      │      │      │             │     │   │      │        │        │      │     │     │
//        ├─────┼──────┼──────┼──────┼─────────────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │      │             │     │   │ G([) │ LSG([) │ LSG(]) │ G(]) │     │     │
//        ├─────┼──────┼──────┼──────┼─────────────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │ lsft │ lalt │ lctl │    lgui     │     │   │ left │  down  │   up   │ rght │ ent │     │
//        ├─────┼──────┼──────┼──────┼─────────────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │      │             │     │   │ home │  bspc  │  del   │ end  │     │     │
//        ├─────┼──────┼──────┼──────┼─────────────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │      │ MO(_ADJUST) │     │   │      │        │        │      │     │     │
//        └─────┴──────┴──────┴──────┴─────────────┴─────┘   └──────┴────────┴────────┴──────┴─────┴─────┘
[_NAV] = LAYOUT_preonic_grid(
      _______ , _______ , _______ , _______ , _______     , _______ ,     _______            , _______              , _______               , _______             , _______ , _______,
      _______ , _______ , _______ , _______ , _______     , _______ ,     G(KC_LEFT_BRACKET) , LSG(KC_LEFT_BRACKET) , LSG(KC_RIGHT_BRACKET) , G(KC_RIGHT_BRACKET) , _______ , _______,
      _______ , KC_LSFT , KC_LALT , KC_LCTL , KC_LGUI     , _______ ,     KC_LEFT            , KC_DOWN              , KC_UP                 , KC_RIGHT            , KC_ENT  , _______,
      _______ , _______ , _______ , _______ , _______     , _______ ,     KC_HOME            , KC_BSPC              , KC_DEL                , KC_END              , _______ , _______,
      _______ , _______ , _______ , _______ , MO(_ADJUST) , _______ ,     _______            , _______              , _______               , _______             , _______ , _______
),

//        ┌────────────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//        │ TG(_MOUSE) │      │      │      │      │      │   │      │      │      │      │     │     │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │            │ G(q) │ G(w) │ G(e) │ G(r) │ G(t) │   │ wh_u │ btn1 │ btn2 │ wh_d │     │     │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │            │ G(a) │ G(s) │ G(d) │ G(f) │ G(g) │   │ ms_l │ ms_d │ ms_u │ ms_r │     │     │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │            │ G(z) │ G(x) │ G(c) │ G(v) │ G(b) │   │      │      │      │      │     │     │
//        ├────────────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//        │            │      │      │      │      │      │   │      │      │      │      │     │     │
//        └────────────┴──────┴──────┴──────┴──────┴──────┘   └──────┴──────┴──────┴──────┴─────┴─────┘
[_MOUSE] = LAYOUT_preonic_grid(
      TG(_MOUSE) , _______ , _______ , _______ , _______ , _______ ,     _______     , _______    , _______  , _______       , _______ , _______,
      _______    , G(KC_Q) , G(KC_W) , G(KC_E) , G(KC_R) , G(KC_T) ,     KC_MS_WH_UP , KC_BTN1    , KC_BTN2  , KC_MS_WH_DOWN , _______ , _______,
      _______    , G(KC_A) , G(KC_S) , G(KC_D) , G(KC_F) , G(KC_G) ,     KC_MS_LEFT  , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT   , _______ , _______,
      _______    , G(KC_Z) , G(KC_X) , G(KC_C) , G(KC_V) , G(KC_B) ,     _______     , _______    , _______  , _______       , _______ , _______,
      _______    , _______ , _______ , _______ , _______ , _______ ,     _______     , _______    , _______  , _______       , _______ , _______
),

//        ┌─────┬─────────┬───────┬─────────┬──────┬─────┐   ┌──────┬────────────────────────┬───────────────┬──────┬─────┬─────┐
//        │     │ DT_PRNT │ DT_UP │ DT_DOWN │      │     │   │      │                        │               │      │     │     │
//        ├─────┼─────────┼───────┼─────────┼──────┼─────┤   ├──────┼────────────────────────┼───────────────┼──────┼─────┼─────┤
//        │     │         │       │  G(-)   │ G(+) │     │   │      │ OSM(MOD_LCTL|MOD_LGUI) │               │      │     │     │
//        ├─────┼─────────┼───────┼─────────┼──────┼─────┤   ├──────┼────────────────────────┼───────────────┼──────┼─────┼─────┤
//        │     │         │       │  vold   │ volu │     │   │      │      OSM(MOD_MEH)      │ OSM(MOD_HYPR) │      │     │     │
//        ├─────┼─────────┼───────┼─────────┼──────┼─────┤   ├──────┼────────────────────────┼───────────────┼──────┼─────┼─────┤
//        │     │ QK_BOOT │       │ LSG(`)  │ G(`) │     │   │ mprv │          mply          │     mstp      │ mnxt │     │     │
//        ├─────┼─────────┼───────┼─────────┼──────┼─────┤   ├──────┼────────────────────────┼───────────────┼──────┼─────┼─────┤
//        │     │         │       │         │      │     │   │      │                        │               │      │     │     │
//        └─────┴─────────┴───────┴─────────┴──────┴─────┘   └──────┴────────────────────────┴───────────────┴──────┴─────┴─────┘
[_ADJUST] = LAYOUT_preonic_grid(
      _______ , DT_PRNT , DT_UP   , DT_DOWN           , _______         , _______ ,     _______             , _______                , _______       , _______             , _______ , _______,
      _______ , _______ , _______ , G(KC_MINUS)       , G(KC_PLUS)      , _______ ,     _______             , OSM(MOD_LCTL|MOD_LGUI) , _______       , _______             , _______ , _______,
      _______ , _______ , _______ , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , _______ ,     _______             , OSM(MOD_MEH)           , OSM(MOD_HYPR) , _______             , _______ , _______,
      _______ , QK_BOOT , _______ , LSG(KC_GRAVE)     , G(KC_GRAVE)     , _______ ,     KC_MEDIA_PREV_TRACK , KC_MEDIA_PLAY_PAUSE    , KC_MEDIA_STOP , KC_MEDIA_NEXT_TRACK , _______ , _______,
      _______ , _______ , _______ , _______           , _______         , _______ ,     _______             , _______                , _______       , _______             , _______ , _______
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
        case LSFT_T(KC_A):
        case LALT_T(KC_S):
        case LCTL_T(KC_D):
        case LGUI_T(KC_F):
        case LGUI_T(KC_J):
        case LCTL_T(KC_K):
        case LALT_T(KC_L):
        case LSFT_T(KC_SCLN):
            // found 200 pretty good, just dropping a little
            return 220;
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
      "KC_MEH": "MEH"
    }
  }
}
qmk:json:end
*/
