#include "Score.h"
#include <iostream>
#include "raylib.h"

void Score::addPoints(int value)
{
    points += value; 
}

void Score::draw(int x, int y, int fontSize, Color color) const
{
    int textWidth = MeasureText(TextFormat("Score: %d", points), fontSize);
    DrawText(TextFormat("Score: %d", points), (1000 - textWidth) / 2, 10, fontSize, color);
}

