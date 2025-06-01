#pragma once

#include "Figure2D.h"
#include "adopt.h"

class Arc2D : public virtual Figure2D
{
protected:
    int x;
    int y;
    int rad;
    int startAngle;
    int endAngle;

    void hide() const override;
public:
    Arc2D(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0 = 0, int y0 = 0);

    void draw() override;
    void print() const override;
};