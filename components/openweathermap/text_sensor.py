import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor

# from esphome import automation
# from esphome.automation import maybe_simple_id
# from esphome.components.output import FloatOutput
from esphome.const import (
    CONF_ID,
    CONF_KEY,
    UNIT_CELSIUS,
    UNIT_EMPTY,
    UNIT_PERCENT,
    CONF_LAMBDA,
    CONF_TEXT_SENSORS,
)

CONF_CITY_ID = "city_id"
CONF_LANG = "language"
CONF_API_KEY = "api_key"

owm_ns = cg.esphome_ns.namespace("openweathermap")

LANGUAGES = ["it", "de", "en"]

# OpenWeatherMapClient = owm_ns.class_("openweathermapclient", cg.Component)
OpenWeatherMapClient = owm_ns.class_("openweathermapclient", cg.PollingComponent, text_sensor.TextSensor)

CONFIG_SCHEMA = text_sensor.TEXT_SENSOR_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(OpenWeatherMapClient),
        cv.Required(CONF_API_KEY): cv.string_strict,
        cv.Optional(CONF_LANG, default="en"): cv.one_of(list(LANGUAGES), lower=True),
        # cv.Optional(CONF_CITY_ID): cv.positive_int
    }
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await text_sensor.register_text_sensor(var, config)

