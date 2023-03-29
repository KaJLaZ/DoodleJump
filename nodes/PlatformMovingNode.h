#include <memory>
#include <utility>
#include "../components/Coord.h"
#include "../components/Size.h"
#include "../utilities/ScreenResolution.h""

class RandomValueGenerator;

class PlatformMovingNode
{
public:
    PlatformMovingNode(std::shared_ptr<double> gravitationSpeed, ScreenResolution screen_resolution, Size size, std::shared_ptr<Coord> coord,
        std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator,
        std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator)
        : gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screen_resolution),
          size(size),
          coord(std::move(coord)),
          platformXCordRandomValueGenerator(std::move(platformXCordRandomValueGenerator)),
          platformYCordRandomValueGenerator(std::move(platformYCordRandomValueGenerator)){}
    
    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    ScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    Size getSize() const
    {
        return size;
    }

    std::shared_ptr<Coord> getCoord() const
    {
        return coord;
    }

    void setCoord(double x, double y)
    {
        this->coord->setX(x);
        this->coord->setY(y);
    }

    std::shared_ptr<RandomValueGenerator> getPlatformXCordRandomValueGenerator() const
    {
        return platformXCordRandomValueGenerator;
    }

    std::shared_ptr<RandomValueGenerator> getPlatformYCordRandomValueGenerator() const
    {
        return platformYCordRandomValueGenerator;
    }

private:
    std::shared_ptr<double> gravitationSpeed;
    ScreenResolution screenResolution;
    Size size;
    std::shared_ptr<Coord> coord;
    std::shared_ptr<RandomValueGenerator> platformXCordRandomValueGenerator;
    std::shared_ptr<RandomValueGenerator> platformYCordRandomValueGenerator;
};
