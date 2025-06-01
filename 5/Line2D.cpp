#include <iostream>
#include "Line2D.h"
#include "adopt.h"

void Line2D::hide() const
{
    draw_line(x0 + x1, y0 + y1, x0 + x2, y0 + y2, 0, 0, 0);
}

Line2D::Line2D(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0)
    : Figure2D(x0, y0, r, g, b)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;

    draw();
}

void Line2D::draw()
{
    draw_line(x0 + x1, y0 + y1, x0 + x2, y0 + y2, r, g, b);
}

void Line2D::print() const
{
    std::cout << "Line2D from: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
}