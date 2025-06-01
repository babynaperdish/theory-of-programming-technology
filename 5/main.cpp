#pragma once

#include <iostream>
#include <locale>
#include "TrackedLine.h"
#include "TrackedArc.h"
#include "TrackedSector.h"
#include "adopt.cpp"

typedef ShapesList FiguresList;

int main(int argc, char* argv[])
{
    std::setlocale(LC_ALL, "Russian");
    if (!init()) return 0;

    //// Создаем фигуры
    //Line2D line1(50, 50, 400, 600, 255, 0, 0);
    //Line2D line2(350, 50, 70, 450, 255, 0, 0);
    //Arc2D arc1(200, 200, 100, 360, 90, 255, 255, 0, 100, 100);
    //Sector2D sector1(200, 200, 120, 0, 90, 255, 255, 0, 100, 100);
    //Sector2D sector2(250, 250, 5, 0, 359, 255, 0, 0, 100, 100);
    //Sector2D sector3(280, 220, 5, 0, 359, 255, 0, 0, 100, 100);
    //Sector2D sector4(220, 280, 5, 0, 359, 255, 0, 0, 100, 100);


    //// Выводим информацию о фигурах
    //line1.print();
    //line2.print();
    //arc1.print();
    //sector1.print();

    //wait4mouse();

    //// Перемещаем каждую фигуру индивидуально
    //line1.move(100, 0);
    //line2.move(100, 0);
    //arc1.move(100, 0);
    //sector1.move(100, 0);
    //sector2.move(100, 0);
    //sector3.move(100, 0);
    //sector4.move(100, 0);

    //wait4mouse();

    //// Перемещаем  фигуры
    //line1.move(100, 0);
    //line2.move(100, 0);
    //arc1.move(100, 0);
    //sector1.move(100, 0);
    //sector2.move(100, 0);
    //sector3.move(100, 0);
    //sector4.move(100, 0);
    //wait4mouse();


    //// Удаляем сектор
    //sector2.remove();

    //wait4mouse();

    //// Удаляем сектор
    //sector4.remove();

    //wait4mouse();

    //// Удаляем сектор
    //sector3.remove();

    //wait4mouse();

    //// Удаляем сектор
    //sector1.remove();

    //wait4mouse();

    //// Удаляем дугу
    //arc1.remove();

    //wait4mouse();

    //// Перемещаем оставшиеся фигуры по вертикали
    //line1.move(0, -100);
    //line2.move(0, -100);

    //wait4mouse();

    //// Удаляем оставшиеся фигуры
    //line1.remove();
    //line2.remove();

    //// Создаем фигуры с отслеживанием
    //TrackedLine tline1(200, 50, 200, 300, 170, 0, 230);
    //TrackedLine tline2(50, 200, 300, 200, 170, 0, 230);
    //TrackedArc tarc1(200, 200, 150, 0, 359, 170, 90, 255);
    //TrackedSector tsector1(400, 200, 90, 0, 140, 0, 90, 255);

    //// Выводим список всех отслеживаемых фигур
    //FiguresList::PrintAllShapes();

    //wait4mouse();

    //// Перемещаем все отслеживаемые фигуры
    //tline1.move(100, 100);
    //tline2.move(100, 100);
    //tarc1.move(100, 100);
    //tsector1.move(100, 100);

    //wait4mouse();

    //std::cout << "-------------------------------------" << std::endl;

    //// Удаляем отслеживаемые фигуры
    //tsector1.remove();
    //tline2.remove();

    //// Выводим обновленный список отслеживаемых фигур
    //FiguresList::PrintAllShapes();

    //// dynamic_cast

    //wait4mouse();
    //leave();

    TrackedLine tline3(50, 50, 400, 600, 255, 0, 0);
    TrackedLine* tl = &tline3;
    Figure2D* figure1 = dynamic_cast<Figure2D*>(tl);
    ShapesList* shl = dynamic_cast<ShapesList*>(figure1);
    TrackedLine& tll = tline3;
    Figure2D& figure2 = dynamic_cast<Figure2D&>(tll);
    //ShapesList& shl = dynamic_cast<ShapesList&>(figure2);//-

    return 0;
}  