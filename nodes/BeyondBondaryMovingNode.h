#pragma once
#include "../components/Size.h"
#include "../utilities/ScreenResolution.h"

class BeyondBondaryMovingNode
{
public:
    BeyondBondaryMovingNode(std::shared_ptr<Coord> doodleCoord, ScreenResolution screenResolution, Size size)
        : doodleCoord(doodleCoord),
          screenResolution(screenResolution),
          size(size){}

    Coord getDoodleCoord()
    {
        return *doodleCoord;
    }

    void setDoodleCoord(double x, double y)
    {
        this->doodleCoord->setX(x);
        this->doodleCoord->setY(y);
    }
    
    ScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    Size getSize()
    {
        return size;
    }
    
private:
    std::shared_ptr<Coord> doodleCoord;
    ScreenResolution screenResolution;
    Size size;
};
