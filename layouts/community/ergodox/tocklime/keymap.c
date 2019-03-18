#include QMK_KEYBOARD_H
#include "led.h"
#include "mousekey.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE   0 // default layer
#define NUMP 1
#define MDIA 2
#define CLMK 3
#define SYST 4

#define MUL   20 // mouse up left
#define MUR   21 // mouse up right
#define MDL   22 // mouse down left
#define MDR   23 // mouse down right

#define TRNS KC_TRANSPARENT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
//Left
 KC_GRAVE          ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,TRNS
,KC_TAB            ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LBRACKET
,LCTL_T(KC_ESCAPE) ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G
,KC_LSHIFT         ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NONUS_BSLASH
,KC_LGUI           ,KC_LALT ,TT(MDIA),TT(NUMP),KC_SPACE
		,KC_HOME,KC_END
		        ,KC_PGUP
      ,KC_BSPACE,KC_DELETE,KC_PGDOWN
//Right	 
    ,KC_MINUS,KC_6    ,KC_7     ,KC_8          ,KC_9   ,KC_0           ,KC_EQUAL
    ,KC_RBRC ,KC_Y    ,KC_U     ,KC_I          ,KC_O   ,KC_P           ,KC_NUHS
             ,KC_H    ,KC_J     ,KC_K          ,KC_L   ,LT(MDIA,KC_SCOLON),LGUI_T(KC_QUOTE)
    ,KC_SLASH,KC_N    ,KC_M     ,KC_COMM       ,KC_DOT ,KC_UP          ,KC_RSHIFT
                      ,KC_DELETE,KC_APPLICATION,KC_LEFT,KC_DOWN        ,KC_RIGHT
		         ,TRNS  ,TG(CLMK)
			 ,MO(NUMP)
			 ,KC_INSERT,KC_ENTER,KC_SPACE
),

[NUMP] = LAYOUT_ergodox(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,TRNS,TG(SYST),KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_AUDIO_VOL_UP,TRNS,KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,TRNS,KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,KC_AUDIO_VOL_DOWN,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_NUMLOCK,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,TRNS,TRNS,TRNS,KC_7,KC_8,KC_9,KC_KP_PLUS,TG(SYST),TRNS,KC_4,KC_5,KC_6,TRNS,TRNS,TRNS,TRNS,KC_1,KC_2,KC_3,KC_KP_ENTER,TRNS,TRNS,KC_DOT,KC_0,TRNS,TRNS,TO(BASE),TRNS,TRNS,TRNS,TRNS,TRNS),

[MDIA] = LAYOUT_ergodox(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_MS_UP,TRNS,TRNS,TRNS,TRNS,TRNS,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_MS_BTN1,KC_MS_BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_MEDIA_PLAY_PAUSE,TRNS,TRNS,TRNS,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,TRNS,TRNS,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,TRNS,TRNS,TO(BASE),TRNS,TRNS,TRNS,TRNS,TRNS),

[CLMK] = LAYOUT_ergodox(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_F,KC_P,KC_G,TRNS,TRNS,TRNS,KC_R,KC_S,KC_T,KC_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,TRNS,TRNS,KC_N,KC_E,KC_I,KC_O,TRNS,TRNS,KC_K,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TO(BASE),TRNS,TRNS,TRNS,TRNS,TRNS),

[SYST] = LAYOUT_ergodox(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,RGB_TOG,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,RGB_VAI,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,RESET,TRNS,TRNS,TRNS,TRNS,TRNS,RGB_VAD,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_ASTG,KC_ASRP,TRNS,TRNS,TRNS,TRNS,TRNS,KC_ASUP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KC_ASDN,TRNS,TRNS,TRNS,TRNS,TRNS,RESET,TRNS,TRNS,TRNS,TRNS,TRNS,TO(BASE),TRNS,TRNS,TRNS,TRNS,TRNS)

};

const uint16_t PROGMEM fn_actions[] = {
};

uint16_t symb_shift = 0;
uint16_t mdia_shift = 0;
uint16_t spec_shift = 0;

bool mdia_lock = false;
bool symb_lock = false;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        // mouse diagonals
        case MUL: // mouse up left
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MUR: // mouse up right
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        case MDL: // mouse down left
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MDR: // mouse down right
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        default:
            // none
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    autoshift_disable();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // shift or caps lock turns on red light
    if((keyboard_report->mods & MOD_BIT(KC_LSFT))
    || (keyboard_report->mods & MOD_BIT(KC_RSFT))
    || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // Numpad layer turns on green light
    if(layer_state & (1UL<<NUMP)) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    // Media layer turns on blue light
    if(layer_state & (1UL<<MDIA)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};
