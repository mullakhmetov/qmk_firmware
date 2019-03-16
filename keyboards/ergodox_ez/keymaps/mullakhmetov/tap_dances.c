enum {
 TD_L_PARENTH_BRACKET = 0,
 TD_R_PARENTH_BRACKET,
 TD_LT_LTE,
 TD_GT_GTE,
 TD_EQ_NEQ,
 TD_QUOTES,
 TD_MINUS_UNDERSCORE
};

void tap_dance_lte (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING ("<");
  } else {
    SEND_STRING ("<=");
  }
  reset_tap_dance (state);
}

void tap_dance_gte (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING (">");
  } else {
    SEND_STRING (">=");
  }
  reset_tap_dance (state);
}

void tap_dance_neq (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING ("=");
  } else {
    SEND_STRING ("!=");
  }
  reset_tap_dance (state);
}

void tap_dance_quotes (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING ("'");
  } else {
    SEND_STRING ("\"");
  }
  reset_tap_dance (state);
}


qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for left parenthesis, twice for left bracket
  [TD_L_PARENTH_BRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LBRC),
  [TD_R_PARENTH_BRACKET]  = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RBRC),
  [TD_LT_LTE]             = ACTION_TAP_DANCE_FN(tap_dance_lte),
  [TD_GT_GTE]             = ACTION_TAP_DANCE_FN(tap_dance_gte),
  [TD_EQ_NEQ]             = ACTION_TAP_DANCE_FN(tap_dance_neq),
  [TD_QUOTES]             = ACTION_TAP_DANCE_FN(tap_dance_quotes),
  [TD_MINUS_UNDERSCORE]   = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS)
};