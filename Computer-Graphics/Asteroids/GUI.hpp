//
//  GUI.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>

# include "Utils.hpp"
# include "TgaTexture.hpp"

class GUI
{
    float x, y, sizeX, sizeY;

    TgaTexture start;
    TgaTexture gameOver;
    TgaTexture playAgain;

    bool active;

    EventHandler onClick;

public:

    GUI();

    void Activate();

    void Init(float x1, float y1, float sizeX1, float sizeY1, EventHandler function);

    void HandleMouseClick(float x1, float y1);

    void HandleMouseMove(float x1, float y1);

    void Draw(bool paused, bool gameOver);
};

#endif /* GUI_hpp */
