//
//  Rocket.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

#include "glPlatform.h"
#include "Rocket.hpp"

static const float bombTime = 0.25f;
static const float maxFireTime = 0.75f;
static const float rocketSize = 0.125f;

Rocket::Rocket() : x(0.0f), y(0.0f), theta(0.0f), timeLeft(0.0f), fireTimeLeft(0.0f), gameOver(false), livesLeft(4)
{

}



void Rocket::Shoot()
{
    if(gameOver) return;

    if(timeLeft <= 0.0f)
    {
        timeLeft = bombTime;
    }
    
    missileManager.Add(x, y, theta);
}


void Rocket::DrawSmoke()
{
    if(gameOver) return;

    if(fireTimeLeft < 0.0f) return;


    fire.Activate();

    float fi = theta + 22.0f/7.0f;

    float dx = x + rocketSize*2.0f*cos(fi);
    float dy = y + rocketSize*2.0f*sin(fi);

    float p = (maxFireTime - fireTimeLeft)/maxFireTime;

    glColor4f(1.0f - p, 1.0f, 0.0f, 1.0f - p);
    TgaTexture::DrawQuad(dx, dy, rocketSize, rocketSize*0.5f, fi);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}


void Rocket::Draw()
{
    missileManager.Draw();

    if(!gameOver)
    {
        DrawSmoke();

        if(timeLeft > 0.0f)
            shootingTexture.Activate();
        else
            idleTexture.Activate();

        TgaTexture::DrawQuad(x, y, rocketSize, rocketSize, theta);

        DrawLives();
    }
    
    smoke.Draw();
}



void Rocket::DrawLives()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    for(int i = 0; i < livesLeft; i++)
    {
        float size = 1/20.0f;
        float x1 = 0.25f + float(i)*size*2.5f;
        float y1 = 1.0f - size*1.5f;

        shootingTexture.Activate();
        TgaTexture::DrawQuad(x1, y1, size, size, 22.0f/14.0f);
    }
}



void Rocket::Init()
{
    idleTexture.Init("rocket.tga");
    //idleTexture.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/rocket.tga");
    shootingTexture.Init("rocket_firing.tga");
    //shootingTexture.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/rocket_firing.tga");
    fire.Init("fire.tga");
    //fire.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/fire.tga");
    smoke.Init();
    missileManager.Init();
}



void Rocket::OnMouseMove(float x1, float y1)
{
    if(gameOver) return;

    x1 -= x;
    y1 -= y;
    theta = atan2(y1, x1);
}


bool Rocket::Update(float deltaTime, AsteroidManager* asteroidManager, SpaceShip* ship)
{
    timeLeft -= deltaTime;
    fireTimeLeft -= deltaTime;

    smoke.Update(deltaTime);
    asteroidManager->Update(deltaTime);
    ship->Update(deltaTime, x, y);
    missileManager.Update(deltaTime, asteroidManager, ship);
    
    if(gameOver) return gameOver;

    int hits = 0;
    if(asteroidManager->CheckCollision(x, y, rocketSize, true)) hits++;
    if(ship->CheckCollision(x, y, rocketSize)) hits++;

    for(int i = 0; i < hits; i++)
        ReduceHealth(ship);

    if(fireTimeLeft <= 0.0f) return gameOver;

    float speed = 0.5f;
    x += cos(theta)*speed*deltaTime;
    y += sin(theta)*speed*deltaTime;

    if(x - rocketSize >  1.0f)
        x -= 2.0f;
    else if(x + rocketSize < -1.0f)
        x += 2.0f;
    if(y - rocketSize >  1.0f)
        y -= 2.0f;
    else if(y + rocketSize < -1.0f)
        y += 2.0f;

    return gameOver;
}


void Rocket::Relocate(float x1, float y1)
{
    x = x1;
    y = y1;
    theta = 0.0f;
    gameOver = false;
    timeLeft = 0.0f;
    fireTimeLeft = 0.0f;
    livesLeft = 4;
    missileManager.Reset();
}


void Rocket::Progress()
{
    if(gameOver) return;

    if(fireTimeLeft <= 0.0f)

    fireTimeLeft = maxFireTime;
}


void Rocket::ReduceHealth(SpaceShip* ship)
{
    livesLeft--;
    if(livesLeft < 0)
    {
        ship->SetShooting(false);
        gameOver = true;
    }
    else
    {
        //
    }

    smoke.Activate(x, y, -1);
}

/*
void Rocket::RotateLeft(float deltaTheta)
{
    if(gameOver) return;
    theta -= deltaTheta;
}

void Rocket::RotateRight(float deltaTheta) 
{
    if(gameOver) return;
    theta += deltaTheta;
}
*/


