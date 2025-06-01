#pragma once

#include "Line2D.h"
#include "Arc2D.h"
#include "adopt.h"

class FirstLine : public Line2D
{
public:
    FirstLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0);
};

class SecondLine : public Line2D
{
public:
    SecondLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0);
};

   const float PI_CONST = 3.14159;

class Sector2D : public Arc2D, public FirstLine, public SecondLine
{
protected:
    void hide() const override;

public:
    Sector2D(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0 = 0, int y0 = 0);

    void draw() override;
    void print() const override;
};