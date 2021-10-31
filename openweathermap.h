#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace openweathermap {

enum APIName {
  BY_CITY_NAME = 0,
  BY_CITY_ID,
  BY_GEOGRAPHIC_COORDINATES,
  BY_ZIP_CODE
};

static const char *ESPOWM_VERSION = "1.0.0";

static const uint32_t ESPOWM_POLL_INTERVAL_DEFAULT = 100000;

static const char SERVERNAME[] = "api.openweathermap.org/data/2.5/weather?";

class OpenWeatherMapClient : public Component {
 public:
  OpenWeatherMapClient(const std::function<std::vector<text_sensor::TextSensor *>()> &init) {
    this->text_sensors_ = init();
  }

  text_sensor::TextSensor *get_text_sensor(int i) { return this->text_sensors_[i]; }

  void dump_config() override;

 protected:
  std::vector<text_sensor::TextSensor *> text_sensors_;
};

}  // namespace openweathermap
}  // namespace esphome
