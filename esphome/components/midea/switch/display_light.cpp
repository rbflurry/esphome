#include "display_light.h"

#if (defined(USE_ARDUINO) && !defined(USE_RP2) && !defined(USE_LIBRETINY)) || defined(USE_ESP_IDF)

namespace esphome::midea::ac {

void DisplayLightSwitch::write_state(bool state) {
  // The display is off while the appliance is off, so reject the request and restore the reported state.
  if (this->parent_->mode == climate::ClimateMode::CLIMATE_MODE_OFF) {
    this->publish_state(false);
    return;
  }

  if (state != this->parent_->get_display_light_state())
    this->parent_->do_display_toggle();

  // No optimistic publish: the appliance answers a toggle with a status frame,
  // which reaches this switch through AirConditioner::on_status_change().
}

}  // namespace esphome::midea::ac

#endif  // USE_ARDUINO || USE_ESP_IDF
