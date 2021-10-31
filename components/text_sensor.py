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

owm_ns = cg.esphome_ns.namespace("openweathermap")

APIName = owm_ns.enum("APIName")
API_NAME = {
    "API_BY_CITY_NAME": APIName.BY_CITY_NAME,
    "API_BY_CITY_ID": APIName.BY_CITY_ID,
    "API_BY_GEOGRAPHIC_COORDINATES": APIName.BY_GEOGRAPHIC_COORDINATES,
    "API_BY_ZIP_CODE": APIName.BY_ZIP_CODE,
}

OpenWeatherMapClient = owm_ns.class_("openweathermapclient", cg.Component)
# ServoWriteAction = servo_ns.class_("ServoWriteAction", automation.Action)
# ServoDetachAction = servo_ns.class_("ServoDetachAction", automation.Action)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(OpenWeatherMapClient),
        cv.Required(CONF_LAMBDA): cv.returning_lambda,
        cv.Required(CONF_TEXT_SENSORS): cv.ensure_list(
            text_sensor.TEXT_SENSOR_SCHEMA.extend(
                {
                    cv.GenerateID(): cv.declare_id(text_sensor.TextSensor),
                }
            )
        ),
    }
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

