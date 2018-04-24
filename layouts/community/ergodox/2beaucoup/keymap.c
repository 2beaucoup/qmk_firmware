#include "ergodox_ez.h"

#define BASE 0
#define CODE 1
#define NAVI 2

enum custom_keycodes { EPRM = SAFE_RANGE, UML };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* clang-format off */
    [BASE] = KEYMAP(
        KC_PWR,       KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5, KC_TRNS,
        KC_SLEP,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,  KC_HOME,
        KC_WAKE,      SFT_T(KC_A), CTL_T(KC_S), ALT_T(KC_D), GUI_T(KC_F), KC_G,
        KC_EJCT,      KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,  KC_END,
        ALL_T(KC_NO), KC_TRNS,     KC_TRNS,     KC_TRNS,     LT(1, KC_DELETE),

        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MS_WH_UP, KC_SPC, KC_BSPC, KC_MS_WH_DOWN,

        KC_TRNS,       KC_F6, KC_F7,         KC_F8,        KC_F9,        KC_F10,          KC_F11,
        KC_PGUP,       KC_Y,  KC_U,          KC_I,         KC_O,         KC_P,            KC_F12,
                       KC_H,  GUI_T(KC_J),   RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOTE,
        KC_PGDN,       KC_N,  KC_M,          KC_COMM,      KC_DOT,       KC_SLASH,        KC_TRNS,
                              LT(2, KC_ESC), UML,          KC_TRNS,      KC_TRNS,         MEH_T(KC_NO),

        KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_TAB, KC_ENT),

    [CODE] = KEYMAP(
        KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC, KC_TRNS,
        KC_TRNS, SFT_T(KC_1), CTL_T(KC_2), ALT_T(KC_3), GUI_T(KC_4), KC_5,
        KC_TRNS, KC_UNDS,     KC_PLUS,     KC_MINS,     KC_EQL,      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS, KC_CIRC, KC_AMPR,      KC_ASTR,      KC_GRV,       KC_BSLASH,    KC_TRNS,
                 KC_6,    RGUI_T(KC_7), RALT_T(KC_8), RCTL_T(KC_9), RSFT_T(KC_0), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LPRN,      KC_RPRN,      KC_LBRC,      KC_RBRC,      KC_TRNS,
                          KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [NAVI] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_UP,   KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_BTN1, KC_MS_BTN2,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* clang-format on */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case UML:
        SEND_STRING(SS_LALT("u"));
        return false;
    }
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 0:
      break;
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
