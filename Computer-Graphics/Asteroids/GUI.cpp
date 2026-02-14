//
//  GUI.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include "GUI.hpp"

GUI::GUI() : x(0.0f), y(0.0f), sizeX(0.25f), sizeY(0.125f), active(true), onClick(0)
{
}



void GUI::Activate()
{
    active = true;
}



void GUI::Init(float x1, float y1, float sizeX1, float sizeY1, EventHandler function)
{
    onClick = function;

    x = x1;
    y = y1;
    sizeX = sizeX1;
    sizeY = sizeY1;

    start.Init("start.tga");
    //start.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/start.tga");
    gameOver.Init("game_over.tga");
    //gameOver.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/game_over.tga");
    playAgain.Init("play_again.tga");
    //playAgain.Init("/Users/matteo_logiudice/Desktop/Prog03/Prog03/play_again.tga");
}



void GUI::HandleMouseClick(float x1, float y1)
{
    float left = x - sizeX;
    float right = x + sizeX;
    float top = y + sizeY;
    float bottom = y - sizeY;

    if(x1 < left) return;
    if(y1 < bottom) return;
    if(x1 > right) return;
    if(y1 > top) return;

    if(onClick)
        onClick();
}

bool highlight = false;

void GUI::Draw(bool paused, bool over)
{
    if(over)
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        gameOver.Activate();
        TgaTexture::DrawQuad(0.5f, 0.9f, 0.25f, 0.0625f, 0.0f);
    }


    if(highlight) glColor3f(1.0f, 0.75f, 0.75f);
    else glColor3f(1.0f, 1.0f, 1.0f);


    if(paused)
    {
        start.Activate();
        TgaTexture::DrawQuad(x, y, sizeX, sizeY, 0.0f);
    }
    else if(over)
    {
        playAgain.Activate();
        TgaTexture::DrawQuad(x, y, sizeX, sizeY, 0.0f);
    }

}


void GUI::HandleMouseMove(float x1, float y1)
{
    highlight = false;
    
    float left = x - sizeX;
    float right = x + sizeX;
    float top = y + sizeY;
    float bottom = y - sizeY;

    if(x1 < left) return;
    if(y1 < bottom) return;
    if(x1 > right) return;
    if(y1 > top) return;

    highlight = true;
}
