#pragma once

class Collider
{
public:
    static bool isCollide(double a1x, double a2x, double a1y, double a2y, double b1x, double b2x, double b1y, double b2y)
    {
        //TODO refactor
        int a1 = a1x > b2x;
        int a2 = a2x < b1x;
        int a3 = a1y < b2y;
        int a4 = a2y > b1y;
        
        if ( (a1 && a2 || a3 && a4) && (a1 + a2 + a3 + a4) == 2  )
        {
            return true;
        }
        return false;
    }

    static bool isCollideBelowLeftRight(double a1x, double a2x, double a2y, double b1x, double b2x, double b1y, double b2y)
    {
        return a2y > b1y && a2y < b2y &&
            ((a2x > b1x && a2x < b2x) || (a1x > b1x && a1x < b2x));
    }

    static bool isCollideBelow(double a2y, double b1y, double b2y)
    {
        return a2y > b1y && a2y < b2y;
    }
};
