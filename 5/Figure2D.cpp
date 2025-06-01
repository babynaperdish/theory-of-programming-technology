#include <iostream>
#include "Figure2D.h"

Figure2D::Figure2D(int x, int y, byte r, byte g, byte b)
{
    this->x0 = x;
    this->y0 = y;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Figure2D::move(int dx, int dy)
{
    hide();
    x0 += dx;
    y0 += dy;
    draw();
}

void Figure2D::print() const
{
    std::cout << "Base Figure2D at: (" << x0 << ", " << y0 << ")" << std::endl;
}

void Figure2D::remove()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    draw();
}