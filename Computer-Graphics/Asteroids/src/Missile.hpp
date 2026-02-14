//
//  Missile.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>

# include "SpaceShip.hpp"
# include "AsteroidManager.hpp"

class Missile
{
    float x, y;
    float dx, dy;

    
public:
    Missile* next;
    Missile* back;

    Missile();
    Missile(float x1, float y1, float theta);

    void Draw();
    bool Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship, int* score);
};

#endif /* Missile_hpp */
