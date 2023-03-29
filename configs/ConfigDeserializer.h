#pragma once
#include <fstream>

class ConfigDeserializer
{
public:
    template<class T>
    static T deserializeConfig(const char* path)
    {
        return json::parse(std::ifstream(path))
            .get<T>();
    }
};