//
//  Ship.cpp
//  Battleship
//

#include "Ship.h"
//***Delete after
#include <iostream>
using namespace std;
//***end delete

//*******************************************************************************************
//  Constructor
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
    origin = originPoint;
    orientation = o;
    length = l;
    
    for(int i = 0; i < length; i++)
    {
        if (orientation == HORIZONTAL)
        {
            origin.setX(i);
            points.add(origin);
            
            // For compiling purposes
            /*cout << origin.getX() << endl;
            cout << origin.getY() << endl;
            cout << orientation << endl;
            cout << length << endl << endl;
             */
        }
        else if(orientation == VERTICAL)
        {
            origin.setY(i);
            points.add(origin);
            
            // For compiling purposes
            /*
            cout << origin.getX() << endl;
            cout << origin.getY() << endl;
            cout << orientation << endl;
            cout << length << endl << endl;
             */
        }
    }
    

    
}

//*******************************************************************************************
//  Copy Constructor
//*******************************************************************************************

Ship::Ship(const Ship& s) 
{
    origin = s.origin;
    orientation = s.orientation;
    length = s.length;
    
    points = s.points;
    hits = s.hits;
}

//*******************************************************************************************
// Contains Point. Returns true if a Ship covers a point on the board, false if it does not
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{
    return (points.contains(p));
}

//*******************************************************************************************
// Collides With. Returns true if the receiving ship shares a point with the argument ship,
//      false if it does not
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
    bool pointw = false;
    for (int i = 0; i < points.getSize(); i ++)
    {
        if (points.contains(s.points.get(i)))
            pointw = true;
    }
    return pointw;
}

//*******************************************************************************************
// Shot Fired At Point. This is the verb in the game. When the user enters a coordinate,
//      this method can be called on each ship. If the ship contains the point, it should
//      remember that it has been hit at that point. It should do this with a second
//      PointCollection, or some other data strategy.
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
    if(containsPoint(p))
    {
        hits.add(p);
    }

}

//*******************************************************************************************
// Is Hit At Point. Return true if shotFiredAtPoint() has been called for point p in the
//      ship. False if it has not, or if the point is not in the ship.
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
    return (hits.contains(p));
}

//*******************************************************************************************
// Hit Count. Returns the number of points in the ship that have been hit. When the
//      hitCount is equal to the length of the ship the ship is considered to be sunk.
//*******************************************************************************************

int Ship::hitCount() const
{
    return hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
    length = s.length;
    orientation = s.orientation;
    points = s.points;
    hits = s.hits;
	return *this;
}


//*******************************************************************************************
//  Is Sunk. Returns true if the ship is sunk
//*******************************************************************************************

bool Ship::isSunk() 
{
    
    return (hits.getSize() == length);
}











