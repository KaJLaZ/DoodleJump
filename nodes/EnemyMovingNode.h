#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "../components/Coord.h"
#include "../utilities/ScreenResolution.h""

class EnemyMovingNode
{
public:
    EnemyMovingNode(std::shared_ptr<double> gravitationSpeed, ScreenResolution screenResolution,
        std::shared_ptr<Coord> coord, std::shared_ptr<std::vector<std::string>> removingUUID, std::string UUID)
        : gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screenResolution),
          coord(std::move(coord)),
          removingUUID(std::move(removingUUID)),
          UUID(std::move(UUID)){}

    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    ScreenResolution getScreenResolution() const
    {
        return screenResolution;
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

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::string getUUID() const
    {
        return UUID;
    }

private:
    std::shared_ptr<double> gravitationSpeed;
    ScreenResolution screenResolution;
    std::shared_ptr<Coord> coord;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string UUID;
};
