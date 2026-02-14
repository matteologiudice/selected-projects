//
//  TgaTexture.hpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#ifndef TgaTexture_hpp
#define TgaTexture_hpp

#include <stdio.h>
#include <stdlib.h>

#include "glPlatform.h"

struct Point
{
    float x,y;
};


class TgaTexture
{
    GLuint m_TextureHandle;
    unsigned char *m_pPixelBuffer;

    GLenum m_iBpp;  //bytes per pixel

    

    static void Vertex(float x, float y, float dx, float dy, float theta);


public:
    int Width;
    int Height;

    TgaTexture();
    ~TgaTexture();

    bool Init(const char *fileName);
    void Activate();
    void Destroy();
    static void DrawQuad(float x, float y, float sizeX, float sizeY, float theta = 0.0f);
};

#endif /* TgaTexture_hpp */
