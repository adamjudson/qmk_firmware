#include "adam.h"

void my_custom_function(void) {
    
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == JSARROW && record->event.pressed) {
    SEND_STRING("=>");
  }
  
  return true;
}