#pragma once

#include <iostream>
#include "Line2D.h"
#include "ShapesList.h"

class TrackedLine : public Line2D, public ShapesList
{
public:
    TrackedLine(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0, std::string name = "Отрезок");
    void remove() override;
};