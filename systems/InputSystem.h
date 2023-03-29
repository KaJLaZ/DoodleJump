#pragma once
#include <string>

template<class N, class I>
class InputSystem
{
    virtual void addNode(std::string&& uuid, N& node) = 0;

    virtual void process(I input) = 0;

    virtual void removeNode(std::string key) = 0;
};
