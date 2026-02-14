//
//  SpaceShip.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

# include <math.h>

#include "glPlatform.h"
#include "SpaceShip.hpp"
# include "Utils.hpp"
# include "TgaTexture.hpp"

static float spaceShipSize = 0.125f;

SpaceShip::SpaceShip() : timeLeft(1.0f)
{
    Reset();
}


void SpaceShip::Reset()
{
    if(GetRandom(2))
    {
        x = GetRandomValue(-1.0f, 1.0f);
        y = 1.0f + spaceShipSize;
        if(GetRandom(2)) y = -y;
    }
    else
    {
        y = GetRandomValue(-1.0f, 1.0f);
        x = 1.0f + spaceShipSize;
        if(GetRandom(2)) x = -x;
    }

    dx = GetRandomValue(0.125f, 0.25f);
    dy = GetRandomValue(0.125f, 0.25f);

    if(x > 0.0f) dx = -dx;
    if(y > 0.0f) dy = -dy;

    color = GetRandom(3);

    gun.Reset();
    timeLeft = 1.0f;
}


void SpaceShip::Update(float deltaTime, float x1, float y1)
{
    float speed = 0.5f;
    x += dx*speed*deltaTime;
    y += dy*speed*deltaTime;
    
    const float left = x - spaceShipSize;
    const float right = x + spaceShipSize;
    const float top = y + spaceShipSize;
    const float bottom = y - spaceShipSize;
    const float offset = 1.1f;

    if(left > offset) Reset();
    else if(right < -offset) Reset();
    else if(top < -offset) Reset();
    else if(bottom > offset) Reset();

    smoke.Update(deltaTime);

    gun.Update(deltaTime);

    timeLeft -= deltaTime;
    if(timeLeft < 0.0f)
    {
        gun.Add(x, y, x1, y1);
        timeLeft = 1.0f;
    }
}


void SpaceShip::Draw()
{
    SetColor(color);
    spaceShipTexture.Activate();
    TgaTexture::DrawQuad(x, y, spaceShipSize, spaceShipSize, 0.0f);
    smoke.Draw();
    gun.Draw();
}



bool SpaceShip::CheckCollision(float x1, float y1, float size)
{
    float x2 = x1 - x;
    float y2 = y1 - y;
    float distance = sqrt(x2*x2 + y2*y2);
    
    if(distance < (size+spaceShipSize))
    {
        smoke.Activate(x, y, color);
        Reset();
        return true;
    }

    return gun.CheckCollision(x1, y1, size);
}


void SpaceShip::Init()
{
    spaceShipTexture.Init("spaceship.tga");
    //spaceShipTexture.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/spaceship.tga");
    smoke.Init();
    gun.Init();
}


void SpaceShip::SetShooting(bool mode)
{
    gun.SetShooting(mode);
}


