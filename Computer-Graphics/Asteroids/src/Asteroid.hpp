//
//  Asteroid.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include <stdio.h>

class Asteroid
{
    float x, y, dx, dy;
    float theta;
    int color;
    float size;

    void Reset();

public:

    Asteroid* back;
    Asteroid* next;

    Asteroid();

    bool Clone();

    bool Update(float deltaTime);
    void Draw();
    bool CheckCollision(float x1, float y1, float size1);
};

#endif /* Asteroid_hpp */
