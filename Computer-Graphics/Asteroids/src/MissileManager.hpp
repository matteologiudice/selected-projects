//
//  MissileManager.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef MissileManager_hpp
#define MissileManager_hpp

#include <stdio.h>

# include "Missile.hpp"
# include "SpaceShip.hpp"
# include "TgaTexture.hpp"

class MissileManager
{
    TgaTexture        missileImage;
    Missile*        head;
    int                activeMissiles;
    int                score;

    Missile* Remove(Missile* missile);

public:

    MissileManager();
    ~MissileManager();

    void Init();
    void Destroy();
    void Reset();

    void Add(float x, float y, float theta);
    void Draw();
    void Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship);
};

#endif /* MissileManager_hpp */
