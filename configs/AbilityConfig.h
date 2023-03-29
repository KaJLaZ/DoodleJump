#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct AbilityConfig
    {
        std::string spriteFilePath;
        double width;
        double height;
        int spawningJumpAmount;
    };
    
    void to_json(json& j, AbilityConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"width", setting.width}, {"height", setting.height},
            {"spawningJumpAmount", setting.spawningJumpAmount}
        };
    }

    void from_json(const json& j, AbilityConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("spawningJumpAmount").get_to(setting.spawningJumpAmount);
    }
}
