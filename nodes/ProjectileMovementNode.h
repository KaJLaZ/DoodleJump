#pragma once
#include "../components/Speed.h"

class ProjectileMovementNode
{
public:
    ProjectileMovementNode(std::shared_ptr<Coord> coord, std::shared_ptr<Speed> speed)
        : coord(std::move(coord)), speed(std::move(speed)){}

    Coord getCoord()
    {
        return *coord;
    }

    Speed getSpeed()
    {
        return *speed;
    }

    void shiftCoord(double x, double y)
    {
        this->coord->setX(coord->getX() + x);
        this->coord->setY(coord->getY() + y);
    }

    void shiftSpeed(double x, double y)
    {
        this->speed->setX(speed->getX() + x);
        this->speed->setY(speed->getY() + y);
    }

private:
    std::shared_ptr<Coord> coord;
    std::shared_ptr<Speed> speed;
};

