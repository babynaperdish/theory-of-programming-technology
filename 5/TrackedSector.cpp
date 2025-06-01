#include <cmath>
#include "TrackedSector.h"

void TrackedSector::hide() const
{
    Sector2D::hide();
}

TrackedSector::TrackedSector(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0, int y0, std::string name)
    : TrackedLineFirst(
        x, y,
        rad* cos(startAngle* PI_CONST / 180) + x,
        rad* sin(startAngle* PI_CONST / 180) + y,
        r, g, b,
        x0, y0,
        "Первая линия сектора"
    ),
    TrackedLineSecond(
        x, y,
        rad* cos(endAngle* PI_CONST / 180) + x,
        rad* sin(endAngle* PI_CONST / 180) + y,
        r, g, b,
        x0, y0,
        "Вторая линия сектора"
    ),
    TrackedArc(x, y, rad, startAngle, endAngle, r, g, b, x0, y0, "Дуга сектора"),
    Sector2D(x, y, rad, startAngle, endAngle, r, g, b, x0, y0),
    Figure2D(x0, y0, r, g, b),
    ShapesList(this, name) {
}

void TrackedSector::draw()
{
    Sector2D::draw();
}

void TrackedSector::print() const
{
    Sector2D::print();
}

void TrackedSector::remove()
{
    Figure2D::remove();
    ShapesList::RemoveFromList(this);
}

TrackedLineFirst::TrackedLineFirst(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0, std::string name)
    : TrackedLine(x1, y1, x2, y2, r, g, b, x0, y0, name), Figure2D(x0, y0, r, g, b) {
}

TrackedLineSecond::TrackedLineSecond(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0, int y0, std::string name)
    : TrackedLine(x1, y1, x2, y2, r, g, b, x0, y0, name), Figure2D(x0, y0, r, g, b) {
}