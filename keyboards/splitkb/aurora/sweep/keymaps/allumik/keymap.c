// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#include QMK_KEYBOARD_H

#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

// like an onion
enum layers { _BASE, _GAMEL, _GAMEPLUSL, _NAVR, _MOUR, _NSL, _FUNL };

// Don't forget to edit the rules.mk and config.h accordingly
#define COMBO_COUNT 17
enum combo_events {
  OPEN_PAR, CLOSE_PAR, OPEN_BRA, CLOSE_BRA, GT, LT, MINUS, EQUAL,
  SUPER_L, SUPER_R, LALT_L, LALT_R, ALGR_L, ALGR_R,
  TAB, DEL,
  GAMEM
};

// some convinience combos
const uint16_t PROGMEM opar_combo[]  = { KC_T, KC_G, COMBO_END };
const uint16_t PROGMEM cpar_combo[]  = { KC_N, KC_M, COMBO_END };
const uint16_t PROGMEM obra_combo[]  = { KC_D, KC_V, COMBO_END };
const uint16_t PROGMEM cbra_combo[]  = { KC_H, KC_K, COMBO_END };
const uint16_t PROGMEM gt_combo[] = { KC_L, KC_J, COMBO_END };
const uint16_t PROGMEM lt_combo[] = { KC_P, KC_B, COMBO_END };
const uint16_t PROGMEM minus_combo[] = { KC_B, KC_G, COMBO_END };
const uint16_t PROGMEM equal_combo[] = { KC_J, KC_M, COMBO_END };

// the modifier combos, super, lalgr and lalt
const uint16_t PROGMEM super_left_combo[]  = { KC_T, KC_D, COMBO_END };
const uint16_t PROGMEM super_right_combo[] = { KC_N, KC_H, COMBO_END };
const uint16_t PROGMEM lalgr_left_combo[]   = { KC_G, KC_V, COMBO_END };
const uint16_t PROGMEM lalgr_right_combo[]  = { KC_M, KC_K, COMBO_END };
const uint16_t PROGMEM lalt_left_combo[]  = { KC_S, KC_C, COMBO_END };
const uint16_t PROGMEM lalt_right_combo[] = { KC_E, KC_COMM, COMBO_END };

// the "missing" thumb keys for Delete and Tab
const uint16_t PROGMEM tab_combo[]  = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM del_combo[] = { KC_Y, KC_QUOTE, COMBO_END };

// combo for the game layer
const uint16_t PROGMEM game_mode[] = { KC_B, KC_J, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  [OPEN_PAR]  = COMBO(opar_combo,  KC_LPRN),
  [CLOSE_PAR] = COMBO(cpar_combo,  KC_RPRN),
  [OPEN_BRA]  = COMBO(obra_combo,  KC_LBRC),
  [CLOSE_BRA] = COMBO(cbra_combo,  KC_RBRC),
  [GT]        = COMBO(gt_combo, KC_GT),
  [LT]        = COMBO(lt_combo, KC_LT),
  [MINUS] = COMBO(minus_combo, KC_MINS),
  // could just add <plus> keycode but it's more functional here with shift + combo
  [EQUAL] = COMBO(equal_combo, KC_EQL),

  [SUPER_L] = COMBO(super_left_combo,  KC_LGUI),
  [SUPER_R] = COMBO(super_right_combo, KC_LGUI),
  [LALT_L]  = COMBO(lalt_left_combo,   KC_LALT),
  [LALT_R]  = COMBO(lalt_right_combo,  KC_LALT),
  [ALGR_L]  = COMBO(lalgr_left_combo,   KC_ALGR),
  [ALGR_R]  = COMBO(lalgr_right_combo,  KC_ALGR),

  [TAB] = COMBO(tab_combo, KC_TAB),
  [DEL] = COMBO(del_combo, KC_DEL),

  // activate the GAME MODE!!! WOOW
  [GAMEM] = COMBO(game_mode, DF(_GAMEL)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_2(
    KC_Q,         KC_W,         KC_F, KC_P,              KC_B,              KC_J,              KC_L,            KC_U,    KC_Y,           KC_QUOT,
    KC_A,         KC_R,         KC_S, KC_T,              KC_G,              KC_M,              KC_N,            KC_E,    KC_I,           KC_O,
    LCTL_T(KC_Z), LSFT_T(KC_X), KC_C, KC_D,              KC_V,              KC_K,              KC_H,            KC_COMM, LSFT_T(KC_DOT), LCTL_T(KC_SLSH),
                                      LT(_NAVR, KC_SPC), LT(_MOUR, KC_ESC), LT(_FUNL, KC_ENT), LT(_NSL, KC_BSPC)
  ),

  [_NAVR] = LAYOUT_split_3x5_2(
    KC_NA,   KC_NA,   KC_NA,    KC_NA,   KC_NA,   KC_CAPS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
    KC_NA,   KC_NA,   KC_NA,    KC_NA,   KC_NA,   KC_AGIN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_LCTL, KC_LSFT, KC_LALT,  KC_LGUI, KC_ALGR, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                KC_NA,   KC_NA,   KC_ENT,  KC_BSPC
  ),
  [_MOUR] = LAYOUT_split_3x5_2(
    KC_NA,   KC_NA,   KC_NA,    KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_MS_U, KC_NU,   KC_NU,
    KC_NA,   KC_NA,   KC_NA,    KC_NA,   KC_NA,   KC_NU,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NU,
    KC_LCTL, KC_LSFT, KC_LALT,  KC_LGUI, KC_ALGR, KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                                KC_NA,   KC_NA,   KC_BTN1, KC_BTN2
  ),
  [_FUNL] = LAYOUT_split_3x5_2(
    KC_F12, KC_F7, KC_F8, KC_F9,  KC_PSCR, KC_NU,   KC_NU,   KC_MPRV, KC_MNXT, CM_TOGG,
    KC_F11, KC_F4, KC_F5, KC_F6,  KC_SLCT, KC_MSTP, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE,
    KC_F10, KC_F1, KC_F2, KC_F3,  KC_PAUS, KC_ALGR, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,
                          KC_TAB, KC_ESC,  KC_NA,   KC_NA
  ),
  [_NSL] = LAYOUT_split_3x5_2(
    KC_LBRC, KC_7, KC_8,  KC_9, KC_RBRC, KC_NA,   KC_NA,   KC_NA,   ALGR(KC_LBRC), ALGR(KC_RBRC),
    KC_SCLN, KC_4, KC_5,  KC_6, KC_EQL,  KC_NA,   KC_NA,   KC_NA,   ALGR(KC_SCLN), ALGR(KC_QUOT),
    KC_GRV,  KC_1, KC_2,  KC_3, KC_BSLS, KC_ALGR, KC_LGUI, KC_LALT, KC_LSFT,       KC_LCTL,
                          KC_0, KC_MINS, KC_NA,   KC_NA
  ),

  [_GAMEL] = LAYOUT_split_3x5_2(
    KC_TAB,  KC_Q, KC_W, KC_E,   KC_R,                   KC_T,              KC_Y,            KC_U, KC_I,    KC_O,
    KC_LSFT, KC_A, KC_S, KC_D,   KC_F,                   KC_G,              KC_H,            KC_J, KC_K,    KC_L,
    KC_LCTL, KC_Z, KC_X, KC_C,   KC_V,                   KC_B,              KC_N,            KC_M, KC_COMM, KC_DOT,
                         KC_SPC, LT(_GAMEPLUSL, KC_ENT), LT(_FUNL, KC_ESC), LT(_NSL, KC_BSPC)
  ),
  [_GAMEPLUSL] = LAYOUT_split_3x5_2(
    KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS,   KC_6,      KC_PGUP, KC_EQL,  KC_GRV,  KC_P,   KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_5,      KC_HOME, KC_MINS, KC_SCLN, KC_L,   KC_BSLS,
    KC_TRNS, KC_1,    KC_2,    KC_3,      KC_4,      KC_PGDN, KC_RBRC, KC_LBRC, KC_DOT, KC_SLSH,
                               DF(_BASE), KC_NA, KC_ENT,  KC_BSPC
  ),

};
