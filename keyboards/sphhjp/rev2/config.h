
#pragma once

/* key matrix size */
#define MATRIX_ROWS 10 
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS       { B0, B1, B2, B3, B4 }
#define MATRIX_COL_PINS       { B5, B6, C6, C7, D4, D5, D6, D7 }
#define MATRIX_ROW_PINS_RIGHT { B0, B1, B2, B3, B4 }
#define MATRIX_COL_PINS_RIGHT { B5, B6, C6, C7, D4, D5, D6, D7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Split Keyboard specific options */
#define SPLIT_HAND_PIN E6  /*fix pin. HIGH is left, LOW is right */
#define SOFT_SERIAL_PIN D3 /* serial communication pin */

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* To properly wake up from suspend, mainly for Mac. */
#define USB_SUSPEND_WAKEUP_DELAY 200
