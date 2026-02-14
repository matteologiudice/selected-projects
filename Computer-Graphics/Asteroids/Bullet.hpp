//
//  Bullet.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>

struct Bullet
{
    float x, y, dx, dy;
    bool  active;

public:

    Bullet();

    Bullet(float x1, float y1, float x2, float y2);

    void Update(float deltaTime);

    void Draw();
    
    bool CheckCollision(float x, float y, float size);
};

#endif /* Bullet_hpp */
