//
//  Utils.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

# include <random>

#include "glPlatform.h"
#include "Utils.hpp"

float GetRandomValue(float min, float max)
{
    int number = std::rand();
    float value = float(number) / float(RAND_MAX);

    return min + value*(max-min);
}

int GetRandom(int limit)
{
    return rand() % limit;
}


float TriangleWave(float time, float maxTime, float min, float max)
{
    float halfTime = maxTime / 2.0f;

    float p = 1.0f - (fabs(halfTime - time)/halfTime);

    return min + p*(max - min);
}


void SetColor(int color)
{
    float colors[6][3] =
    {
        {0.75f, 0.25f, 0.25f},
        {0.25f, 0.75f, 0.25f},
        {0.75f, 0.75f, 0.25f},
        {0.25f, 0.75f, 0.75f},
        {0.75f, 0.25f, 0.75f},
        {0.75f, 0.75f, 0.75f},
    };

    if(color >= 0 && color <= 5)
        glColor3f(colors[color][0], colors[color][1], colors[color][2]);
    else
        glColor3f(0.125f, 0.125f, 0.125f);
}


void DrawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void DisplayLines(float x, float y, float size, int mask)
{
    float x1 = x - size / 2.0f;
    float x2 = x + size / 2.0f;

    float y1 = y + size;
    float y2 = y - size;

    if(mask & 1) DrawLine(x1, y1, x2, y1);

    if(mask & 2) DrawLine(x1, y1, x1, y);

    if(mask & 4) DrawLine(x1, y, x2, y);

    if(mask & 8) DrawLine(x2, y1, x2, y);

    if(mask & 16) DrawLine(x1, y, x1, y2);

    if(mask & 32) DrawLine(x1, y2, x2, y2);

    if(mask & 64) DrawLine(x2, y, x2, y2);
}

void DisplayDigit(float x, float y, float size, int digit)
{
    /*
        aaaaaaaa
        b      d
        b      d
        b      d
        bccccccd
        e      g
        e      g
        e      g
        effffffg
    */

    int a = 1;
    int b = 2;
    int c = 4;
    int d = 8;
    int e = 16;
    int f = 32;
    int g = 64;

    int lines[10] =
    {
        a | b | 0 | d | e | f | g,
        0 | 0 | 0 | d | 0 | 0 | g,
        a | 0 | c | d | e | f | 0,
        a | 0 | c | d | 0 | f | g,
        0 | b | c | d | 0 | 0 | g,
        a | b | c | 0 | 0 | f | g,
        a | b | c | 0 | e | f | g,
        a | 0 | 0 | d | 0 | 0 | g,
        a | b | c | d | e | f | g,
        a | b | c | d | 0 | f | g,
    };

    DisplayLines(x, y, size, lines[digit]);
}

void DisplayNumber(float x, float y, float size, int number)
{
    glColor3f(1.0f, 0.25f, 0.25f);
    glDisable(GL_TEXTURE_2D);

    glLineWidth(2.0f);

    while(number)
    {
        DisplayDigit(x, y, size, number % 10);
        number /= 10;
        x -= size*1.5f;
    }

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
}
