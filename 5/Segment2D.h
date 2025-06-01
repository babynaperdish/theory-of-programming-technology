#pragma once

#include "Line2D.h"
#include "Arc2D.h"
#include "adopt.h"


class Line : public Line2D
{
public:
    Line(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0);
};

class Segment2D : public Arc2D, public Line2D
{
protected:
    void hide() const override;

public:
    Segment2D(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0 = 0, int y0 = 0);

    void draw() override;
    void print() const override;
};
const float PI_CONST = 3.14159;