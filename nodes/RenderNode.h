#include <memory>
#include "../components/Coord.h"
#include "../components/Size.h"

class RenderNode
{
public:
    RenderNode(Sprite* sprite, std::shared_ptr<Coord> coord, Size size)
        : sprite(std::move(sprite)),
        coord(std::move(coord)),
        size(size) {}

    Sprite* getSprite() const
    {
        return sprite;
    }

    Coord getCoord()
    {
        return *coord;
    }

    Size getSize() const
    {
        return size;
    }
    
private:
    Sprite* sprite;
    std::shared_ptr<Coord> coord;
    Size size;
};
