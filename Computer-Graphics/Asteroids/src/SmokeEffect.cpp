//
//  SmokeEffect.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include "SmokeEffect.hpp"
# include "Utils.hpp"

static float maxTime = 1.0f;

SmokeEffect::SmokeEffect() : x(0.0f), y(0.0f), time(0.0f), active(false) { }


void SmokeEffect::Activate(float x1, float y1, int clr)
{
    active = true;

    x = x1;
    y = y1;

    color = clr;
}



void SmokeEffect::Draw()
{
    if(!active) return;

    smoke.Activate();

    SetColor(color);
    float size = TriangleWave(time, maxTime, 0.0f, 0.125f);
    TgaTexture::DrawQuad(x, y, size, size, 0.0f);
}



bool SmokeEffect::Update(float deltaTime)
{
    if(!active) return false;

    float halfTime = maxTime / 2.0f;

    bool flag1 = (time < halfTime);
    time += deltaTime;
    bool flag2 = (time >= halfTime);

    if(time > maxTime)
    {
        time = 0.0f;
        active = false;
    }

    return flag1 && flag2;
}


void SmokeEffect::Init()
{
    smoke.Init("cloud.tga");
    //smoke.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/cloud.tga");
}
