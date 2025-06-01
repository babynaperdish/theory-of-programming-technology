#pragma once

#include <iostream>
#include "Figure2D.h"
#include "adopt.h"

class Line2D : public virtual Figure2D
{
protected:
    int x1;
    int y1;
    int x2;
    int y2;

    void hide() const override;

public:
    Line2D(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0);

    void draw() override;
    void print() const override;
};