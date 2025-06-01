#pragma once

#include <iostream>
#include "Arc2D.h"
#include "ShapesList.h"

class TrackedArc : public Arc2D, public ShapesList
{
public:
    TrackedArc(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0 = 0, int y0 = 0, std::string name = "Арка");
    void remove() override;
};