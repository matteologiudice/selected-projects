//
//  AsteroidManager.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include <ctime>  // for time()

#include "AsteroidManager.hpp"
# include "Asteroid.hpp"

AsteroidManager::AsteroidManager() : head(0)
{
}


AsteroidManager::~AsteroidManager()
{
    Destroy();
}


void AsteroidManager::Destroy()
{
    Asteroid* asteroid = head;

    while(asteroid)
    {
        Asteroid* temp = asteroid->back;
        delete asteroid;
        asteroid = temp;
    }

    head = 0;
}


void AsteroidManager::Init()
{
    asteroidImage.Init("asteroid.tga");
    //asteroidImage.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/asteroid.tga");

    srand(static_cast<unsigned int>(time(NULL)));

    for(int i = 0; i < 10; i++)
    {
        Asteroid* asteroid = new Asteroid();
        asteroid->back = head;
        if(head) head->next = asteroid;
        head = asteroid;
    }
}


void AsteroidManager::Update(float deltaTime)
{
    Asteroid* asteroid = head;

    if(deltaTime > 0.1f) deltaTime = 0.1f;

    while(asteroid)
    {
        Asteroid* temp = asteroid->back;
        asteroid->Update(deltaTime);
        asteroid = temp;
    }
}



void AsteroidManager::Draw()
{
    Asteroid* asteroid = head;

    asteroidImage.Activate();

    while(asteroid)
    {
        Asteroid* temp = asteroid->back;
        asteroid->Draw();
        asteroid = temp;
    }

    glColor3f(1.0f, 1.0f, 1.0f);
}


bool AsteroidManager::CheckCollision(float x, float y, float size, bool destroy)
{
    Asteroid* asteroid = head;
    while(asteroid)
    {
        if(asteroid->CheckCollision(x, y, size))
        {
            if(destroy || !asteroid->Clone())
                asteroid = Remove(asteroid);
            return true;
        }
        asteroid = asteroid->back;
    }

    return false;
}




Asteroid* AsteroidManager::Remove(Asteroid* asteroid)
{
    if(!asteroid) return 0;

    if(asteroid->back)
        asteroid->back->next = asteroid->next;
    if(asteroid->next)
        asteroid->next->back = asteroid->back;
    
    if(asteroid == head)
        head = asteroid->back;

    Asteroid* temp = asteroid->back;
    delete asteroid;
    
    // Update position based on the golden ratio
    static double position = 0.5;  // Initialize position with a starting value.

    position += golden_ratio;
    position -= floor(position);

    // If the position is less than 0.6 (60%), create a new asteroid
    if (position < 0.6)
    {
        Asteroid* newAsteroid = new Asteroid();
        newAsteroid->back = head;
        if (head) head->next = newAsteroid;
        head = newAsteroid;
    }
    
    return temp;
}
