#include "adam.h"

void my_custom_function(void) {
    
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == JSARROW && record->event.pressed) {
    SEND_STRING("=>");
  } else if (keycode == BRACKETS && record->event.pressed) {
    SEND_STRING("() ");
  } else if (keycode == ARRAY && record->event.pressed) {
    SEND_STRING("[] ");
  } else if (keycode == ARRAY_INSIDE && record->event.pressed) {
    SEND_STRING("[]"SS_TAP(X_LEFT));
  } else if (keycode == END_TAG && record->event.pressed) {
    SEND_STRING("</");
  }
  
  return true;
}
