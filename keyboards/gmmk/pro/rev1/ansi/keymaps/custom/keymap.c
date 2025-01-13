/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "rgb_matrix_map.h"
#include QMK_KEYBOARD_H


enum Layer {
    DEFAULT = 0,
    MAC_OS = 1,
    FUNC = 2,
    NUM_PAD = 3
} Layer;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    
    [DEFAULT] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,          KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        MO(3) ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_OS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_LALT, KC_LGUI,                            _______,                            KC_RGUI, _______, _______, _______, _______, _______
    ),


    [FUNC] = LAYOUT(
        _______, _______, _______, KC_VOLD, KC_VOLU, KC_CALC, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______, _______, GUI_TOG, TG(1)	,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        KC_CAPS, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
    [NUM_PAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS,  KC_NUM, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            KC_KP_0, KC_PENT, _______, _______, _______, _______
    ),



};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(KC_F18);
    } else {
      tap_code16(KC_F19);
    }
    return false;
}
#endif // ENCODER_ENABLE

// RGB LED layout

// led number, function of the key

//  67, Side 01    0, ESC      6, F1      12, F2     18, F3    23, F4    28, F5      34, F6    39, F7   44, F8       50, F9     56, F10    61, F11    66, F12    69, Prt       Rotary(Mute)   68, Side 12
//  70, Side 02    1, ~        7, 1       13, 2      19, 3     24, 4     29, 5       35, 6     40, 7    45, 8        51, 9      57, 0      62, -_     78, (=+)   85, BackSpc   72, Del        71, Side 13
//  73, Side 03    2, Tab      8, Q       14, W      20. E     25, R     30, T       36, Y     41, U    46, I        52, O      58, P      63, [{     89, ]}     93, \|        75, PgUp       74, Side 14
//  76, Side 04    3, Caps     9, A       15, S      21, D     26, F     31, G       37, H     42, J    47, K        53, L      59, ;:     64, '"                96, Enter     86, PgDn       77, Side 15
//  80, Side 05    4, Sh_L     10, Z      16, X      22, C     27, V     32, B       38, N     43, M    48, ,<       54, .<     60, /?                90, Sh_R   94, Up        82, End        81, Side 16
//  83, Side 06    5, Ct_L     11,Win_L   17, Alt_L                      33, SPACE                      49, Alt_R    55, FN                65, Ct_R   95, Left   97, Down      79, Right      84, Side 17
//  87, Side 07                                                                                                                                                                               88, Side 18
//  91, Side 08                                                                                                                                                                               92, Side 19

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {


    for (int i = 0; i < (sizeof(LED_MATRIX)/sizeof(LED_MATRIX[0])); ++i){
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_MATRIX[i], custom_purple.r, custom_purple.g, custom_purple.b);
    }

    for(int i = 0; i < (sizeof(LED_REGION_L_SIDE)/sizeof(LED_REGION_L_SIDE[0])); ++i){
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_L_SIDE[i], custom_orange.r, custom_orange.g, custom_orange.b);
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_R_SIDE[i], custom_orange.r, custom_orange.g, custom_orange.b);
    }


    if ((layer_state >> MAC_OS) & 1) {
        for(int i = 0; i < (sizeof(LED_REGION_L_SIDE)/sizeof(LED_REGION_L_SIDE[0])); ++i){
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_L_SIDE[i], custom_macos.r, custom_macos.g, custom_macos.b);
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_R_SIDE[i], custom_macos.r, custom_macos.g, custom_macos.b);
        }
    }

    switch(get_highest_layer(layer_state)){  // special handling per layer
        case NUM_PAD:
            if IS_HOST_LED_ON(USB_LED_NUM_LOCK){ 

                for (int i = 0; i < sizeof(LED_LAYER_NUMPAD_NUMS)/sizeof(LED_LAYER_NUMPAD_NUMS[0]); ++i){
                    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LAYER_NUMPAD_NUMS[i], custom_orange.r, custom_orange.g, custom_orange.b);
                }
    
                for (int i = 0; i < sizeof(LED_LAYER_NUMPAD_FNC)/sizeof(LED_LAYER_NUMPAD_FNC[0]); ++i){
                    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LAYER_NUMPAD_FNC[i].led, LED_LAYER_NUMPAD_FNC[i].r, 
                    LED_LAYER_NUMPAD_FNC[i].g, LED_LAYER_NUMPAD_FNC[i].b);
                }
            } else {

                RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LCK.led, NUM_LCK.r, NUM_LCK.g, NUM_LCK.b);
                
                for (int i = 0; i < sizeof(LED_LAYER_NUMPAD_NUMS)/sizeof(LED_LAYER_NUMPAD_NUMS[0]); ++i){
                    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LAYER_NUMPAD_NUMS[i], NUM_OFF.r, NUM_OFF.g, NUM_OFF.b);
                }
    
                for (int i = 0; i < sizeof(LED_LAYER_NUMPAD_FNC)/sizeof(LED_LAYER_NUMPAD_FNC[0]); ++i){
                    RGB_MATRIX_INDICATOR_SET_COLOR(LED_LAYER_NUMPAD_FNC[i].led, NUM_OFF.r, NUM_OFF.g, NUM_OFF.b);
                }
            }


        default:
            break;
    }

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for(int i = 0; i < (sizeof(LED_REGION_L_SIDE)/sizeof(LED_REGION_L_SIDE[0])); ++i){
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_L_SIDE[i], custom_capslock.r, custom_capslock.g, custom_capslock.b);
            RGB_MATRIX_INDICATOR_SET_COLOR(LED_REGION_R_SIDE[i], custom_capslock.r, custom_capslock.g, custom_capslock.b);
        }
    }
}