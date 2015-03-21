#include "pebble.h"
#include "ShadowTextLayer.h"

static Window *window;

static ShadowTextLayer *shadow_text_layer1;

static void init() {
  window = window_create();
  window_stack_push(window, true);

  #ifdef PBL_COLOR
  window_set_background_color(window, GColorMediumSpringGreen);
  #else
  window_set_background_color(window, GColorBlack);
  #endif
  shadow_text_layer1 = shadow_text_layer_create(GRect(0, 68, 144, 30));
  shadow_text_layer_set_text(shadow_text_layer1, "Hello world!");

  #ifdef PBL_COLOR
  shadow_text_layer_set_background_color(shadow_text_layer1, GColorCobaltBlue);
  shadow_text_layer_set_text_color(shadow_text_layer1, GColorVividCerulean);
  shadow_text_layer_set_shadow_color(shadow_text_layer1, GColorOxfordBlue);
  #else
  #endif

  shadow_text_layer_set_shadow_offset(shadow_text_layer1, GPoint(1, 1));
  shadow_text_layer_set_text_alignment(shadow_text_layer1, GTextAlignmentCenter);
  shadow_text_layer_set_font(shadow_text_layer1,
                             fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));

  Layer *window_layer = window_get_root_layer(window);
  layer_add_child(window_layer, shadow_text_layer_get_layer(shadow_text_layer1));
}

static void deinit() {
  shadow_text_layer_destroy(shadow_text_layer1);
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
