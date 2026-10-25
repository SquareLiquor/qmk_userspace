#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_CTRL = 0,
};

td_state_t cur_dance(tap_dance_state_t *state);

void ctrl_finished(tap_dance_state_t *state, void *user_data);
void ctrl_reset(tap_dance_state_t *state, void *user_data);
