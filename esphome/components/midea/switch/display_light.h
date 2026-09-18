#pragma once

#if (defined(USE_ARDUINO) && !defined(USE_RP2) && !defined(USE_LIBRETINY)) || defined(USE_ESP_IDF)

#include "esphome/components/switch/switch.h"
#include "esphome/components/midea/air_conditioner.h"

namespace esphome::midea::ac {

class DisplayLightSwitch : public switch_::Switch, public Parented<AirConditioner> {
 protected:
  void write_state(bool state) override;
};

}  // namespace esphome::midea::ac

#endif  // USE_ARDUINO || USE_ESP_IDF
