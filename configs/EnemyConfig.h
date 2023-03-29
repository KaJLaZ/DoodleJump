#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct EnemyConfig
    {
        std::string spriteFilePath;
        double width;
        double height;
        double probability;
    };
    
    void to_json(json& j, EnemyConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"width", setting.width}, {"height", setting.height},
        {"probability", setting.probability}
        };
    }

    void from_json(const json& j, EnemyConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("probability").get_to(setting.probability);
    }
}
