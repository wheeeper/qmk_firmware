/* Copyright 2021 Cedrik Lussier @cedrikl
.* Directly inspired from the work of jonavin https://github.com/qmk/qmk_firmware/tree/master/keyboards/gmmk/pro/ansi/keymaps/jonavin
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

#pragma once
#include "color.h"

#ifdef RGB_MATRIX_ENABLE

    // Custom RGB Colours
    const RGB custom_orange = {255, 102 , 0};
    const RGB custom_capslock = {255, 0, 0};
    const RGB custom_purple = {194, 31, 234};
    
    const RGB custom_macos = custom_purple;
    const RGB numpad_inactive = {255, 0, 0};

    // RGB LED locations
    enum led_location_map {
        LED_ESC, // 0, ESC, k13
        LED_GRV, // 1, ~, k16
        LED_TAB, // 2, Tab, k11
        LED_CAPS, // 3, Caps, k21
        LED_LSFT, // 4, Sh_L, k00
        LED_LCTL, // 5, Ct_L, k06
        LED_F1, // 6, F1, k26
        LED_1, // 7, 1, k17
        LED_Q, // 8, Q, k10
        LED_A, // 9, A, k12
        LED_Z, // 10, Z, k14
        LED_LWIN, // 11, Win_L, k90
        LED_F2, // 12, F2, k36
        LED_2, // 13, 2, k27
        LED_W, // 14, W, k20
        LED_S, // 15, S, k22
        LED_X, // 16, X, k24
        LED_LALT, // 17, Alt_L, k93
        LED_F3, // 18, F3, k31
        LED_3, // 19, 3, k37
        LED_E, // 20, E, k30
        LED_D, // 21, D, k32
        LED_C, // 22, C, k34
        LED_F4, // 23, F4, k33
        LED_4, // 24, 4, k47
        LED_R, // 25, R, k40
        LED_F, // 26, F, k42
        LED_V, // 27, V, k44
        LED_F5, // 28, F5, k07
        LED_5, // 29, 5, k46
        LED_T, // 30, T, k41
        LED_G, // 31, G, k43
        LED_B, // 32, B, k45
        LED_SPC, // 33, SPACE, k94
        LED_F6, // 34, F6, k63
        LED_6, // 35, 6, k56
        LED_Y, // 36, Y, k51
        LED_H, // 37, H, k53
        LED_N, // 38, N, k55
        LED_F7, // 39, F7, k71
        LED_7, // 40, 7, k57
        LED_U, // 41, U, k50
        LED_J, // 42, J, k52
        LED_M, // 43, M, k54
        LED_F8, // 44, F8, k76
        LED_8, // 45, 8, k67
        LED_I, // 46, I, k60
        LED_K, // 47, K, k62
        LED_COMM, // 48, ,, k64
        LED_RALT, // 49, Alt_R, k95
        LED_F9, // 50, F9, ka6
        LED_9, // 51, 9, k77
        LED_O, // 52, O, k70
        LED_L, // 53, L, k72
        LED_DOT, // 54, ., k74
        LED_FN, // 55, FN, k92
        LED_F10, // 56, F10, ka7
        LED_0, // 57, 0, k87
        LED_P, // 58, P, k80
        LED_SCLN, // 59, ;, k82
        LED_SLSH, // 60, ?, k85
        LED_F11, // 61, F11, ka3
        LED_MINS, // 62, -, k86
        LED_LBRC, // 63, [, k81
        LED_QUOT, // 64, ", k83
        LED_RCTL, // 65, Ct_R, k04
        LED_F12, // 66, F12, ka5
        LED_L1, // 67, LED, l01
        LED_R1, // 68, LED, l11
        LED_DEL, // 69, Prt, k97  -- remapped to DEL
        LED_L2, // 70, LED, l02
        LED_R2, // 71, LED, l12
        LED_HOME, // 72, Del, k65
        LED_L3, // 73, LED, l03
        LED_R3, // 74, LED, l13
        LED_PGUP, // 75, PgUp, k15
        LED_L4, // 76, LED, l04
        LED_R4, // 77, LED, l14
        LED_EQL, // 78, =, k66
        LED_RGHT, // 79, Right, k05
        LED_L5, // 80, LED, l05
        LED_R5, // 81, LED, l15
        LED_END, // 82, End, k75
        LED_L6, // 83, LED, l06
        LED_R6, // 84, LED, l16
        LED_BSPC, // 85, BSpc, ka1
        LED_PGDN, // 86, PgDn, k25
        LED_L7, // 87, LED, l07
        LED_R7, // 88, LED, l17
        LED_RBRC, // 89, ], k61
        LED_RSFT, // 90, Sh_R, k91
        LED_L8, // 91, LED, l08
        LED_R8, // 92, LED, l18
        LED_BSLS, // 93, \, ka2
        LED_UP, // 94, Up, k35
        LED_LEFT, // 95, Left, k03
        LED_ENT, // 96, Enter, ka4
        LED_DOWN // 97, Down, k73
    };

    typedef struct LedConf {
        const uint8_t led;
        const uint8_t r;
        const uint8_t g;
        const uint8_t b;
    } CUSTOM_LED_CONF;

const uint8_t LED_REGION_L_SIDE[] = {LED_L1, LED_L2, LED_L3, LED_L4, LED_L5, LED_L6, LED_L7,LED_L8};
const uint8_t LED_REGION_R_SIDE[] = {LED_R1, LED_R2, LED_R3, LED_R4, LED_R5, LED_R6, LED_R7,LED_R8};

    const uint8_t LED_MATRIX[] = {
        LED_ESC,  LED_F1,   LED_F2,   LED_F3,   LED_F4,   LED_F5,   LED_F6,   LED_F7,   LED_F8,   LED_F9,   LED_F10,  LED_F11,  LED_F12,  LED_DEL,
        LED_GRV,  LED_1,    LED_2,    LED_3,    LED_4,    LED_5,    LED_6,    LED_7,    LED_8,    LED_9,    LED_0,    LED_MINS, LED_EQL,  LED_BSPC,           LED_HOME,
        LED_TAB,  LED_Q,    LED_W,    LED_E,    LED_R,    LED_T,    LED_Y,    LED_U,    LED_I,    LED_O,    LED_P,    LED_LBRC, LED_RBRC, LED_BSLS,           LED_PGUP,
        LED_CAPS, LED_A,    LED_S,    LED_D,    LED_F,    LED_G,    LED_H,    LED_J,    LED_K,    LED_L,    LED_SCLN, LED_QUOT,           LED_ENT,            LED_PGDN,
        LED_LSFT,           LED_Z,    LED_X,    LED_C,    LED_V,    LED_B,    LED_N,    LED_M,    LED_COMM, LED_DOT,  LED_SLSH,           LED_RSFT, LED_UP,   LED_END,
        LED_LCTL, LED_LWIN, LED_LALT,                            LED_SPC,                                   LED_RALT, LED_FN,   LED_RCTL, LED_LEFT, LED_DOWN, LED_RGHT
    };


    const CUSTOM_LED_CONF LED_LAYER_NUMPAD_FNC[] = {
            {LED_7, 255, 255, 0},  // Yellow
            {LED_8, 0, 0, 255},    // Blue
            {LED_9, 255, 0, 0},    // Red
            {LED_0, 0, 255, 0}    // Green
        };

    const CUSTOM_LED_CONF NUM_LCK = {LED_MINS, 0, 255, 0};
    const RGB NUM_OFF = {255, 35, 35};

    const uint8_t LED_LAYER_NUMPAD_NUMS[] = {
                                                                                                                                                                       
                                                                               
                                                                               LED_U,    LED_I,    LED_O,     
                                                                               LED_J,    LED_K,    LED_L,     
                                                                                         LED_M,    LED_COMM, LED_DOT,   
                                                                                                           LED_RALT, LED_FN,
    };

    const uint8_t LED_REGION_A[] = {
        LED_ESC,                                                                                  LED_F9,   LED_F10,  LED_F11,  LED_F12,  LED_DEL,
        LED_GRV,  LED_1,                                                                                    LED_0,    LED_MINS, LED_EQL,  LED_BSPC,           LED_HOME,
        LED_TAB,  LED_Q,                                                                                    LED_P,    LED_LBRC, LED_RBRC, LED_BSLS,           LED_PGUP,
        LED_CAPS, LED_A,                                                                                    LED_SCLN, LED_QUOT,           LED_ENT,            LED_PGDN,
        LED_LSFT,           LED_Z,                                                                                              LED_SLSH,           LED_RSFT, LED_UP,   LED_END,
        LED_LCTL, LED_LWIN, LED_LALT,                                                                                                     LED_RCTL, LED_LEFT, LED_DOWN, LED_RGHT
    };
    const uint8_t LED_REGION_B[] = {
                  LED_F1,   LED_F2,   LED_F3,   LED_F4,   LED_F5,   LED_F6,   LED_F7,   LED_F8,
                            LED_2,    LED_3,    LED_4,    LED_5,    LED_6,    LED_7,    LED_8,    LED_9,
                            LED_W,    LED_E,    LED_R,    LED_T,    LED_Y,    LED_U,    LED_I,    LED_O,
                            LED_S,    LED_D,    LED_F,    LED_G,    LED_H,    LED_J,    LED_K,    LED_L,
                                      LED_X,    LED_C,    LED_V,    LED_B,    LED_N,    LED_M,    LED_COMM, LED_DOT, 
                                                                 LED_SPC,                                   LED_RALT, LED_FN
    };

    const uint8_t LED_REGION_NUMPAD[] = {

        LED_GRV,  LED_1,    LED_2,    LED_3,    LED_4,    LED_5,    LED_6,    LED_7,    LED_8,    LED_9,    LED_0,    LED_MINS, LED_EQL,
                                                                                                                      LED_LBRC, LED_RBRC,
                                                                                                                                          LED_ENT,
                                                                                                            LED_DOT
  
    };

    const uint8_t LED_REGION_OTHER[] = {
        LED_ESC,                                                                                                                          LED_DEL,
                                                                                                                                                              LED_HOME,

                 LED_A,    LED_S,    LED_D,
                                                                                                                                                              LED_END,
                 LED_LWIN
    };

    const uint8_t LED_REGION_CAPS[] = {

        LED_GRV,  LED_1,
        LED_TAB,  LED_Q,
        LED_CAPS, LED_A,
        LED_LSFT,
        LED_LCTL
    };

#endif
