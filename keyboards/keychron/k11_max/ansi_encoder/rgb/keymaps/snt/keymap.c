/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"



enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
    MAC_VIM,
    WIN_VIM,
    COMPAT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,	    KC_2,/**/KC_3,    KC_4,    KC_5,	KC_6,	  /******/ KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC, /******/ KC_MUTE,
        KC_TAB,  KC_Q,/**/	KC_W,	 KC_E,	  KC_R,    KC_T,	/******/  KC_Y,	   KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS, /******/ KC_DEL,
        KC_LCTL, KC_A,/**/	KC_S,	 KC_D,	  KC_F,    KC_G,    /******/  KC_H,    KC_J,	KC_K,	KC_L,	 LT(MAC_VIM,KC_SCLN),
        /**/                                                                                                           KC_QUOT,             KC_ENT,  /******/ KC_HOME,
        KC_LSFT, KC_Z,/**/  KC_X,    KC_C,    KC_V,	   KC_B,/**/KC_B,     KC_N,	   KC_M, KC_COMM, KC_DOT,/**/KC_SLSH,  KC_RSFT, /**/         KC_UP,  /******/
        KC_ESC, KC_LOPTN, MT(MOD_LGUI,KC_LANGUAGE_2),
                                     /******/ KC_SPC, /******/ MT(MAC_FN1,KC_SPC),LT(FN2,KC_LANGUAGE_1),/******/ KC_SPC,  /******/ MT(KC_RGUI,KC_LANGUAGE_1),
                                                                                                                         /******/  KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_GRV,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC, /******/ KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS, /******/ KC_DEL,
        MO(COMPAT),KC_A,   KC_S,	 KC_D,	  KC_F,    KC_G,    /******/  KC_H,    KC_J,	KC_K,	 KC_L,	   LT(WIN_VIM,KC_SCLN),
                                                                                                                         KC_QUOT,  KC_ENT,  /******/ KC_HOME,
        KC_LSFT, /******/  KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_SLSH,  KC_RSFT, KC_UP,   /******/
        KC_ESC , KC_LALT,  MT(MOD_LCTL,KC_LANGUAGE_2),
                                     /******/ KC_SPC,  /******/ MO(WIN_FN1),LT(FN2,KC_LANGUAGE_1), /******/ KC_SPC,/******/   MT(MOD_RCTL,KC_LANGUAGE_1), /******/  KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        _______, KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD,RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______, /******/ RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, /******/ KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, /******/  _______, _______, _______, _______,  _______,  _______,  _______, /******/ KC_END,
        _______, /******/  RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP, /******/
        _______, _______,  _______,  /******/ _______, /******/ _______,  _______, /******/ _______, /******/  _______,  /******/  _______, KC_PGDN, _______),

    [WIN_FN1] = LAYOUT_69_ansi(
        _______, KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______, /******/ RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,	 _______,  _______, /******/ KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, /******/  _______, _______, _______, _______,  _______,  _______,  _______, /******/ KC_END,
        _______, /******/  RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP, /******/
        _______, _______,  _______,  /******/ _______, /******/ _______,  _______, /******/ _______, /******/  _______,  /******/  _______, KC_PGDN, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	    KC_F7,   KC_F8,	  KC_F9,  KC_F10,   KC_F11,	 KC_F12,   _______, /******/ _______,
        _______, _______,  _______,  _______, _______, _______, KC_EQUAL,    KC_7,    KC_8,    KC_9, _______,  _______,  _______,  _______, /******/ _______,
        _______, KC_LABK,  KC_LPRN,  KC_RPRN, KC_RABK, KC_PIPE, /******/ KC_MINUS,    KC_4,    KC_5,    KC_6,  KC_MINS,  _______,  _______, /******/ _______,
        _______, /******/ KC_MINUS,  KC_LCBR, KC_RCBR, KC_PLUS, _______,  _______,  KC_ASTR,   KC_1,    KC_2,     KC_3,  KC_SLSH,  KC_COMM, _______, /******/
        _______, _______,  KC_LBRC,  /******/ KC_RBRC, /******/ _______,  _______,  /******/   KC_0, /******/   KC_DOT,  /******/  _______, _______, _______),

    [MAC_VIM] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  QK_BOOT, /******/ _______,
        _______, _______,  KC_MS_WH_LEFT,
                                    KC_MS_UP,KC_MS_WH_RIGHT,
                                                       _______, _______, KC_PGDN,KC_PAGE_UP,_______, _______,  _______,  _______,  _______, /******/ _______,
        _______,KC_MS_WH_UP,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,
                                                       _______, /******/  KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  _______,  _______,  _______, /******/ _______,
        _______, /******/KC_MS_WH_DOWN,
                                     _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______, /******/
        _______, _______,KC_MS_BTN2,/******/KC_MS_BTN1,/******/ _______,RCMD(KC_LEFT), /******/
                                                                                      RCMD(KC_RIGHT), /******/  _______,  /******/  _______, _______, KC_SYSTEM_SLEEP),


    [WIN_VIM] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  QK_BOOT, /******/ _______,
        _______, _______,  KC_MS_WH_LEFT,
                                    KC_MS_UP,KC_MS_WH_RIGHT,
                                                       _______, _______, KC_PGDN,KC_PAGE_UP,_______, _______,  _______,  _______,  _______, /******/ _______,
        _______,KC_MS_WH_UP,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,
                                                       _______, /******/  KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  _______,  _______,  _______, /******/ _______,
        _______, /******/KC_MS_WH_DOWN,
                                     _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______, /******/
        _______, _______,KC_MS_BTN2,/******/KC_MS_BTN1,/******/ _______,RALT(KC_RIGHT), /******/
                                                                                      RALT(KC_LEFT), /******/  _______,  /******/  _______, _______, KC_SYSTEM_SLEEP),


    [COMPAT] = LAYOUT_69_ansi(
        LCTL(KC_GRAVE), LCTL(KC_1),  LCTL(KC_2),  LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6),  LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0),  _______,  _______,  _______, /******/ _______,
          LCTL(KC_TAB), LCTL(KC_Q),  LCTL(KC_W),      KC_END, LCTL(KC_R), LCTL(KC_T), LCTL(KC_Y),  LCTL(KC_U), LCTL(KC_I), LCTL(KC_O),      KC_UP,  _______,  _______,  _______, /******/ _______,
               _______,    KC_HOME,  LCTL(KC_S),   KC_DELETE,   KC_RIGHT, LCTL(KC_G),    /******/     KC_BSPC,   KC_ENTER, LCTL(KC_K), LCTL(KC_L),  _______,  _______,  _______, /******/ _______,
               _______,    /******/  LCTL(KC_Z),  LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),    KC_LEFT,     KC_LEFT,    KC_DOWN,   KC_ENTER,    _______,  _______,  _______,  _______, _______, /******/
               _______,    _______,     KC_LWIN,     /******/    _______,    /******/    _______,     _______,    /******/    _______,    /******/  _______,  /******/  _______, _______, _______),

    // [WIN_VIM] = LAYOUT_69_ansi(
    //     _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, _______,  _______,  _______, _______, _______, /******/  _______, _______, _______, _______,  _______,  _______,  _______, /******/ _______,
    //     _______, /******/  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______, /******/
    //     _______, _______,  _______,  /******/ _______, /******/ _______,  _______, /******/ _______, /******/  _______,  /******/  _______, _______, _______,
    // )
};

#if defined(ENCODER_MAP_ENABLE)
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[FN2]	   = {ENCODER_CCW_CW(_______, _______)},
		[MAC_VIM]  = {ENCODER_CCW_CW(_______, _______)},
		[WIN_VIM]  = {ENCODER_CCW_CW(_______, _______)},
		[COMPAT]   = {ENCODER_CCW_CW(_______, _______)},
	};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// RGB

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}
#define CCCC {0,0}
#define C_NONEX {0,0,0}
#define C_LETTR {13,248,179}
#define C_LAYER {180,255,127}
#define C_MODIF {76,255,127}
#define C_SPCHL {90,255,235}
#define C_CTCHL {43,255,132}
#define C_CURSR {31,255,132}
#define C_ENTER {187,255,132}
#define C_TENKY {0,0,255}
#define C_OPERA {0,217,112}
#define C_BRAKT {218,128,128}
#define C_BLUTH {}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [MAC_BASE] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },

    [WIN_BASE] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },

    [MAC_FN1] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },

    [WIN_FN1] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },

    [FN2] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, /******/ C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_TENKY, C_TENKY, C_TENKY, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_SPCHL, C_BRAKT, C_BRAKT, C_SPCHL, C_SPCHL, C_SPCHL, C_OPERA, C_TENKY, C_TENKY, C_TENKY, C_OPERA, C_ENTER, C_CTCHL,
        C_MODIF, C_OPERA, C_BRAKT, C_BRAKT, C_OPERA, C_LETTR, C_OPERA, C_OPERA, C_TENKY, C_TENKY, C_TENKY, C_OPERA, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_BRAKT, C_BRAKT, C_LAYER, C_LAYER, C_TENKY, C_TENKY, C_CURSR, C_CURSR, C_CURSR
    },

    [MAC_VIM] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
         },

    [WIN_VIM] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },

    [COMPAT] = {
        C_SPCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR,
        C_CTCHL, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_CTCHL,
        C_LAYER, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LAYER, C_SPCHL, C_ENTER, C_CTCHL,
        C_MODIF, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_LETTR, C_SPCHL, C_SPCHL, C_SPCHL, C_MODIF, C_CURSR,
        C_CTCHL, C_MODIF, C_MODIF, C_SPCHL, C_LAYER, C_LAYER, C_SPCHL, C_MODIF, C_CURSR, C_CURSR, C_CURSR
    },
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case MAC_BASE:
            set_layer_color(MAC_BASE);
            break;
        case WIN_BASE:
            set_layer_color(WIN_BASE);
            break;
        case MAC_FN1:
            set_layer_color(MAC_FN1);
            break;
        case WIN_FN1:
            set_layer_color(WIN_FN1);
            break;
        case FN2:
            set_layer_color(FN2);
            break;
        case WIN_VIM:
            set_layer_color(WIN_VIM);
            break;
        case MAC_VIM:
            set_layer_color(MAC_VIM);
            break;
        case COMPAT:
            set_layer_color(COMPAT);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}