#include QMK_KEYBOARD_H
#include "flow.h"

// https://docs.qmk.fm/#/keycodes?id=midi

// clang-format off
enum preonic_layers {
  _QWERTY,
  _SYMBOLS,
  _NAV,
  _ADJUST
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    ARROW,
    OS_SYM,
    OS_NAV
};


#define L_NAV       MO(_NAV)
#define L_SYM       MO(_SYMBOLS)

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LSFT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LALT},
    {L_NAV, KC_LCTL},

    {L_SYM, KC_LCTL},
    {L_SYM, KC_LALT},
    {L_SYM, KC_LGUI},
    {L_SYM, KC_LSFT},
};

// for layers configuration follow this format:
// * custom layer key
// * layer name
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_SYM, _SYMBOLS},
    {OS_NAV, _NAV},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌─────────────┬─────┬──────┬──────┬───────┬──────┐   ┌────────────────┬─────┬─────┬─────┬─────┬──────┐
//        │     esc     │  1  │  2   │  3   │   4   │  5   │   │       6        │  7  │  8  │  9  │  0  │ f12  │
//        ├─────────────┼─────┼──────┼──────┼───────┼──────┤   ├────────────────┼─────┼─────┼─────┼─────┼──────┤
//        │     tab     │  q  │  w   │  e   │   r   │  t   │   │       y        │  u  │  i  │  o  │  p  │ ent  │
//        ├─────────────┼─────┼──────┼──────┼───────┼──────┤   ├────────────────┼─────┼─────┼─────┼─────┼──────┤
//        │    lctl     │  a  │  s   │  d   │   f   │  g   │   │       h        │  j  │  k  │  l  │  ;  │  '   │
//        ├─────────────┼─────┼──────┼──────┼───────┼──────┤   ├────────────────┼─────┼─────┼─────┼─────┼──────┤
//        │    lsft     │  z  │  x   │  c   │   v   │  b   │   │       n        │  m  │ cOC │  .  │  /  │ rsft │
//        ├─────────────┼─────┼──────┼──────┼───────┼──────┤   ├────────────────┼─────┼─────┼─────┼─────┼──────┤
//        │ MO(_ADJUST) │     │ lalt │ lgui │ L_SYM │ lalt │   │ LT(_NAV, bspc) │ "_" │     │     │     │      │
//        └─────────────┴─────┴──────┴──────┴───────┴──────┘   └────────────────┴─────┴─────┴─────┴─────┴──────┘
[_QWERTY] = LAYOUT_preonic_grid(
      KC_ESC      , KC_1    , KC_2    , KC_3    , KC_4  , KC_5    ,     KC_6              , KC_7   , KC_8    , KC_9    , KC_0    , KC_F12 ,
      KC_TAB      , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T    ,     KC_Y              , KC_U   , KC_I    , KC_O    , KC_P    , KC_ENT ,
      KC_LCTL     , KC_A    , KC_S    , KC_D    , KC_F  , KC_G    ,     KC_H              , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
      KC_LSFT     , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B    ,     KC_N              , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
      MO(_ADJUST) , _______ , KC_LALT , KC_LGUI , L_SYM , KC_LALT ,     LT(_NAV, KC_BSPC) , KC_SPC , _______ , _______ , _______ , _______
),

//        ┌─────┬──────┬──────┬──────┬──────┬─────┐   ┌─────────┬─────┬─────┬─────┬─────┬─────┐
//        │ f14 │  f1  │  f2  │  f3  │  f4  │ f5  │   │   f6    │ f7  │ f8  │ f9  │ f10 │ f11 │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │      │  *   │  _   │  %   │  @  │   │    -    │  [  │  ]  │  $  │  &  │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │ lsft │ lgui │ lalt │ lctl │  ~  │   │    (    │  {  │  }  │  )  │  \  │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │      │  ^   │  !   │  =   │ =>  │   │   ../   │  |  │  `  │  #  │  +  │     │
//        ├─────┼──────┼──────┼──────┼──────┼─────┤   ├─────────┼─────┼─────┼─────┼─────┼─────┤
//        │     │      │      │      │      │     │   │ A(bspc) │ ent │     │     │     │     │
//        └─────┴──────┴──────┴──────┴──────┴─────┘   └─────────┴─────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT_preonic_grid(
      KC_F14  , KC_F1   , KC_F2         , KC_F3         , KC_F4      , KC_F5    ,     KC_F6         , KC_F7               , KC_F8                , KC_F9          , KC_F10       , KC_F11 ,
      _______ , _______ , KC_ASTERISK   , KC_UNDERSCORE , KC_PERCENT , KC_AT    ,     KC_MINUS      , KC_LEFT_BRACKET     , KC_RIGHT_BRACKET     , KC_DOLLAR      , KC_AMPR      , _______,
      _______ , KC_LSFT , KC_LGUI       , KC_LALT       , KC_LCTL    , KC_TILDE ,     KC_LEFT_PAREN , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_RIGHT_PAREN , KC_BACKSLASH , _______,
      _______ , _______ , KC_CIRCUMFLEX , KC_EXCLAIM    , KC_EQUAL   , ARROW    ,     UPDIR         , KC_PIPE             , KC_GRAVE             , KC_HASH        , KC_PLUS      , _______,
      _______ , _______ , _______       , _______       , _______    , _______  ,     A(KC_BSPC)    , KC_ENT              , _______              , _______        , _______      , _______
),

//        ┌─────┬──────┬──────┬────────┬──────┬─────┐   ┌──────┬────────┬────────┬──────┬─────┬─────┐
//        │     │      │      │        │      │     │   │      │        │        │      │     │     │
//        ├─────┼──────┼──────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │  G(+)  │ G(-) │     │   │ G([) │ LSG([) │ LSG(]) │ G(]) │     │     │
//        ├─────┼──────┼──────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │ lsft │ lgui │  lalt  │ lctl │     │   │ left │  down  │   up   │ rght │ ent │     │
//        ├─────┼──────┼──────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │ LSG(`) │ G(`) │     │   │ mstp │  mply  │  mnxt  │ mprv │     │     │
//        ├─────┼──────┼──────┼────────┼──────┼─────┤   ├──────┼────────┼────────┼──────┼─────┼─────┤
//        │     │      │      │        │      │     │   │      │        │        │      │     │     │
//        └─────┴──────┴──────┴────────┴──────┴─────┘   └──────┴────────┴────────┴──────┴─────┴─────┘
[_NAV] = LAYOUT_preonic_grid(
      _______ , _______ , _______ , _______       , _______     , _______ ,     _______            , _______              , _______               , _______             , _______ , _______,
      _______ , _______ , _______ , G(KC_PLUS)    , G(KC_MINUS) , _______ ,     G(KC_LEFT_BRACKET) , LSG(KC_LEFT_BRACKET) , LSG(KC_RIGHT_BRACKET) , G(KC_RIGHT_BRACKET) , _______ , _______,
      _______ , KC_LSFT , KC_LGUI , KC_LALT       , KC_LCTL     , _______ ,     KC_LEFT            , KC_DOWN              , KC_UP                 , KC_RIGHT            , KC_ENT  , _______,
      _______ , _______ , _______ , LSG(KC_GRAVE) , G(KC_GRAVE) , _______ ,     KC_MEDIA_STOP      , KC_MEDIA_PLAY_PAUSE  , KC_MEDIA_NEXT_TRACK   , KC_MEDIA_PREV_TRACK , _______ , _______,
      _______ , _______ , _______ , _______       , _______     , _______ ,     _______            , _______              , _______               , _______             , _______ , _______
),

//        ┌─────────┬─────────┬────────┬─────────┬────────┬─────┐   ┌────────┬──────┬──────┬──────┬─────┬─────┐
//        │ QK_BOOT │         │        │         │        │     │   │        │      │      │      │     │     │
//        ├─────────┼─────────┼────────┼─────────┼────────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//        │ RGB_TOG │ DT_PRNT │ DT_UP  │ DT_DOWN │        │     │   │  wh_u  │ btn1 │ btn2 │ wh_d │     │     │
//        ├─────────┼─────────┼────────┼─────────┼────────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//        │ RGB_MOD │         │        │         │        │     │   │  ms_l  │ ms_d │ ms_u │ ms_r │     │     │
//        ├─────────┼─────────┼────────┼─────────┼────────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//        │         │ MUV_DE  │ MUV_IN │  MU_ON  │ MU_OFF │     │   │ MI_OFF │      │      │      │     │     │
//        ├─────────┼─────────┼────────┼─────────┼────────┼─────┤   ├────────┼──────┼──────┼──────┼─────┼─────┤
//        │         │         │        │  vold   │        │     │   │        │      │ volu │      │     │     │
//        └─────────┴─────────┴────────┴─────────┴────────┴─────┘   └────────┴──────┴──────┴──────┴─────┴─────┘
[_ADJUST] = LAYOUT_preonic_grid(
      QK_BOOT , _______ , _______ , _______           , _______ , _______ ,     _______     , _______    , _______         , _______       , _______ , _______,
      RGB_TOG , DT_PRNT , DT_UP   , DT_DOWN           , _______ , _______ ,     KC_MS_WH_UP , KC_BTN1    , KC_BTN2         , KC_MS_WH_DOWN , _______ , _______,
      RGB_MOD , _______ , _______ , _______           , _______ , _______ ,     KC_MS_LEFT  , KC_MS_DOWN , KC_MS_UP        , KC_MS_RIGHT   , _______ , _______,
      _______ , MUV_DE  , MUV_IN  , MU_ON             , MU_OFF  , _______ ,     MI_OFF      , _______    , _______         , _______       , _______ , _______,
      _______ , _______ , _______ , KC_AUDIO_VOL_DOWN , _______ , _______ ,     _______     , _______    , KC_AUDIO_VOL_UP , _______       , _______ , _______
)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Get current mod and one-shot mod states.
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

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

void matrix_scan_user(void) {
    flow_matrix_scan();
}

/*
qmk:json:start
{
  "comment_preview": {
    "keymap_overrides": {
      "UPDIR": "../",
      "ARROW": "=>",
      "KC_SPC": "\"_\""
    }
  }
}
qmk:json:end
*/
