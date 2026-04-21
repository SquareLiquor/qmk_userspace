#include "tap_dances.h"

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->interrupted || state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

static td_tap_t ctrl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ctrl_finished(tap_dance_state_t *state, void *user_data) {
    ctrl_tap_state.state = cur_dance(state);
    switch (ctrl_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F19); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: tap_code16(C(KC_UP)); break;
        case TD_DOUBLE_HOLD: register_code(KC_F11); break;
        default: break;
    }
}

void ctrl_reset(tap_dance_state_t *state, void *user_data) {
    switch (ctrl_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_F19); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F11); break;
        default: break;
    }
    ctrl_tap_state.state = TD_NONE;
}
