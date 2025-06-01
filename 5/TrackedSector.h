#pragma once

#include "Sector2D.h"
#include "TrackedLine.h"
#include "TrackedArc.h"
#include "ShapesList.h"

class TrackedLineFirst : public TrackedLine
{
public:
    TrackedLineFirst(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0, std::string name = "Первая линия сектора");
};

class TrackedLineSecond : public TrackedLine
{
public:
    TrackedLineSecond(int x1, int y1, int x2, int y2, byte r, byte g, byte b, int x0 = 0, int y0 = 0, std::string name = "Вторая линия сектора");
};

class TrackedSector : public TrackedLineFirst, public TrackedLineSecond, public TrackedArc, public Sector2D, public ShapesList
{
protected:
    void hide() const override;

public:
    TrackedSector(int x, int y, int rad, int startAngle, int endAngle, byte r, byte g, byte b, int x0 = 0, int y0 = 0, std::string name = "Составной сектор");

    void draw() override;
    void print() const override;
    void remove() override;
};