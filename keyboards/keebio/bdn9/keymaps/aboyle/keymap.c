/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
  MMMMYES = SAFE_RANGE,
  OHYEAH, SAD_TROMBONE, THUMBSUP, YEY, HEAVY_PLUS_SIGN, R_MMMMYES, R_OHYEAH, R_SAD_TROMBONE, R_THUMBSUP, R_YEY, R_HEAVY_PLUS_SIGN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        slack emojis, entered on their own line
     */
    [0] = LAYOUT(
        KC_MUTE, MMMMYES, KC_MPLY,
        MO(1)  , OHYEAH  , YEY,
        SAD_TROMBONE, THUMBSUP, HEAVY_PLUS_SIGN
    ),
    /*
        same emoji's as layer 0 but as reactions
     */
    [1] = LAYOUT(
        RESET  , R_MMMMYES, KC_STOP,
        _______, R_OHYEAH, R_YEY,
        R_SAD_TROMBONE, R_THUMBSUP, R_HEAVY_PLUS_SIGN
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MMMMYES:
      if (record->event.pressed) {
        SEND_STRING(":mmmmyes:\n");
        return false;
      }
    case R_MMMMYES:
      if (record->event.pressed) {
        SEND_STRING("+:mmmmyes:\n");
        return false;
      }
    case OHYEAH:
      if (record->event.pressed) {
        SEND_STRING(":ohyeah:\n");
        return false;
      }
    case R_OHYEAH:
      if (record->event.pressed) {
        SEND_STRING("+:ohyeah:\n");
        return false;
      }
    case SAD_TROMBONE:
      if (record->event.pressed) {
        SEND_STRING(":sad_trombone:\n");
        return false;
      }
    case R_SAD_TROMBONE:
      if (record->event.pressed) {
        SEND_STRING("+:sad_trombone:\n");
        return false;
      }
    case THUMBSUP:
      if (record->event.pressed) {
        SEND_STRING(":THUMBSUP:\n");
        return false;
      }
    case R_THUMBSUP:
      if (record->event.pressed) {
        SEND_STRING("+:THUMBSUP:\n");
        return false;
      }
    case YEY:
      if (record->event.pressed) {
        SEND_STRING(":YEY:\n");
        return false;
      }
    case R_YEY:
      if (record->event.pressed) {
        SEND_STRING("+:YEY:\n");
        return false;
      }
    case HEAVY_PLUS_SIGN:
      if (record->event.pressed) {
        SEND_STRING(":HEAVY_PLUS_SIGN:\n");
        return false;
      }
    case R_HEAVY_PLUS_SIGN:
      if (record->event.pressed) {
        SEND_STRING("+:HEAVY_PLUS_SIGN:\n");
        return false;
      }
  }

  return true;
}
