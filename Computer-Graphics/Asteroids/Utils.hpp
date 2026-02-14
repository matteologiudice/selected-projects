//
//  Utils.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>

typedef void (*EventHandler)(void);

float TriangleWave(float time, float maxTime, float min, float max);

float GetRandomValue(float min, float max);

int GetRandom(int limit);

void SetColor(int color);

void DisplayNumber(float x, float y, float size, int number);

#endif /* Utils_hpp */
