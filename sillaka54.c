// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _SYM,
    _GAME,
};

#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_SCLN RCTL_T(KC_SCLN)

#define LANG    LSFT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * BASE
     *
     * Esc   1   2   3   4   5            6   7   8   9   0   Del
     * Tab   Q   W   E   R   T            Y   U   I   O   P   [
     * Caps  A   S   D   F   G            H   J   K   L   ;   '
     * Game  Z   X   C   V   B            N   M   ,   .   /   ]
     *
     *             NAV Sft/Spc Lang    SYM Bspc Enter
     */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CW_TOGG,   HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,KC_QUOT,
        TG(_GAME), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                             MO(_NAV), KC_SPC, MO(_SYM),       MO(_NAV), KC_BSPC, LANG
    ),

    /*
     * NAV
     *
     * 필요한 것만 배치.
     * 왼손 홈로우 = modifiers
     * 오른손 홈로우 = arrows
     */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_ESC,                          _______, _______, KC_UP, _______, _______, KC_DEL,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                         _______, KC_LEFT, KC_DOWN, KC_RGHT,   _______, _______,
        _______, _______, _______, _______, _______, KC_TAB,                          _______, _______, _______, _______, _______, _______,
                                             _______, _______, _______,      _______, _______, _______
    ),

    /*
     * SYM
     *
     * 원칙:
     *   오른손 = unshifted
     *   왼손   = 오른손 키의 shifted 결과를 mirror
     *
     * 오른손 숫자는 numpad:
     *
     *          7 8 9
     *          4 5 6
     *          1 2 3
     *            0
     *
     * 왼손 대응:
     *
     *          & * (
     *          $ % ^
     *          ! @ #
     *            )
     */
    [_SYM] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
    KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_UNDS, KC_EQL,                        KC_LT,   KC_7,    KC_8,    KC_9,    KC_GT,   KC_MINS,
    KC_BSLS, KC_PIPE, KC_GRV,  KC_SCLN, KC_DQUO, KC_SLSH,                       KC_QUOT, KC_4,    KC_5,    KC_6,    KC_COLN, KC_BSLS,
    _______, _______, _______, _______, _______, _______,                        KC_0,    KC_1,    KC_2,    KC_3,    KC_QUES, _______,
                                         _______, _______, _______,     _______, _______, _______
),

    /*
     * GAME
     *
     * Home-row mods 제거.
     * 일반 QWERTY keycode 그대로.
     * 왼쪽 외곽에 Ctrl / Shift 직접 제공.
     *
     * GAME 키를 다시 누르면 BASE로 복귀.
     */
    [_GAME] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        TG(_GAME), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                             KC_LALT, KC_SPC, KC_LSFT,      MO(_SYM), KC_BSPC, KC_ENT
    ),
};
