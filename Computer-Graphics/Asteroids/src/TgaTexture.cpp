//
//  TgaTexture.cpp
//  Prog03
//
//  Created by Matteo Lo Giudice on 25/10/23.
//

#include <math.h>

#include "TgaTexture.hpp"

TgaTexture::TgaTexture() : m_TextureHandle(0),
                           m_pPixelBuffer(0),
                           Width(0), Height(0)
{
}


TgaTexture::~TgaTexture()
{
    Destroy();
}



void TgaTexture::Destroy()
{
    if(m_pPixelBuffer)
    {
        delete m_pPixelBuffer;
        m_pPixelBuffer = 0;
    }

    Width = 0;
    Height = 0;
}




//This function reads the pixel data from an uncompressed image.
bool TgaTexture::Init(const char* fileName)
{
    FILE *fp = 0;
    unsigned char fileHeader[18];

    fp = fopen(fileName, "rb");
    if(!fp)
    {
        printf("The mentioned image....%s is not found\n", fileName);
        return false;
    }

    fread(fileHeader, 18, 1, fp);
    if(fileHeader[2] != 2)
    {
        printf("Sorry.. this kind of files are not supported\n");
        fclose(fp);
        return false;
    }
    Width = fileHeader[13] << 8 | fileHeader[12];
    Height = fileHeader[15] << 8 | fileHeader[14];

    //bpp stands for bytes per pixel
    // bpp = 3 means RGB, bpp = 4 means RGBA (red, green, blue, alpha)
    m_iBpp = fileHeader[16] >> 3;
    int dataSize = Width * Height * m_iBpp;
    
    m_pPixelBuffer = new unsigned char[dataSize];
    fread(m_pPixelBuffer, dataSize, 1, fp);
    fclose(fp);

    unsigned char *temp = m_pPixelBuffer;
    //Tga files store the pixel in bgr/bgra order.
    //We should change them into rgb/rgba order
    for(int i = 0; i < Height; i++)
    {
        for(int j = 0; j < Width; j++)
        {
            unsigned char b = temp[0];
            unsigned char r = temp[2];
            temp[0] = r;
            temp[2] = b;

            temp += m_iBpp;
        }
    }

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &m_TextureHandle);
    glBindTexture(GL_TEXTURE_2D, m_TextureHandle);
    GLenum format = (m_iBpp == 4)?GL_RGBA:GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, Width, Height, 0, format, GL_UNSIGNED_BYTE, m_pPixelBuffer);

    return true;
}


void TgaTexture::Activate()
{
    glBindTexture(GL_TEXTURE_2D, m_TextureHandle);

    // make the texture repeat in the u and v texture directions
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    // linearly filter the texture when it needs to be magnified
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // linearly filter textures into the distance
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}




void TgaTexture::Vertex(float x, float y, float dx, float dy, float theta)
{
    float x1, y1;

    x1 = dx + x*cos(theta) - y*sin(theta);
    y1 = dy + x*sin(theta) + y*cos(theta);

    glVertex2f(x1, y1);
}



void TgaTexture::DrawQuad(float x, float y, float sizeX, float sizeY, float theta)
{
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0.0f, 0.0f);
    Vertex(-sizeX, -sizeY, x, y, theta);
    
    glTexCoord2f(1.0f, 0.0f);
    Vertex( sizeX, -sizeY, x, y, theta);
    
    glTexCoord2f(0.0f, 1.0f);
    Vertex(-sizeX,  sizeY, x, y, theta);

    glTexCoord2f(1.0f, 1.0f);
    Vertex( sizeX,  sizeY, x, y, theta);
    glEnd();
}

