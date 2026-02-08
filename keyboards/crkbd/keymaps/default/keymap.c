#include QMK_KEYBOARD_H

// Layer Enum
enum layers {
    _DEF = 0,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _SET
};

// --- COMBOS ---
const uint16_t PROGMEM combo_enter_seq[] = {KC_J,    KC_K,    COMBO_END};
const uint16_t PROGMEM combo_tab_seq[]   = {KC_Q,    KC_W,    COMBO_END};
const uint16_t PROGMEM combo_c_bs_seq[]  = {KC_C,    KC_V,    COMBO_END};
const uint16_t PROGMEM combo_quot_seq[]  = {KC_COMM, KC_DOT,  COMBO_END};
const uint16_t PROGMEM combo_c_sf_seq[]  = {KC_Z,    KC_X,    COMBO_END};
const uint16_t PROGMEM combo_bs_seq[]    = {KC_D,    KC_F,    COMBO_END};
const uint16_t PROGMEM combo_a_sf_seq[]  = {KC_D,    KC_F,    COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter_seq, KC_ENT),
    COMBO(combo_tab_seq,   KC_TAB),
    COMBO(combo_c_bs_seq,  LCTL(KC_BSPC)),
    COMBO(combo_quot_seq,  KC_QUOT),
    COMBO(combo_c_sf_seq,  LCTL(KC_LSFT)),
    COMBO(combo_bs_seq,    KC_BSPC),
    COMBO(combo_a_sf_seq,  LALT(KC_LSFT)),
};

// --- KEYMAP ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Default */
    [_DEF] = LAYOUT_split_3x5_3(
    //  Q         W         E         R         T            Y         U         I         O         P
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    //  A         S         D         F         G            H         J         K         L         ;
        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
    //  Z         X         C         V         B            N         M         ,         .         /
        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    //                      LCTL      LALT      LSFT         SPC       SYM       GUI
                            KC_LCTL,  KC_LALT,  KC_LSFT,     KC_SPC,   TO(_SYM), KC_LGUI
    ),

    /* Layer 1: Symbols */
    [_SYM] = LAYOUT_split_3x5_3(
    //  ESC       @         #         $         %            ^         &         * !         BSPC
        KC_ESC,   KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,     KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_EXLM,  KC_BSPC,
    //  TAB       =         +         -         _            {         (         )         }         ENT
        KC_TAB,   KC_EQL,   KC_PLUS,  KC_MINS,  KC_UNDS,     KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  KC_ENT,
    //  FUN       `         ~         |         \            [         "         '         ]         NAV
        TO(_FUN), KC_GRV,   KC_TILD,  KC_PIPE,  KC_BSLS,     KC_LBRC,  KC_DQUO,  KC_QUOT,  KC_RBRC,  TO(_NAV),
    //                      LCTL      DEF       LSFT         SPC       NUM       RALT
                            KC_LCTL,  TO(_DEF), KC_LSFT,     KC_SPC,   TO(_NUM), KC_RALT
    ),

    /* Layer 2: Navigation */
    [_NAV] = LAYOUT_split_3x5_3(
    //  ESC       MB1       M_UP      MB2       TRANS        WhL       WhD       WhU       WhR       BSPC
        KC_ESC,   MS_BTN1,  MS_UP,    MS_BTN2,  KC_TRNS,     MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,  KC_BSPC,
    //  TAB       M_LEFT    M_DOWN    M_RGHT    TRANS        LEFT      DOWN      UP        RGHT      ENT
        KC_TAB,   MS_LEFT,  MS_DOWN,  MS_RGHT,  KC_TRNS,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_ENT,
    //  FUN       LWIN      MB3       TRANS     TRANS        TRANS     TRANS     TRANS     TRANS     NAV
        TO(_FUN), KC_LWIN,  MS_BTN3,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_NAV),
    //                      LCTL      DEF       LSFT         SPC       NUM       RALT
                            KC_LCTL,  TO(_DEF), KC_LSFT,     KC_SPC,   TO(_NUM), KC_RALT
    ),

    /* Layer 3: Numbers */
    [_NUM] = LAYOUT_split_3x5_3(
    //  ESC           CapWrd        Scroll        NumLk         PgUp             HOME          7             8             9             BSPC
        KC_ESC,       CW_TOGG,      KC_SCRL,      KC_NUM,       KC_PGUP,         KC_HOME,      KC_7,         KC_8,         KC_9,         KC_BSPC,
    //  S(TAB)        S(X)          S(C)          S(V)          PgDn             END           4             5             6             ENT
        LSFT(KC_TAB), LSFT(KC_X),   LSFT(KC_C),   LSFT(KC_V),   KC_PGDN,         KC_END,       KC_4,         KC_5,         KC_6,         KC_ENT,
    //  FUN           INS           UNDO          AGIN          DEL              0             1             2             3             NAV
        TO(_FUN),     KC_INS,       KC_UNDO,      KC_AGIN,      KC_DEL,          KC_0,         KC_1,         KC_2,         KC_3,         TO(_NAV),
    //                              RCTL          DEF           TRANS            LSFT          SPC           SYM
                                    KC_RCTL,      TO(_DEF),     KC_TRNS,         KC_LSFT,      KC_SPC,       TO(_SYM)
    ),

    /* Layer 4: Function */
    [_FUN] = LAYOUT_split_3x5_3(
    //  ESC       BrD       TRANS     BrU       TRANS        F9        F10       F11       F12       BSPC
        KC_ESC,   KC_BRID,  KC_TRNS,  KC_BRIU,  KC_TRNS,     KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC,
    //  TAB       Prev      Play      Next      TRANS        F5        F6        F7        F8        ENT
        KC_TAB,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_ENT,
    //  FUN       TRANS     Mute      TRANS     SET          F1        F2        F3        F4        NAV
        TO(_FUN), KC_TRNS,  KC_MUTE,  KC_TRNS,  TO(_SET),    KC_F1,    KC_F2,    KC_F3,    KC_F4,    TO(_NAV),
    //                      LCTL      DEF       TRANS        LSFT      SPC       NUM
                            KC_LCTL,  TO(_DEF), KC_TRNS,     KC_LSFT,  KC_SPC,   TO(_NUM)
    ),

    /* Layer 5: Settings */
    [_SET] = LAYOUT_split_3x5_3(
    //  ESC       NO        NO        NO        NO           TRANS     TRANS     TRANS     TRANS     BSPC
        KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSPC,
    //  TAB       NO        NO        NO        EEP_CLR      TRANS     BOOT      NO        RESET     ENT
        KC_TAB,   KC_NO,    KC_NO,    KC_NO,    EE_CLR,      KC_TRNS,  QK_BOOT,  KC_NO,    QK_RBT,   KC_ENT,
    //  FUN       NO        NO        NO        TRANS        TRANS     TRANS     TRANS     TRANS     NAV
        TO(_FUN), KC_NO,    KC_NO,    KC_NO,    KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_NAV),
    //                      LCTL      DEF       TRANS        LSFT      SPC       NUM
                            KC_LCTL,  TO(_DEF), KC_TRNS,     KC_LSFT,  KC_SPC,   TO(_NUM)
    ),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // These keys will NOT turn off Caps Word
        case KC_UNDS:
        case KC_MINS:
        case KC_BSPC: // Recommended: allows you to correct typos without exiting
            return true;

        // All other non-letter keys (Space, Enter, etc.) will turn it off
        default:
            return false;
    }
}