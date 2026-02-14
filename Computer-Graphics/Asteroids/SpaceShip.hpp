//
//  SpaceShip.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef SpaceShip_hpp
#define SpaceShip_hpp

#include <stdio.h>

# include "AlienGun.hpp"
# include "SmokeEffect.hpp"

class SpaceShip
{
    float x, y, dx, dy;
    int   color;

    
    TgaTexture    spaceShipTexture;
    SmokeEffect smoke;
    AlienGun    gun;

    float        timeLeft;
public:

    SpaceShip();

    void Init();

    void Reset();

    void Draw();

    void SetShooting(bool mode);

    void Update(float deltaTime, float x1, float y1);

    bool CheckCollision(float x, float y, float size);
};

#endif /* SpaceShip_hpp */
