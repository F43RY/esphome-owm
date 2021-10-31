#include "openweathermap.h"
#include "esphome/core/log.h"

namespace esphome {
namespace openweathermap {

static const char *const TAG = "openweathermap";

void OpenWeatherMapClient::dump_config() {
  ESP_LOGCONFIG(TAG, "OpenWeatherMap:");
//  ESP_LOGCONFIG(TAG, "  Idle Level: %.1f%%", this-> * 100.0f);
//   ESP_LOGCONFIG(TAG, "  Min Level: %.1f%%", this->min_level_ * 100.0f);
//   ESP_LOGCONFIG(TAG, "  Max Level: %.1f%%", this->max_level_ * 100.0f);
//   ESP_LOGCONFIG(TAG, "  auto detach time: %d ms", this->auto_detach_time_);
//   ESP_LOGCONFIG(TAG, "  run duration: %d ms", this->transition_length_);
}

}  // namespace openweathermap
}  // namespace esphome