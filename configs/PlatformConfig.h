#pragma once

#include <../include/json.hpp>

using nlohmann::json;

namespace config {
    struct PlatformConfig
    {
        std::string spriteFilePath;
        double posX;
        double posY;
        double width;
        double height;
        int platformAmount; 
    };

    void to_json(json& j, PlatformConfig& setting) {
        j = json{ {"spriteFilePath", setting.spriteFilePath},
        {"x", setting.posX}, {"y", setting.posY},
        {"width", setting.width}, {"height", setting.height},
        {"platformAmount", setting.platformAmount}};
    }

    void from_json(const json& j, PlatformConfig& setting) {
        j.at("spriteFilePath").get_to(setting.spriteFilePath);
        j.at("x").get_to(setting.posX);
        j.at("y").get_to(setting.posY);
        j.at("width").get_to(setting.width);
        j.at("height").get_to(setting.height);
        j.at("platformAmount").get_to(setting.platformAmount);
    }
}
