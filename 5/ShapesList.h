#pragma once

#include <iostream>
#include <string>
#include "Figure2D.h"

class ShapesList
{
private:
    int id;
    ShapesList* pNext;
    static ShapesList* pHead;
    const Figure2D* figurePtr;
    std::string shapeName;

protected:
    ShapesList(const Figure2D* figurePtr, std::string shapeName);
    static void RemoveFromList(const Figure2D* figurePtr);

public:
    static void PrintAllShapes();
};