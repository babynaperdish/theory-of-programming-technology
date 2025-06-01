#include <iostream>
#include "Arc2D.h"
#include "adopt.h"

void Arc2D::hide() const
{
    draw_arc(
        x0 + x, y0 + y, rad, startAngle, endAngle,
        0, 0, 0
    );
}

Arc2D::Arc2D(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0, int y0)
    : Figure2D(x0, y0, r, g, b)
{
    this->x = x;
    this->y = y;
    this->rad = rad;
    this->startAngle = startAngle;
    this->endAngle = endAngle;

    draw();
}

void Arc2D::draw()
{
    draw_arc(
        x0 + x, y0 + y, rad, startAngle, endAngle,
        r, g, b
    );
}

void Arc2D::print() const
{
    std::cout << "Arc2D center: (" << x << ", " << y << "), radius: " << rad << std::endl;
}