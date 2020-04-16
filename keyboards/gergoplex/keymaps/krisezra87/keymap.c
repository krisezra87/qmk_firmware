/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define CMOD 1 // custom mods
#define NUMB 2 // numbers and symbols
#define PAD 3  // Pad/motion

// Combos
enum combos {
  QW,UI,OP,
  AS,JK,KL,LSCLN,
  DQ,
  OT,NZ,
  VV,LR
};

// NOTE: If you're using MT,LT or anything you must
// define it here. Note this if you change your layout!

/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |    TAB    |     |     |      |      |     |     |    MINS  BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |    ESC    |     |     |      |      |     |    LESS  GRT    |        |
 * |-----+-----+-----+-RMB-+-LMB--|      |--------------------------------|
 * |     |     |     |     |      |      |     |     |     |     |        |
 * `-----+-----+-----+-----+------'      `--------------------------------'
 *             .------------------.      .-----------------.
 *             |     |     |      |      |     |     |     |
 *             '------------------'      '-----------------'
 */
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM dq_combo[] = {KC_DLR, KC_QUOT, COMBO_END};

const uint16_t PROGMEM ot_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM nz_combo[] = {KC_9, KC_0, COMBO_END};

const uint16_t PROGMEM vv_combo[] = {KC_VOLU, KC_VOLD, COMBO_END};
const uint16_t PROGMEM lr_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

/* enum custom_keycodes { */
    /* ALT_ONE=SAFE_RANGE, */
/* }; */

combo_t key_combos[COMBO_COUNT] = {
  // Horizontal Chords
  [QW] = COMBO(qw_combo, KC_TAB),
  [UI] = COMBO(ui_combo, KC_MINS),
  [OP] = COMBO(op_combo, KC_BSLS),

  [AS] = COMBO(as_combo, KC_ESC),
  [JK] = COMBO(jk_combo, KC_LT),
  [KL] = COMBO(kl_combo, KC_GT),
  [LSCLN] = COMBO(lscln_combo, KC_QUOT),

  // CMOD
  [DQ] = COMBO(dq_combo, KC_PIPE),

  // NUM
  [OT] = COMBO(ot_combo, KC_TILD),
  [NZ] = COMBO(nz_combo, KC_EQL),

  // Pad
  [VV] = COMBO(vv_combo, KC_MUTE),
  [LR] = COMBO(lr_combo, KC_BTN3),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case ALT_ONE: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING(SS_LALT("1")); */
        /*     } */
        /*     break; */

    }
    return true;
};

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |   Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |    A |  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+-----+-----'      `--------------------------------'
 *       .------------------------.      .-----------------------.
 *       | LALT|DEL/LCTL|BSPC(SYM)|      | SPC(NUM)|ENT(PAD)|RCTL|
 *       '------------------------'      '-----------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_E, KC_R, KC_T,  	              KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

   	KC_LALT, MT(MOD_LCTL,KC_DEL),  LT(CMOD,KC_BSPC), // Left
  	LT(NUMB, KC_SPC), LT(PAD, KC_ENT), KC_RCTL  // Right
    ),

/* Keymap 1: MOD Layer
 * ,-----------------------------.       ,----------------------------------.
 * | ALT1 | ALT2| ALT3| ALT4| ALT5|      | ALT6| ALT7 | ALT8 | ALT9| ALT0   |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * |  `   |     | CTLD|     |     |      | ALTH| ALTJ | ALTK | ALTL|    '   |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * | SHIFT|     | CTLC| CTLV|     |      |     |      | ALT, |     | SHIFT  |
 * `------+-----+-----+-----+-----'      `----------------------------------'
 *              .-----------------.      .-------------------.
 *              |     |     |     |      |  ~  |      |      |
 *              '-----------------'      '-------------------'
 */

[CMOD] = LAYOUT_gergoplex(
    LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),  LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0),
    KC_GRV,     KC_TRNS,    LCTL(KC_D), KC_TRNS,    KC_TRNS,     LALT(KC_H), LALT(KC_J), LALT(KC_K),    LALT(KC_L), KC_QUOT,
    KC_LSFT,    KC_TRNS,    LCTL(KC_C), LCTL(KC_V), KC_TRNS,     KC_TRNS,    KC_TRNS,    LALT(KC_COMM), KC_TRNS,    KC_RSFT,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,     LALT(LSFT(KC_ENT)), LALT(LSFT(KC_Q)), KC_TRNS
    ),

/* Keymap 2: Num/Sym Layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   ~  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  =   0   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  `   |  0  |  (  |  [  |  {  |      |  }  |  ]  |  )  |  $ PIPE '   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * | SHIFT|     |     |     |     |      |     |     |     |     | SHIFT |
 * `------+-----+-----+-----+-----'      `-------------------------------'
 *              .-----------------.      .-----------------.
 *              |     |    |  =   |      |     |     |     |
 *              '-----------------'      '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	   KC_6,  	KC_7, 	 KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_0,    KC_LPRN, KC_LBRC, KC_LCBR,   KC_RCBR, KC_RBRC, KC_RPRN, KC_DLR,  KC_QUOT,
    KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
       		          KC_TRNS, KC_TRNS, KC_EQL,    KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 3: Pad layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |      |     | SKP |VOLUP| LMB |      | LFT | DWN | UP  | RGT |       |
 * |------+-----+-----+MUTE-+-MMB-|      |-------------------------------|
 * | SHIFT|     | PLY |VOLDN| RMB |      |MLFT | MDWN| MUP | MRGT| SHIFT |
 * `------+-----+-----+-----+-----'      `-------------------------------'
 *              .-----------------.      .-----------------.
 *              |     |    |      |      |     |     |     |
 *              '-----------------'      '-----------------'
 */
[PAD] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	   KC_6,  	KC_7, 	 KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLU, KC_BTN2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_LSFT, KC_TRNS, KC_MPLY, KC_VOLD, KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RSFT,
                      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
    )
};
