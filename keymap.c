#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "leader.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,
LSFT_T(KC_A),KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        RSFT_T(KC_SCLN),
LCTL_T(KC_Z),LALT_T(KC_X),LGUI_T(KC_C),KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,        RALT_T(KC_DOT),        RCTL_T(KC_SLSH),        LT(5,       KC_DEL),        LT(1,       KC_ESC),        LT(3,       KC_BSPC),        LT(4,       KC_SPC),        LT(2,       KC_ENT),        LT(6,       KC_NO)),
    [1] = LAYOUT_split_3x5_3(KC_EXLM,        KC_AT,        KC_HASH,        KC_DLR,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINS,        KC_EQL,        KC_TRNS,        KC_2,        KC_LPRN,        KC_RPRN,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TILD,        KC_LT,        KC_GT,        KC_UNDS,        KC_PPLS,        KC_NO,        KC_NO,        LGUI(KC_ESC),        KC_BSLS,        KC_PIPE,        KC_SLSH),
    [2] = LAYOUT_split_3x5_3(KC_EXLM,        KC_AT,        KC_HASH,        KC_DLR,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINS,        KC_EQL,        KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_LBRC,        KC_RBRC,        KC_9,        KC_TRNS,        KC_NO,        KC_NO,        KC_LCBR,        KC_RCBR,        KC_NO,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_GRV,        KC_QUOT,        KC_DQUO,        KC_NO,        KC_NO,        KC_NO),
    [3] = LAYOUT_split_3x5_3(KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ESC,        KC_TRNS,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,        KC_TAB,        KC_LEFT,        KC_DOWN,        KC_UP,        KC_RGHT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_END,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BSPC,        KC_SPC,        KC_NO,        KC_TRNS,        KC_TRNS),
    [4] = LAYOUT_split_3x5_3(KC_TRNS,        KC_TRNS,        KC_PSCR,        KC_ESC,        KC_INS,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        QK_LEAD,        KC_ENT,        KC_TAB,        KC_LEFT,        KC_DOWN,        KC_UP,        KC_RGHT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_END,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BSPC,        KC_SPC,        KC_NO,        KC_TRNS,        KC_TRNS),
    [5] = LAYOUT_split_3x5_3(KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_COPY,        KC_UNDO,        KC_CUT,        KC_TRNS,        KC_PSTE,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_L,        KC_MS_D,        KC_MS_U,        KC_MS_R,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_WH_D,        KC_WH_U,        KC_TRNS,        KC_TRNS,        KC_NO,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BTN1,        KC_BTN2),
    [6] = LAYOUT_split_3x5_3(QK_BOOT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F11,        KC_F12,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO)
};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}
