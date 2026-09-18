#include "display_light.h"

#if (defined(USE_ARDUINO) && !defined(USE_RP2) && !defined(USE_LIBRETINY)) || defined(USE_ESP_IDF)

namespace esphome::midea::ac {

void DisplayLightSwitch::write_state(bool state) {
  if (this->parent_->mode == climate::ClimateMode::CLIMATE_MODE_OFF) {
    this->publish_state(false);
    return;
  }

  this->parent_->do_display_toggle();
  this->publish_state(state);
}

}  // namespace esphome::midea::ac

#endif  // USE_ARDUINO || USE_ESP_IDF
