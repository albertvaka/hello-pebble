#include <pebble.h>

#include "windows/main_window.h"

typedef enum {
  Message = 0,   // The message (must also be in package.json)
} AppKey;

static void inbox_received_handler(DictionaryIterator *iter, void *context) {
  Tuple *message = dict_find(iter, Message);
  if(message) {
    // Show the image
    main_window_set_data(message);
  }
}

static void init() {
  window_init();

  app_message_register_inbox_received(inbox_received_handler);
  const int inbox_size = app_message_inbox_size_maximum();
  const int outbox_size = 64;
  app_message_open(inbox_size, outbox_size);
}

static void deinit() { 
  window_deinit();
}

int main() {
  init();
  app_event_loop();
  deinit();
}
