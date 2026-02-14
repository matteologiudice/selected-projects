//
//  SmokeEffect.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef SmokeEffect_hpp
#define SmokeEffect_hpp

#include <stdio.h>

# include "TgaTexture.hpp"

class SmokeEffect
{
    TgaTexture smoke;

    float x, y;
    float time;
    int color;

    bool active;

public:

    SmokeEffect();

    void Init();

    void Activate(float x1, float y1, int color);

    bool Update(float deltaTime);

    void Draw();
};

#endif /* SmokeEffect_hpp */
