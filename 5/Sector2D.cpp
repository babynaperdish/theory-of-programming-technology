#include <iostream>
#include <cmath>
#include "Sector2D.h"
#include "adopt.h"

void Sector2D::hide() const
{
    Arc2D::hide();
    FirstLine::hide();
    SecondLine::hide();
}

Sector2D::Sector2D(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0, int y0) :
    Arc2D(x, y, rad, startAngle, endAngle, r, g, b, x0, y0),
    FirstLine(
        x, y,
        rad* cos(startAngle* PI_CONST / 180) + x,
        rad* sin(startAngle* PI_CONST / 180) + y,
        r, g, b,
        x0, y0
    ),
    SecondLine(
        x, y,
        rad* cos(endAngle* PI_CONST / 180) + x,
        rad* sin(endAngle* PI_CONST / 180) + y,
        r, g, b,
        x0, y0
    ),
    Figure2D(x0, y0, r, g, b)
{
}

void Sector2D::draw()
{
    Arc2D::draw();
    FirstLine::draw();
    SecondLine::draw();
}

void Sector2D::print() const
{
    std::cout << "Sector2D center: (" << x << ", " << y << "), radius: " << rad << std::endl;
}

FirstLine::FirstLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0)
    : Line2D(x1, y1, x2, y2, r, g, b, x0, y0), Figure2D(x0, y0, r, g, b) {
}

SecondLine::SecondLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0)
    : Line2D(x1, y1, x2, y2, r, g, b, x0, y0), Figure2D(x0, y0, r, g, b) {
}