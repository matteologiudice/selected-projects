//
//  AsteroidManager.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef AsteroidManager_hpp
#define AsteroidManager_hpp

#include <stdio.h>
#include <cmath>

# include "Asteroid.hpp"
# include "TgaTexture.hpp"

class AsteroidManager
{
    static const int MaxAsteroids = 25;

    TgaTexture    asteroidImage;
    Asteroid*    head;

private:
    
    double position;
    static constexpr double golden_ratio = 1.618033988749895;
    
public:

    AsteroidManager();
    ~AsteroidManager();

    void Destroy();
    void Update(float deltaTime);
    void Draw();
    void Init();

    bool CheckCollision(float x, float y, float size, bool destroy);

    Asteroid* Remove(Asteroid* asteroid);
};

#endif /* AsteroidManager_hpp */
