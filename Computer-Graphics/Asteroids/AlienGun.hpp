//
//  AlienGun.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef AlienGun_hpp
#define AlienGun_hpp

#include <stdio.h>
#include <vector>

# include "Bullet.hpp"
# include "TgaTexture.hpp"

class AlienGun
{
    TgaTexture bulletImage;

    std::vector<Bullet> bullets;

    bool shootMode;

public:

    AlienGun();

    void Add(float x1, float y1, float x2, float y2);

    void Init();
    void Reset();
    void Update(float deltaTime);
    bool CheckCollision(float x, float y, float size);
    void Draw();
    void SetShooting(bool mode);
};

#endif /* AlienGun_hpp */
