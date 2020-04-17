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
  AS,LSCLN,
  OT,EN,NZ,BA,SLP,LPRP,
  VV,LR
};

// NOTE: If you're using MT,LT or anything you must
// define it here. Note this if you change your layout!

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM ot_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM en_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM nz_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM ba_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM slp_combo[] = {KC_ASTR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM lprp_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};

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
  [LSCLN] = COMBO(lscln_combo, KC_QUOT),

  // CMOD

  // NUM
  [OT] = COMBO(ot_combo, KC_GRV),
  [BA] = COMBO(ba_combo, KC_TILD),
  [EN] = COMBO(en_combo, KC_MINS),
  [NZ] = COMBO(nz_combo, KC_EQL),
  [SLP] = COMBO(slp_combo, KC_UNDS),
  [LPRP] = COMBO(lprp_combo, KC_PLUS),

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
 * ,------------------------------.      ,-----------------------------------.
 * |   Q TAB W  |  E  |  R  |  T  |      |  Y  |  U  |  I  -  O BSLSH P      |
 * |------+-----+-----+-----+-----|      |-----------------------------------|
 * |   A ESC S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/;    |
 * |------+-----+-----+-----+-----|      |-----------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | SHFT/SLSH |
 * `------+-----+-----+-----+-----'      `-----------------------------------'
 *       .------------------------.      .-----------------------.
 *       | LALT|DEL/LCTL|BSPC(SYM)|      | SPC(NUM)|ENT(PAD)|RCTL|
 *       '------------------------'      '-----------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

   	KC_LALT, MT(MOD_LCTL,KC_DEL),  LT(CMOD,KC_BSPC), // Left
  	LT(NUMB, KC_SPC), LT(PAD, KC_ENT), KC_RCTL  // Right
    ),

/* Keymap 1: MOD Layer
 * ,-----------------------------.       ,----------------------------------.
 * | ALT1 | ALT2| ALT3| ALT4| ALT5|      | ALT6| ALT7 | ALT8 | ALT9| ALT0   |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * |      |     | CTLD|     |     |      | ALTH| ALTJ | ALTK | ALTL|        |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * | SHIFT|     | CTLC| CTLV|     |      |     |      | ALT, |     | SHIFT  |
 * `------+-----+-----+-----+-----'      `----------------------------------'
 *              .-----------------.      .-------------------.
 *              |     |     |     |      |  ~  |      |      |
 *              '-----------------'      '-------------------'
 */

[CMOD] = LAYOUT_gergoplex(
    LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),  LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0),
    KC_TRNS,     KC_TRNS,    LCTL(KC_D), KC_TRNS,    KC_TRNS,     LALT(KC_H), LALT(KC_J), LALT(KC_K),    LALT(KC_L), KC_TRNS,
    KC_LSFT,    KC_TRNS,    LCTL(KC_C), LCTL(KC_V), KC_TRNS,     KC_TRNS,    KC_TRNS,    LALT(KC_COMM), KC_TRNS,    KC_RSFT,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,     LALT(LSFT(KC_ENT)), LALT(LSFT(KC_Q)), KC_TRNS
    ),

/* Keymap 2: Num/Sym Layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   `  2  |  3  |  4  |  5  |      |  6  |  7  |  8  -  9  =   0   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  !   ~  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  _  (  +   )   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * | SHIFT|  {  |  [  |  (  |     |      |CTL6 |  )  |  ]  |  }  | SHIFT |
 * `------+-----+-----+-----+-----'      `-------------------------------'
 *              .-----------------.      .-----------------.
 *              |     |    |      |      |     |     |     |
 *              '-----------------'      '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	   KC_6,  	   KC_7, 	 KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,
    KC_LSFT, KC_LCBR, KC_LBRC, KC_LPRN, KC_TRNS,   LCTL(KC_6), KC_RPRN, KC_RBRC, KC_RCBR,  KC_RSFT,
                      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS
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
                      KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    )
};
