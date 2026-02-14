//
//  Asteroid.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

# include <math.h>
# include <random>

#include "glPlatform.h"
#include "Asteroid.hpp"
# include "Utils.hpp"
# include "TgaTexture.hpp"

Asteroid::Asteroid():back(0), next(0)
{
    Reset();
}


void Asteroid::Reset()
{
    if(GetRandom(2))
    {
        x = GetRandomValue(-1.0f, 1.0f);
        y = 1.1f;
        if(GetRandom(2)) y = -y;
    }
    else
    {
        y = GetRandomValue(-1.0f, 1.0f);
        x = 1.1f;
        if(GetRandom(2)) x = -x;
    }

    dx = GetRandomValue(0.125f, 0.25f);
    dy = GetRandomValue(0.125f, 0.25f);

    if(x > 0.0f) dx = -dx;
    if(y > 0.0f) dy = -dy;

    theta = GetRandomValue(-4.0f, 4.0f);

    color = GetRandom(6);
    size = GetRandomValue(0.05f, 0.1f);
}


bool Asteroid::Update(float deltaTime)
{
    theta += deltaTime*size*10.0f;

    float speed = 0.5f;
    x += dx*speed*deltaTime;
    y += dy*speed*deltaTime;
    
    const float left = x - size;
    const float right = x + size;
    const float top = y + size;
    const float bottom = y - size;
    const float offset = 1.1f;

    if(left > offset) Reset();
    else if(right < -offset) Reset();
    else if(top < -offset) Reset();
    else if(bottom > offset) Reset();

    return false;
}


void Asteroid::Draw()
{
    SetColor(color);
    TgaTexture::DrawQuad(x, y, size, size, theta);
}



bool Asteroid::CheckCollision(float x1, float y1, float size1)
{
    x1 -= x;
    y1 -= y;
    float distance = sqrt(x1*x1 + y1*y1);
    
    return (distance < (size+size1));
}


bool Asteroid::Clone()
{
    size /= 2.0f;

    if(size < 0.025f) return false;

    dx = -dx;

    Asteroid* asteroid = new Asteroid();

    asteroid->x = x;
    asteroid->y = y;
    asteroid->dx = -dx;
    asteroid->dy = dy;
    asteroid->size = size;
    asteroid->color = color;

    asteroid->back = back;
    asteroid->next = this;

    if(back) back->next = asteroid;
    back = asteroid;
    return true;
}
