import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import ENTITY_CATEGORY_CONFIG, ICON_BRIGHTNESS_6

from ..climate import AirConditioner, midea_ac_ns

CONF_MIDEA_ID = "midea_id"
CONF_DISPLAY_LIGHT = "display_light"

DisplayLightSwitch = midea_ac_ns.class_(
    "DisplayLightSwitch", switch.Switch, cg.Parented.template(AirConditioner)
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_MIDEA_ID): cv.use_id(AirConditioner),
        cv.Optional(CONF_DISPLAY_LIGHT): switch.switch_schema(
            DisplayLightSwitch,
            icon=ICON_BRIGHTNESS_6,
            entity_category=ENTITY_CATEGORY_CONFIG,
            # The appliance reports the display state, so there is nothing to restore.
            default_restore_mode="DISABLED",
        ),
    }
)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_MIDEA_ID])

    if CONF_DISPLAY_LIGHT in config:
        sw_var = await switch.new_switch(config[CONF_DISPLAY_LIGHT])
        await cg.register_parented(sw_var, parent)
        cg.add(parent.set_display_light_switch(sw_var))
