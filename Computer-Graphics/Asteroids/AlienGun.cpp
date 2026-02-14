//
//  AlienGun.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include "glPlatform.h"
#include "AlienGun.hpp"

AlienGun::AlienGun() : shootMode(true)
{

}

void AlienGun::Add(float x1, float y1, float x2, float y2)
{
    if(shootMode)
    {
        bullets.push_back(Bullet(x1, y1, x2, y2));
    }
}


void AlienGun::Init()
{
    bulletImage.Init("missile.tga");
    //bulletImage.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/missile.tga");
}


void AlienGun::Reset()
{
    bullets.clear();
}



void AlienGun::Update(float deltaTime)
{
    for(size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update(0.01f);
    }
}



bool AlienGun::CheckCollision(float x, float y, float size)
{
    for(size_t i = 0; i < bullets.size(); i++)
    {
        if(bullets[i].CheckCollision(x, y, size))
        {
            bullets.erase(bullets.begin() + i);
            return true;
        }
    }

    return false;
}


void AlienGun::Draw()
{
    bulletImage.Activate();

    for(size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw();
    }
}


void AlienGun::SetShooting(bool mode)
{
    shootMode = mode;
}

