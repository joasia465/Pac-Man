#include <iostream>
#include <cmath> // Dla sqrtf i powf
#include "raylib.h"
#include "PacMan.h"
#include "Map.h"

using namespace std;

PacMan::PacMan(float startX, float startY, float r, Color c) : 
    position({ startX, startY }), radius(r), color(c),
    mouthAngle(45.0f), mouthOpening(true), startAngle(0), endAngle(0), 
    currentDirection(RIGHT), speed(2.0f) {}

void PacMan::move(const Map& map, Direction dir)
{
    // Pozycja Pac-Mana w kafelkach
    int tileX = static_cast<int>(position.x / map.getcellSize());
    int tileY = static_cast<int>(position.y / map.getcellSize());

    // Oblicz œrodek bie¿¹cego kafelka
    int centerX = static_cast<int>( tileX * map.getcellSize() + map.getcellSize() / 2 );
    int centerY = static_cast<int>( tileY * map.getcellSize() + map.getcellSize() / 2 );

    // Jeœli Pac-Man nie jest na œrodku kafelka, dokoñcz ruch w aktualnym kierunku
    if (abs(position.x - centerX) > 1.0f || abs(position.y - centerY) > 1.0f)
    {
        switch (currentDirection) 
        {
        case Direction::UP: position.y -= speed; break;
        case Direction::DOWN: position.y += speed; break;
        case Direction::LEFT: position.x -= speed; break;
        case Direction::RIGHT: position.x += speed; break;
        }
        return; // Pac-Man jeszcze siê przesuwa, wiêc nie zmieniaj kierunku
    }

    // Wyrównaj Pac-Mana do œrodka kratki
    position.x = static_cast<int>(centerX);
    position.y = static_cast<int>(centerY);

    // Zmiana kierunku na podstawie wciœniêtego klawisza (tylko gdy Pac-Man jest na œrodku kratki)
    if (IsKeyDown(KEY_W) && !map.isWall(tileX, tileY - 1)) currentDirection = Direction::UP;
    if (IsKeyDown(KEY_S) && !map.isWall(tileX, tileY + 1)) currentDirection = Direction::DOWN;
    if (IsKeyDown(KEY_A) && !map.isWall(tileX - 1, tileY)) currentDirection = Direction::LEFT;
    if (IsKeyDown(KEY_D) && !map.isWall(tileX + 1, tileY)) currentDirection = Direction::RIGHT;

    // Przesuniêcie Pac-Mana do kolejnego kafelka w wybranym kierunku (jeœli nie ma œciany)
    switch (currentDirection) 
    {
    case Direction::UP:
        if (!map.isWall(tileX, tileY - 1)) position.y -= speed;
        break;
    case Direction::DOWN:
        if (!map.isWall(tileX, tileY + 1)) position.y += speed;
        break;
    case Direction::LEFT:
        if (!map.isWall(tileX - 1, tileY)) position.x -= speed;
        break;
    case Direction::RIGHT:
        if (!map.isWall(tileX + 1, tileY)) position.x += speed;
        break;
    }
}

void PacMan::updateMouth()
{
    float mouthSpeed = speed * 0.5f; // Im szybciej Pac-Man siê porusza, tym szybciej ruszaj¹ siê usta

    // Animacja otwierania i zamykania buzi
    if (mouthOpening) 
    {
        mouthAngle -= mouthSpeed;
        if (mouthAngle <= 45.0f) mouthOpening = false;
    }
    else 
    {
        mouthAngle += mouthSpeed;
        if (mouthAngle >= 75.0f) mouthOpening = true;
    }
}

void PacMan::draw(int offsetX, int offsetY, Direction dir)
{

    // Ustawienie k¹ta w zale¿noœci od aktualnego kierunku
    switch (dir)   
    {
    case Direction::UP:
    {
        startAngle = 0.0f;
        endAngle = 180.0f;
        break;
    }
    case Direction::DOWN:
    {
    startAngle = 180.0f;
    endAngle = 360.0f;
	break;
	}
    case Direction::LEFT:
    {
        startAngle = -90.0f;
        endAngle = 90.0f;
        break;
    }
    case Direction::RIGHT:
    {
        startAngle = 90.0f;
        endAngle = 270.0f;
        break;
    }

    }



    // Rysowanie sektora (Pac-Mana)
    DrawCircleSector({ position.x + offsetX, position.y + offsetY }, radius, startAngle - mouthAngle, endAngle + mouthAngle, 100, YELLOW);
}

Vector2 PacMan::getPosition() const
{
    return position;
}

float PacMan::getRadius() const
{
    return radius;
}

bool PacMan::checkCollision(const Vector2& otherPosition, float otherRadius)
{
    float distance = sqrtf(powf(otherPosition.x - position.x, 2.0f) + powf(otherPosition.y - position.y, 2.0f));
    return distance < (radius + otherRadius); // Kolizja, jeœli odleg³oœæ jest mniejsza ni¿ suma promieni      

                                  
}

