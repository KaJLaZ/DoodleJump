#pragma once

#include <memory>
#include "../components/Coord.h"

class GravitationNode
{
public:
    GravitationNode(std::shared_ptr<Coord> subjectCoord, std::shared_ptr<double> gravitationSpeed)
        : subjectCoord(std::move(subjectCoord)),
          gravitationSpeed(gravitationSpeed){}

    Coord getSubjectCoord()
    {
        return *subjectCoord;
    }

    void shiftCoord(double x, double y)
    {
        this->subjectCoord->setX(subjectCoord->getX() + x);
        this->subjectCoord->setY(subjectCoord->getY() + y);
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }
    
private:
    std::shared_ptr<Coord> subjectCoord;
    std::shared_ptr<double> gravitationSpeed;
};
