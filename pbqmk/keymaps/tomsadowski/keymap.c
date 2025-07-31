// tomsadowski
// keymap for split_3x5_2 keyboards

#include QMK_KEYBOARD_H
#include "action.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "process_combo.h"

//                           . 3 3 . .          . . 3 3 .
const uint16_t PROGMEM    tab_cmb_l[] = {KC_C,    KC_H,    COMBO_END};
const uint16_t PROGMEM    tab_cmb_r[] = {KC_W,    KC_P,    COMBO_END};
//                           . 2 2 . .          . . 2 2 .
const uint16_t PROGMEM  shift_cmb_l[] = {KC_S,    KC_R,    COMBO_END};
const uint16_t PROGMEM  shift_cmb_r[] = {KC_I,    KC_O,    COMBO_END};
//                           . 1 1 . .          . . 1 1 .
const uint16_t PROGMEM   caps_cmb_l[] = {KC_F,    KC_L,    COMBO_END};
const uint16_t PROGMEM   home_cmb_r[] = {KC_M,    KC_G,    COMBO_END};
//                           3 . . 3 .          . 3 . . 3
const uint16_t PROGMEM    alt_cmb_l[] = {KC_K,    KC_B,    COMBO_END};
const uint16_t PROGMEM    alt_cmb_r[] = {KC_Y,    KC_V,    COMBO_END};
//                           2 . . 2 .          . 2 . . 2
const uint16_t PROGMEM   ctrl_cmb_l[] = {KC_A,    KC_T,    COMBO_END};
const uint16_t PROGMEM   ctrl_cmb_r[] = {KC_E,    KC_N,    COMBO_END};
//                           1 . . 1 .          . 1 . . 1
const uint16_t PROGMEM  lnav2_cmb_l[] = {KC_J,    KC_D,    COMBO_END};
const uint16_t PROGMEM  mouse_cmb_r[] = {KC_U,    KC_Q,    COMBO_END};
//                           3 . . . 3          3 . . . 3
const uint16_t PROGMEM  game2_cmb_l[] = {KC_K,    KC_X,    COMBO_END};
const uint16_t PROGMEM  game3_cmb_r[] = {KC_Z,    KC_V,    COMBO_END};
//                           3 . . 2 .          . 2 . . 3
const uint16_t PROGMEM    gui_cmb_l[] = {KC_T,    KC_K,    COMBO_END};
const uint16_t PROGMEM    gui_cmb_r[] = {KC_E,    KC_V,    COMBO_END};
//                           2 . . 1 .          . 1 . . 2
const uint16_t PROGMEM  lnav1_cmb_l[] = {KC_A,    KC_D,    COMBO_END};
const uint16_t PROGMEM  numbe_cmb_r[] = {KC_U,    KC_N,    COMBO_END};
//                           . . . 3 2          2 3 . . .
const uint16_t PROGMEM    esc_cmb_l[] = {KC_B,    KC_COMM, COMBO_END};
const uint16_t PROGMEM  enter_cmb_r[] = {KC_DOT,  KC_Y,    COMBO_END};

enum combos
{
    // . 3 3 . .     . . 3 3 .
    TAB_CMB_L,     TAB_CMB_R,
    // . 2 2 . .     . . 2 2 .
    SHIFT_CMB_L,   SHIFT_CMB_R,
    // . 1 1 . .     . . 1 1 .
    CAPS_CMB_L,    HOME_CMB_R,
    // 3 . . 3 .     . 3 . . 3
    ALT_CMB_L,     ALT_CMB_R,
    // 2 . . 2 .     . 2 . . 2
    CTRL_CMB_L,    CTRL_CMB_R,
    // 1 . . 1 .     . 1 . . 1
    LNAV2_CMB_L,   MOUSE_CMB_R,
    // 3 . . . 3     3 . . . 3
    GAME2_CMB_L,   GAME3_CMB_R,
    // 3 . . 2 .     . 2 . . 3
    GUI_CMB_L,     GUI_CMB_R,
    // 2 . . 1 .     . 1 . . 2
    LNAV1_CMB_L,   NUMBE_CMB_R,
    // . . . 3 2     2 3 . . .
    ESC_CMB_L,     ENTER_CMB_R,
};

enum custom_keycodes
{
    LAYOUT_HOME = SAFE_RANGE,
    CAPS_ON
};

enum layers
{
    ALPHA_LYR,
    NUMBE_LYR,
    MOUSE_LYR,
    LNAV1_LYR,
    LNAV2_LYR,
    GAME2_LYR,
    GAME3_LYR,
    ALPHA_FROM_NUMBE_LYR,
    ALPHA_FROM_MOUSE_LYR,
    NUMBE_FROM_OTHER_LYR,
    MOUSE_FROM_OTHER_LYR,
};

// switching to non-alpha layers breaks capsword
layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state))
    {
        case NUMBE_LYR ... LNAV2_LYR:
            caps_word_off();
            break;
        case GAME2_LYR:
            caps_word_off();
            combo_disable();
            break;
        case GAME3_LYR:
            caps_word_off();
            combo_disable();
            break;
        default:
            break;
    }
    return state;
}

combo_t key_combos[] =
{
    // . 3 3 . .     . . 3 3 .
    [TAB_CMB_L]   = COMBO(   tab_cmb_l, KC_TAB),
    [TAB_CMB_R]   = COMBO(   tab_cmb_r, KC_TAB),
    // . 2 2 . .    . . 2 2 .
    [SHIFT_CMB_L] = COMBO( shift_cmb_l, KC_LEFT_SHIFT),
    [SHIFT_CMB_R] = COMBO( shift_cmb_r, KC_RIGHT_SHIFT),
    // . 1 1 . .    . . 1 1 .
    [CAPS_CMB_L]  = COMBO(  caps_cmb_l, CAPS_ON),
    [HOME_CMB_R]  = COMBO(  home_cmb_r, LAYOUT_HOME),
    // 3 . . 3 .    . 3 . . 3
    [ALT_CMB_L]   = COMBO(   alt_cmb_l, KC_LEFT_ALT),
    [ALT_CMB_R]   = COMBO(   alt_cmb_r, KC_RIGHT_ALT),
    // 2 . . 2 .    . 2 . . 2
    [CTRL_CMB_L]  = COMBO(  ctrl_cmb_l, KC_LEFT_CTRL),
    [CTRL_CMB_R]  = COMBO(  ctrl_cmb_r, KC_RIGHT_CTRL),
    // 1 . . 1 .    . 1 . . 1
    [LNAV2_CMB_L] = COMBO( lnav2_cmb_l, TO(LNAV2_LYR)),
    [MOUSE_CMB_R] = COMBO( mouse_cmb_r, TO(MOUSE_LYR)),
    // 2 . . . 2    2 . . . 2
    [GAME2_CMB_L] = COMBO( game2_cmb_l, TO(GAME2_LYR)),
    [GAME3_CMB_R] = COMBO( game3_cmb_r, TO(GAME3_LYR)),
    // 3 . . 2 .    . 2 . . 3
    [GUI_CMB_L]   = COMBO(   gui_cmb_l, KC_LEFT_GUI),
    [GUI_CMB_R]   = COMBO(   gui_cmb_r, KC_RIGHT_GUI),
    // 2 . . 1 .    . 1 . . 2
    [LNAV1_CMB_L] = COMBO( lnav1_cmb_l, TO(LNAV1_LYR)),
    [NUMBE_CMB_R] = COMBO( numbe_cmb_r, TO(NUMBE_LYR)),
    // . . . 3 2    2 3 . . .
    [ESC_CMB_L]   = COMBO(   esc_cmb_l, KC_ESCAPE),
    [ENTER_CMB_R] = COMBO( enter_cmb_r, KC_ENTER),
};

// KC_ESCAPE breaks capsword, KC_SPACE does not
bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode)
    {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LEFT_SHIFT));
            return true;
        case KC_ESCAPE:
            return false;
        default:
            return true;
    }
}

// process custom keys
bool process_record_user(uint16_t keycode,
                         keyrecord_t* record)
{
    switch (keycode)
    {
        case LAYOUT_HOME:
            if (record->event.pressed)
            {
                caps_word_off();
                layer_move(ALPHA_LYR);
            }
            return false;

        case CAPS_ON:
            if (record->event.pressed)
                caps_word_on();
            return false;

        default:
            return true;
    }
}

// layers

#define HOLD_MOUSE_TAP_SPACE            LT(MOUSE_FROM_OTHER_LYR, KC_SPC)
#define HOLD_NUMBE_TAP_SPACE            LT(NUMBE_FROM_OTHER_LYR, KC_SPC)
#define HOLD_ALPHA_TAP_SPACE_FROM_NUMBE LT(ALPHA_FROM_NUMBE_LYR, KC_SPC)
#define HOLD_ALPHA_TAP_SPACE_FROM_MOUSE LT(ALPHA_FROM_MOUSE_LYR, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
// alpha layer (home layer)
// - contains: alphabet, space, backspace, delete
[ALPHA_LYR] = LAYOUT_split_3x5_2(
KC_K,    KC_C,    KC_H,    KC_B,    KC_X,     KC_Z,    KC_Y,    KC_W,    KC_P,    KC_V,
KC_A,    KC_S,    KC_R,    KC_T,    KC_COMMA, KC_DOT,  KC_E,    KC_I,    KC_O,    KC_N,
KC_J,    KC_F,    KC_L,    KC_D,    KC_QUOT,  KC_SCLN, KC_U,    KC_M,    KC_G,    KC_Q,
         KC_BSPC, HOLD_MOUSE_TAP_SPACE,       HOLD_NUMBE_TAP_SPACE,       KC_DEL),
// number layer
// - contains: digits, arrow-keys, misc symbols, misc navigation
[NUMBE_LYR] = LAYOUT_split_3x5_2(
KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
KC_INS,  KC_LBRC, KC_RBRC, KC_EQL,  _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                           _______, _______, HOLD_ALPHA_TAP_SPACE_FROM_NUMBE,  _______),
// mouse layer
// - contains: function keys 1-13, printscreen,
// cursor direction/speed, scroll-wheel direction/speed,
// left and right click
[MOUSE_LYR] = LAYOUT_split_3x5_2(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
KC_BTN6, KC_BTN5, KC_BTN4, KC_BTN3, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
KC_F11,  KC_F12,  KC_F13,  KC_PSCR, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
_______, HOLD_ALPHA_TAP_SPACE_FROM_MOUSE,    KC_BTN1, KC_BTN2),
// lnav1 layer
// - contains the navigation keys found in the number layer, but under the left hand
[LNAV1_LYR] = LAYOUT_split_3x5_2(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______,
KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______,
                           _______, KC_SPC,  KC_SPC,  _______),
// lnav2 layer
// - contains the mouse keys found in the mouse layer, but under the left hand
[LNAV2_LYR] = LAYOUT_split_3x5_2(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______,
KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______,
                           KC_BTN2, KC_BTN1, KC_SPC,  _______),
// 2D game layer
// - same as alpha layer with the following exceptions:
//  - combos deactivated
//  - KC_SPACE replaces HOLD_MOUSE_TAP_SPACE
//  - KC_0 replaces HOLD_NUMBE_TAP_SPACE
//  - KC_ESCAPE replaces KC_QUOTE
//  - KC_ENTER replaces KC_SCLN
[GAME2_LYR] = LAYOUT_split_3x5_2(
_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
_______, _______, _______, _______, KC_ESC,   KC_ENT,  _______, _______, _______, _______,
                           _______, KC_SPC,   KC_0,    _______),
// 3D game layer
// - same as alpha layer with the following exceptions:
//  - combos deactivated
//  - KC_SPACE replaces HOLD_MOUSE_TAP_SPACE
//  - KC_BTN1, KC_BTN2, replaces HOLD_NUMBE_TAP_SPACE, KC_DEL respectively
//  - KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R replaces KC_E, KC_I, KC_O, KC_N respectively
[GAME3_LYR] = LAYOUT_split_3x5_2(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
_______, _______, _______, _______, KC_ESC,  KC_ENT,  _______, _______, _______, _______,
                           _______, KC_SPC,  KC_BTN1, KC_BTN2),
// alpha-from-number layer
// - alpha layer momentarily accessed from number layer
[ALPHA_FROM_NUMBE_LYR] = LAYOUT_split_3x5_2(
KC_K,   KC_C,     KC_H,    KC_B,    KC_X,    KC_Z,    KC_Y,    KC_W,    KC_P,    KC_V,
KC_A,   KC_S,     KC_R,    KC_T,    _______, _______, KC_E,    KC_I,    KC_O,    KC_N,
KC_J,   KC_F,     KC_L,    KC_D,    _______, _______, KC_U,    KC_M,    KC_G,    KC_Q,
                           _______, KC_SPC,  _______, _______),
// alpha-from-mouse layer
// - alpha layer momentarily accessed from mouse layer
[ALPHA_FROM_MOUSE_LYR] = LAYOUT_split_3x5_2(
KC_K,   KC_C,     KC_H,    KC_B,    KC_X,    KC_Z,    KC_Y,    KC_W,    KC_P,     KC_V,
KC_A,   KC_S,     KC_R,    KC_T,    _______, _______, KC_E,    KC_I,    KC_O,     KC_N,
KC_J,   KC_F,     KC_L,    KC_D,    _______, _______, KC_U,    KC_M,    KC_G,     KC_Q,
                           _______, _______, HOLD_NUMBE_TAP_SPACE,      KC_DEL),
// number-from-other layer
// - number layer momentarily accessed from alpha layer or alpha-from-mouse layer
[NUMBE_FROM_OTHER_LYR] = LAYOUT_split_3x5_2(
KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
KC_GRV,  KC_BSLS, KC_SLSH, KC_MINS, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
KC_INS,  KC_LBRC, KC_RBRC, KC_EQL,  _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                           _______, KC_SPC,  _______, _______),
// mouse-from-other layer
// - mouse layer momentarily accessed from alpha layer or number layer
[MOUSE_FROM_OTHER_LYR] = LAYOUT_split_3x5_2(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
KC_BTN6, KC_BTN5, KC_BTN4, KC_BTN3, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
KC_F11,  KC_F12,  KC_F13,  KC_PSCR, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                           _______, _______, KC_BTN1, KC_BTN2),
};

// HOLD_MOUSE_TAP_SPACE will go to mouse layer before TAPPING_TERM elapses
// if another key is pressed then released
bool get_permissive_hold(uint16_t keycode,
                         keyrecord_t* record)
{
    switch (keycode)
    {
        case HOLD_MOUSE_TAP_SPACE:
            return true;
        default:
            return false;
    }
}

// HOLD_NUMBE_TAP_SPACE will go to number layer before TAPPING_TERM
// elapses if another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode,
                                 keyrecord_t* record)
{
    switch (keycode)
    {
        case HOLD_NUMBE_TAP_SPACE:
            return true;
        default:
            return false;
    }
}
