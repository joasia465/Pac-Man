#include <cmath> // Dla sqrtf i powf
#include "Point.h"
#include "Map.h"

Point::Point(float x, float y, float r, Color c) : position({ x, y }), radius(r), color(c) {}

void Point::draw(int offsetX, int offsetY) const
{

    DrawCircleV({ position.x + offsetX, position.y + offsetY }, radius, color);
}

bool Point::checkCollision(const Vector2& pos, float radius) const 
{
    float distance = sqrtf(powf(pos.x - position.x, 2.0f) + 
        powf(pos.y - position.y, 2.0f));
    return distance < (this->radius + radius);
}

//void Point::collectPoint(int x, int y, const Map& map)
//{
//    if (map.setGrid({y,x}) == 0) // Jeœli w tym miejscu siatki jest punkt
//    {
//        grid[y][x] = 2; // Zmieniamy pole na puste pole = 2
//        point.setIsBig(false);
//    }
//    else if (grid[y][x] == 4) // Jeœli w tym miejscu siatki jest mega punkt
//    {
//        grid[y][x] = 2;
//        point.setIsBig(true);
//    }
//
//
//}
