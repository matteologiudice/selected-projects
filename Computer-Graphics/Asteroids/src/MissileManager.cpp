//
//  MissileManager.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include "MissileManager.hpp"
# include "Utils.hpp"

MissileManager::MissileManager() : head(0), activeMissiles(0), score(0)
{

}


MissileManager::~MissileManager()
{
    Destroy();
}


void MissileManager::Destroy()
{
    Missile* missile = head;

    while(missile)
    {
        Missile* next = missile->back;
        delete missile;
        missile = next;
    }
    activeMissiles = 0;

    head = 0;
}


void MissileManager::Add(float x, float y, float theta)
{
    Missile* missile = new Missile(x, y, theta);

    missile->back = head;
    if(head) head->next = missile;
    head = missile;

    activeMissiles++;
}


void MissileManager::Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship)
{
    Missile* missile = head;
    while(missile)
    {
        if(missile->Update(deltaTime, asteroidManager, ship, &score))
        {
            missile = Remove(missile);
        }
        else
        {
            missile = missile->back;
        }
    }
}


void MissileManager::Draw()
{
    missileImage.Activate();
    
    Missile* missile = head;
    while(missile)
    {
        missile->Draw();
        missile = missile->back;
    }
    

    DisplayNumber(-0.75, 0.9f, 0.025f, score);
}


Missile* MissileManager::Remove(Missile* missile)
{
    if(!missile) return 0;

    activeMissiles--;

    if(missile->back)
        missile->back->next = missile->next;
    if(missile->next)
        missile->next->back = missile->back;
    
    if(missile == head)
        head = missile->back;

    Missile* temp = missile->back;
    delete missile;
    return temp;
}


void MissileManager::Init()
{
    missileImage.Init("missile.tga");
    //missileImage.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/missile.tga");
}


void MissileManager::Reset()
{
    Destroy();
    score = 0;
}

