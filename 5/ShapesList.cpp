#include "ShapesList.h"

ShapesList* ShapesList::pHead = nullptr;

ShapesList::ShapesList(const Figure2D* figurePtr, std::string shapeName)
{
    this->figurePtr = figurePtr;
    this->shapeName = shapeName;

    id = pHead ? pHead->id + 1 : 1;
    pNext = pHead;
    pHead = this;
}

void ShapesList::RemoveFromList(const Figure2D* figurePtr)
{
    ShapesList* pPrev = nullptr;
    ShapesList* pObj = pHead;

    while (pObj)
    {
        if (pObj->figurePtr == figurePtr)
        {
            if (pPrev)
            {
                pPrev->pNext = pObj->pNext;
                pObj = pPrev;
            }
            else
            {
                pHead = pObj->pNext;
                pObj = pHead;
                continue;
            }
        }

        pPrev = pObj;
        pObj = pObj->pNext;
    }
}

void ShapesList::PrintAllShapes()
{
    ShapesList* p = pHead;
    while (p)
    {
        std::cout << p->id << ") " << p->shapeName << std::endl;
        p = p->pNext;
    }
}