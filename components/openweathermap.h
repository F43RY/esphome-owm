#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace openweathermap {

// static const char *ESPOWM_VERSION = "1.0.0";

// static const uint32_t ESPOWM_POLL_INTERVAL_DEFAULT = 100000;

// static const char SERVERNAME[] = "api.openweathermap.org/data/2.5/weather?";

class OpenWeatherMapClient : public PollingComponent, public text_sensor::TextSensor {
 public:
  // OpenWeatherMapClient(const std::function<std::vector<text_sensor::TextSensor *>()> &init) {
  //   this->text_sensors_ = init();
  // }

  // text_sensor::TextSensor *get_text_sensor(int i) { return this->text_sensors_[i]; }
  void update() override;
  void dump_config() override;

 protected:
  // std::vector<text_sensor::TextSensor *> text_sensors_;
};

}  // namespace openweathermap
}  // namespace esphome
