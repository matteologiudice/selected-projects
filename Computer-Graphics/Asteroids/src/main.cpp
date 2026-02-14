//
//  main.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include <iostream>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
#include <cstdint>
#include <chrono>


#include "glPlatform.h"
# include "GUI.hpp"
# include "Rocket.hpp"
# include "SpaceShip.hpp"
# include "AsteroidManager.hpp"


GUI                    gui;
Rocket                rocket;
SpaceShip            spaceShip;
AsteroidManager        asteroids;

        // unsigned int
static long long    lastTime = 0;
static bool            paused = true;

int                    windowWidth = 800;
int                    windowHeight = 800;


void OnWindowResize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    windowWidth = width;
    windowHeight = height;
}


void Restart()
{
    rocket.Relocate(0.0f, 0.0f);
    asteroids.Destroy();
    asteroids.Init();
    spaceShip.SetShooting(true);
    spaceShip.Reset();
    
    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

    paused = false;
            
}


void OnKeyPress(unsigned char key, int x, int y)
{
# define ESC_Key    27
# define ENTER_key    13

    switch (key)
    {
        case ESC_Key:
            paused = !paused;
        break;

        case 'w':
            rocket.Progress();
            break;
           
        /*
        case 'a':
            rocket.RotateRight(0.3f);
            break;
            
        case 'd':
            rocket.RotateLeft(0.3f);
            break;
         */
            
        case ' ':
            rocket.Shoot();
            break;
            
        case ENTER_key:
            Restart();
            break;
    }
}

void OnSpecialKeyPress(int key, int x, int y) 
{
    switch (key) 
    {
        case GLUT_KEY_UP:
            rocket.Progress();
            break;
    }
}



void Draw()
{
    
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    float deltaTime = float(now - lastTime)/1000.0f;
    lastTime = now;

    glClearColor(0.1f, 0.1f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    

    rocket.Update(deltaTime, &asteroids, &spaceShip);

    asteroids.Draw();
    spaceShip.Draw();
    rocket.Draw();
    gui.Draw(paused, rocket.gameOver);


    glutSwapBuffers();

}


void OnMouseMove(int mouseX, int mouseY)
{
    //Convert mouseX, mouseY into (x, y)
    //where x and y values are between -1 and +1
    float x = (float) (2.0f*mouseX)/(float)windowWidth - 1.0f;
    float y = 1.0f - (float)(2.0f*mouseY)/(float)windowHeight;

    if(rocket.gameOver || paused)
    {
        gui.HandleMouseMove(x, y);
    }
    else
    {

        rocket.OnMouseMove(x, y);
    }

    glutPostRedisplay();
}


void OnMouseClick(int button, int state, int x, int y)
{
    
    float x1 = (float) (2.0f*x)/(float)windowWidth - 1.0f;
    float y1 = 1.0f - (float)(2.0f*y)/(float)windowHeight;
    if(rocket.gameOver || paused)
    {
        gui.HandleMouseClick(x1, y1);
    }
    else
    {
        if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
        {
            rocket.Shoot();
        }
        if(state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
        {
            rocket.Relocate(x1, y1);
            spaceShip.SetShooting(false);
            spaceShip.Reset();
        }
    }

    glutPostRedisplay();
}




int main(int argc, char** argv)
{
    const int left = 0;
    const int top = 0;

    const char* windowTitle = "Asteorids";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(left, top);
    glutCreateWindow(windowTitle);
    
    glutDisplayFunc(Draw);
    glutReshapeFunc(OnWindowResize);
    glutKeyboardFunc(OnKeyPress);
    glutSpecialFunc(OnSpecialKeyPress);
    glutMouseFunc(OnMouseClick);
    glutIdleFunc(Draw);
    glutPassiveMotionFunc(OnMouseMove);

    gui.Init(0.0f, 0.0f, 0.25f, 0.125f, Restart);
    rocket.Init();
    asteroids.Init();
    spaceShip.Init();
    spaceShip.SetShooting(false);

    lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    glutMainLoop();

    return 0;
}

