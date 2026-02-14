//
//  Bullet.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

# include <math.h>

#include "Bullet.hpp"
# include "TgaTexture.hpp"

static float bulletSize = 0.025f;

Bullet::Bullet() : x(0.0f), y(0.0f), dx(0.0f), dy(0.0f), active(false) { }


Bullet::Bullet(float x1, float y1, float x2, float y2)
{
    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;
    float distance = sqrt(dx*dx + dy*dy);

    dx /= distance;
    dy /= distance;

    active = true;
}



void Bullet::Draw()
{
    if(active)
        TgaTexture::DrawQuad(x, y, bulletSize, bulletSize, 0.0f);
}



void Bullet::Update(float deltaTime)
{
    x += dx*deltaTime;
    y += dy*deltaTime;

    if(x - bulletSize >  1.0f) active = false;
    else if(x + bulletSize < -1.0f) active = false;
    if(y - bulletSize >  1.0f)  active = false;
    else if(y + bulletSize < -1.0f) active = false;
}


bool Bullet::CheckCollision(float x1, float y1, float size)
{
    x1 -= x;
    y1 -= y;
    float distance = sqrt(x1*x1 + y1*y1);
    
    return (distance < (size+bulletSize));
}

