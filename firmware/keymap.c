#include QMK_KEYBOARD_H

#define _BASE 0
#define _L1 1
#define _L2 2
#define _GAMING 3

#define MO_L1 MO(_L1)
#define MO_L2 MO(_L2)
#define TOG_GAM TG(_GAMING)


#define ORANGE 7

#define SHIFT_COLOR HSV_MAGENTA


enum custom_keycodes {

    S_CLR = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_PSCR,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_MINS,
        KC_GRV , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_RBRC,                                                       KC_MINS, KC_EQL,
                                            MO_L1  , KC_LCTL,                   KC_SPC , MO_L2  ,
                                            KC_LSFT, KC_LALT,                   KC_RSFT, KC_BSPC,
                                            KC_BSPC, KC_LGUI,                   KC_RCTL, KC_RALT
        ),

    [_L1] = LAYOUT_5x6(
          QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                 KC_BSLS, KC_SLSH, KC_PAST, KC_MINS, KC_PLUS , KC_F11  ,
          TOG_GAM, KC_INS , KC_HOME, KC_UP  , KC_END , KC_LBRC,                 KC_RBRC, KC_7   , KC_8   , KC_9   , KC_NUM  , KC_MUTE ,
          _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,                 KC_RPRN, KC_4   , KC_5   , KC_6   , KC_DOT  , KC_VOLU ,
          _______, _______, _______, KC_SPC , _______, _______,                 KC_GRV , KC_1   , KC_2   , KC_3   , KC_COMM , KC_VOLD ,
                            _______, RGB_TOG,                                                     _______, _______,
                                              _______, _______,                 KC_PENT, KC_0   ,
                                              _______, _______,                 _______, KC_DEL ,
                                              _______, _______,                 _______, _______
        ),

    [_L2] = LAYOUT_5x6(
        QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                 KC_F6  , KC_MPRV, KC_MPLY, KC_MNXT, KC_F10 , QK_BOOT,
        TOG_GAM, _______, _______, KC_UP  , _______, _______,                 KC_RBRC, KC_HOME, KC_UP  , KC_END , KC_SCRL, KC_MUTE,
        _______, KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT, _______,                 KC_RPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , KC_VOLU,
        _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, KC_VOLD,
                          _______, RGB_TOG,                                                     KC_EQL , _______,
                                            _______, _______,                 KC_TAB ,_______,
                                            _______, _______,                 _______,_______,  
                                            _______, _______,                 _______,_______
        ),


    [_GAMING] = LAYOUT_5x6(
            KC_ESC , KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   ,               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
            TOG_GAM, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,               KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
            KC_LSFT, KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,               KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
            KC_NUM , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,               KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
                              KC_LBRC, KC_RBRC,                                                   KC_PLUS, KC_EQL ,
                                                KC_SPC , KC_P1  ,               KC_ENT , MO_L2  ,
                                                KC_LALT, KC_P2  ,               KC_END , KC_DEL ,
                                                KC_P4  , KC_P3  ,               KC_LGUI, KC_LALT
        )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv_noeeprom(ORANGE, 255, 255);
            break;
        case _L1:
            rgblight_sethsv_noeeprom(SHIFT_COLOR);
            break;
        case _L2:
            rgblight_sethsv_noeeprom(SHIFT_COLOR);
            break;
        case _GAMING:
            rgblight_sethsv_noeeprom(HSV_TEAL);
            break;
    }
    return state;
}

