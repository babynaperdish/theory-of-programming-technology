#pragma once

#include "adopt.h"

class Figure2D
{
protected:
    int x0; 
    int y0;
    byte r;
    byte g;
    byte b;

    virtual void hide() const = 0;
    virtual void draw() = 0;

public:
    Figure2D(int x, int y, byte r, byte g, byte b);

    virtual void print() const;
    void move(int dx, int dy);
    virtual void remove();
};