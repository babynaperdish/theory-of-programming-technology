#include "TrackedLine.h"

TrackedLine::TrackedLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0, std::string name)
    : Line2D(x1, y1, x2, y2, r, g, b, x0, y0),
    Figure2D(x0, y0, r, g, b),
    ShapesList(this, name) {
}

void TrackedLine::remove()
{
    ShapesList::RemoveFromList(this);
    Figure2D::remove();
}