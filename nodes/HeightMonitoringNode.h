#pragma once
#include "../components/Coord.h"
#include <memory>
#include <utility>

class HeightMonitoringNode
{
public:
    HeightMonitoringNode(std::shared_ptr<Coord> coord, double maxHeight, std::shared_ptr<double> score,
        ScreenResolution screenResolution, std::shared_ptr<bool> isGameOver)
        : coord(std::move(coord)),
          maxHeight(maxHeight),
          score(std::move(score)),
          screenResolution(screenResolution),
          isGameOver(std::move(isGameOver)){}

    Coord getCoord()
    {
        return *coord;
    }

    void setCoord(double x, double y)
    {
        this->coord->setX(x);
        this->coord->setY(y);
    }

    double getMaxHeight()
    {
        return maxHeight;
    }

    std::shared_ptr<double> getScore() const
    {
        return score;
    }

    ScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    std::shared_ptr<bool> IsGameOver() const
    {
        return isGameOver;
    }

private:
    std::shared_ptr<Coord> coord;
    double maxHeight;
    std::shared_ptr<double> score;
    ScreenResolution screenResolution;
    std::shared_ptr<bool> isGameOver;
};
