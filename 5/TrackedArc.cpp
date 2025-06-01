#include "TrackedArc.h"

TrackedArc::TrackedArc(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0, int y0, std::string name)
    : Arc2D(x, y, rad, startAngle, endAngle, r, g, b, x0, y0),
    Figure2D(x0, y0, r, g, b),
    ShapesList(this, name) {
}

void TrackedArc::remove()
{
    ShapesList::RemoveFromList(this);
    Figure2D::remove();
}