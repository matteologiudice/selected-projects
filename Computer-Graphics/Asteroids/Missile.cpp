//
//  Missile.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include <math.h>

#include "Missile.hpp"
# include "TgaTexture.hpp"

static const float missileSize = 0.05f;


Missile::Missile() : x(0.0f), y(0.0f), dx(0.0f), dy(0.0f), next(0), back(0) { }


Missile::Missile(float x1, float y1, float theta)
{
    x = x1;
    y = y1;

    dx = cos(theta);
    dy = sin(theta);

    next = 0;
    back = 0;
}



void Missile::Draw()
{
    TgaTexture::DrawQuad(x, y, missileSize, missileSize);
}


bool Missile::Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship, int* score)
{
    float speed = 2.0f;
    x += dx*speed*deltaTime;
    y += dy*speed*deltaTime;

    if(asteroidManager->CheckCollision(x, y, missileSize, false))
    {
        *score += 50;
        return true;
    }

    if(ship->CheckCollision(x, y, missileSize))
    {
        *score += 100;
        return true;
    }

    const float left = x - missileSize;
    const float right = x + missileSize;
    const float top = y + missileSize;
    const float bottom = y - missileSize;

    if(left < -1.0f) return true;
    if(right > 1.0f) return true;
    if(top < -1.0f) return true;
    if(bottom > 1.0f) return true;

    return false;
}

