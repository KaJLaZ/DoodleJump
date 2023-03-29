#pragma once
#include <memory>
#include "../Framework.h"

class PressedMouseButtonTrackNode
{
public:
    PressedMouseButtonTrackNode(std::shared_ptr<FRMouseButton> mouseButton) : mouseButton(std::move(mouseButton)) {}

    FRMouseButton getMouseButton()
    {
        return *mouseButton;
    }

    void setMouseButton(FRMouseButton key)
    {
        *mouseButton = key;
    }

private:
    std::shared_ptr<FRMouseButton> mouseButton;
};
