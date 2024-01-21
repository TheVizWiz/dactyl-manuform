/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#pragma once

#define WS2812_DI_PIN D0
#define SPLIT_HAND_PIN F5
#define MASTER_LEFT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_LED_STATE_ENABLE
#define RGBLIGHT_SLEEP


#define RGB_DI_PIN D0
#define RGBLED_NUM 144
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 72, 72 }
#define RGBLIGHT_LIMIT_VAL 200
// #define MASTER_RIGHs

// #define EE_HANDS