// QMK Ferris Sweep (ferris/sweep) keymap
// 7-layer layout: BASE, NAV, NUM, MOD, SWAY, SYM, FUNC
// No home row mods — Callum-style one-shot modifiers on dedicated layer

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _NUM,
    _MOD,
    _SWAY,
    _SYM,
    _FUNC
};

// Thumb keys — tap / hold layer
#define NAV_SPC  LT(_NAV, KC_SPC)
#define NUM_ESC  LT(_NUM, KC_ESC)
#define MOD_BSPC LT(_MOD, KC_BSPC)
#define SWY_ENT  LT(_SWAY, KC_ENT)

// Right home pinky — tap Tab / hold SYM layer
#define SYM_TAB  LT(_SYM, KC_TAB)

// Sway window manager macros ($mod = Super)
#define SW_1     LGUI(KC_1)
#define SW_2     LGUI(KC_2)
#define SW_3     LGUI(KC_3)
#define SW_4     LGUI(KC_4)
#define SW_5     LGUI(KC_5)
#define SW_6     LGUI(KC_6)
#define SW_7     LGUI(KC_7)
#define SW_8     LGUI(KC_8)
#define SW_9     LGUI(KC_9)
#define SW_FOCL  LGUI(KC_H)    // Focus left
#define SW_FOCD  LGUI(KC_J)    // Focus down
#define SW_FOCU  LGUI(KC_K)    // Focus up
#define SW_FOCR  LGUI(KC_L)    // Focus right
#define SW_KILL  SGUI(KC_Q)    // Kill focused window
#define SW_LNCH  LGUI(KC_D)    // App launcher
#define SW_FULL  LGUI(KC_F)    // Toggle fullscreen
#define SW_FLOT  SGUI(KC_SPC)  // Toggle floating
#define SW_SPLV  LGUI(KC_T)    // Split vertical
#define SW_SPLH  LGUI(KC_B)    // Split horizontal
#define SW_TERM  LGUI(KC_ENT)  // Open terminal
#define SW_RLOD  SGUI(KC_C)    // Reload sway config
#define SW_RESZ  LGUI(KC_R)    // Resize mode
#define SW_LOCK  LGUI(KC_ESC)  // Lock screen (swaylock)
#define SW_CLIP  LGUI(KC_P)    // Clipboard history (cliphist)
#define SW_EXIT  SGUI(KC_E)    // Exit Sway

// Combo: Q+P simultaneously types "nodemadic"
const uint16_t PROGMEM qp_combo[] = {KC_Q, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO_ACTION(qp_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (combo_index == 0 && pressed) {
        SEND_STRING("nodemadic");
    }
}

// One-shot modifier aliases (for MOD layer)
#define OS_LSFT  OSM(MOD_LSFT)
#define OS_LALT  OSM(MOD_LALT)
#define OS_LCTL  OSM(MOD_LCTL)
#define OS_LGUI  OSM(MOD_LGUI)
#define OS_RSFT  OSM(MOD_RSFT)
#define OS_RALT  OSM(MOD_RALT)
#define OS_RCTL  OSM(MOD_RCTL)
#define OS_RGUI  OSM(MOD_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │  Q       │  W       │  E       │  R       │  T       │   │  Y       │  U       │  I       │  O       │  P       │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  A       │  S       │  D       │  F       │  G       │   │  H       │  J       │  K       │  L       │ Tab/SYM  │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  Z       │  X       │  C       │  V       │  B       │   │  N       │  M       │  , <     │  . >     │ Shift    │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │ Esc/NUM  │ Spc/NAV  │   │ Bks/MOD  │ Ent/SWAY │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_BASE] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    SYM_TAB,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LSFT,
                                   NUM_ESC, NAV_SPC,      MOD_BSPC, SWY_ENT
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │          │          │          │          │          │   │          │          │          │          │          │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  Shift   │  Alt     │  Ctrl    │  Super   │          │   │  Left    │  Down    │  Up      │  Right   │          │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │          │          │          │          │  Delete  │   │  Home    │  PgDn    │  PgUp    │  End     │          │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │          │  [held]  │   │          │          │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_NAV] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   _______, _______,      _______, _______
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │          │          │          │          │          │   │  /       │  7       │  8       │  9       │  -       │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  Shift   │  Alt     │  Ctrl    │  Super   │  =       │   │  *       │  4       │  5       │  6       │  +       │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │          │          │          │          │          │   │  0       │  1       │  2       │  3       │  .       │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │  [held]  │          │   │          │          │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_NUM] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,      KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_EQL,      KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
        _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    KC_DOT,
                                   _______, _______,      _______,    KC_0
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │          │          │          │          │          │   │          │          │          │          │          │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  OSShift │  OSAlt   │  OSCtrl  │  OSSuper │          │   │          │  OSSuper │  OSCtrl  │  OSAlt   │  OSShift │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │          │          │          │          │          │   │          │          │          │          │          │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │          │          │   │  [held]  │          │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_MOD] = LAYOUT_split_3x5_2(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        OS_LSFT, OS_LALT, OS_LCTL, OS_LGUI, LGUI(KC_G),  _______, OS_RGUI, OS_RCTL, OS_RALT, OS_RSFT,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │  W1      │  W2      │  W3      │  W4      │  W5      │   │  W6      │  W7      │  W8      │  W9      │          │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  Kill    │  Launch  │  Full    │  Float   │  Resize  │   │  FocusL  │  FocusD  │  FocusU  │  FocusR  │  Exit    │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  Reload  │  Lock    │  Clip    │  SplitV  │  SplitH  │   │          │          │          │          │  Shift   │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │  Term    │          │   │          │  [held]  │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_SWAY] = LAYOUT_split_3x5_2(
        SW_1,    SW_2,    SW_3,    SW_4,    SW_5,         SW_6,    SW_7,    SW_8,    SW_9,    _______,
        SW_KILL, SW_LNCH, SW_FULL, SW_FLOT, SW_RESZ,     SW_FOCL, SW_FOCD, SW_FOCU, SW_FOCR, SW_EXIT,
        SW_RLOD, SW_LOCK, SW_CLIP, SW_SPLV, SW_SPLH,     _______, _______, _______, _______, KC_LSFT,
                                   SW_TERM, _______,     _______, _______
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │  !       │  @       │  #       │  $       │  %       │   │  ^       │  &       │  *       │  `       │  ~       │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  '       │  "       │  (       │  )       │  ;       │   │  /       │  -       │  =       │  :       │  [held]  │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  [       │  ]       │  {       │  }       │          │   │  \       │  _       │  +       │  |       │  ?       │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │          │          │   │          │          │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,
        KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_SCLN,     KC_SLSH, KC_MINS, KC_EQL,  KC_COLN, _______,
        KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,     KC_BSLS, KC_UNDS, KC_PLUS, KC_PIPE, KC_QUES,
                                   _______, _______,      _______, _______
    ),

    // ┌──────────┬──────────┬──────────┬──────────┬──────────┐   ┌──────────┬──────────┬──────────┬──────────┬──────────┐
    // │  F1      │  F2      │  F3      │  F4      │  F5      │   │  F6      │  F7      │  F8      │  F9      │  F10     │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │  F11     │  F12     │  PrtSc   │  CapsWd  │          │   │          │  BriUp   │  VolUp   │          │  Play    │
    // ├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
    // │          │          │          │          │  Boot    │   │          │  BriDn   │  VolDn   │  Mute    │          │
    // └──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │          │  [held]  │   │  [held]  │          │
    //                                  └──────────┴──────────┘   └──────────┴──────────┘
    [_FUNC] = LAYOUT_split_3x5_2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  KC_PSCR, CW_TOGG, _______,     _______, KC_BRIU, KC_VOLU, _______, KC_MPLY,
        _______, _______, _______, _______, QK_BOOT,     _______, KC_BRID, KC_VOLD, KC_MUTE, _______,
                                   _______, _______,      _______, _______
    )
};

// Tri-layer: holding NAV (Space) + MOD (Bksp) activates FUNC
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _MOD, _FUNC);
    return state;
}
