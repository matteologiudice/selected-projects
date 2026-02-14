//
//  Rocket.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef Rocket_hpp
#define Rocket_hpp

#include <stdio.h>

# include "Utils.hpp"
# include "SpaceShip.hpp"
# include "TgaTexture.hpp"
# include "SmokeEffect.hpp"
# include "MissileManager.hpp"

class Rocket
{
    float x;
    float y;
    float theta;
    float timeLeft;
    float fireTimeLeft;
    int   livesLeft;

    TgaTexture        idleTexture;
    TgaTexture        shootingTexture;
    TgaTexture        fire;
    SmokeEffect        smoke;

    MissileManager    missileManager;
    
    void DrawSmoke();
    void DrawLives();

    void ReduceHealth(SpaceShip* ship);

public:
    bool  gameOver;

    Rocket();

    void Init();

    void Draw();
    
    bool Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship);

    void Shoot();

    void Progress();

    void OnMouseMove(float x1, float y1);

    void Relocate(float x1, float y1);
    
    void RotateRight(float delta);
    
    void RotateLeft(float delta);
};

#endif /* Rocket_hpp */
