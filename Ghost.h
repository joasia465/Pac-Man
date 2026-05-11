#pragma once
#include <iostream>
#include "raylib.h"
#include "Map.h"
#include "Game.h"

class Ghost
{
private:
    Vector2 position; // Pozycja ducha (x,y)
    Color color;      // Kolor ducha
    float speed;      // Prêdkoœæ ducha
    int currentDirection = GetRandomValue(0, 3); // Ustawia obecny kierunek w losowy sposób
    bool isGoing = false;   // Flaga czy siê porusza
    bool isWallInfront;     // Flaga czy duch ma œcianê przed sob¹
    int HowManyWalls;       // Iloœæ œcian dooko³a ducha 
public:
    Ghost(float startX, float startY, Color c) : position({ startX, startY }), color(c), speed(2.0f), HowManyWalls(0), isWallInfront(0) {}  // Konstruktor z domyœlnymi waroœciami
    void move(const Map& map, int currentDirection);                        // Poruszanie siê ducha
    void draw(int offsetX, int offsetY, const Map& map, Color color) const; // Rysowanie ducha
    Vector2 getPosition() const { return position; }    // Getter pozycji ducha (x,y)
    Color setColor(int ghostcolor);                     // Setter koloru ducha

    void setCurrentDirection(int currentDirection) { this->currentDirection = currentDirection; }   // Setter kierunku poruszania siê ducha
	int getCurrentDirection() { return currentDirection; }                                          // Getter aktualnego kierunku poruszania siê

    void setGoing(const Map& map);          // Setter czy duch siê porusza
	bool getGoing() { return isGoing; }     // Getter czy duch siê porusza

    bool getIsWallInfront(const Map& map);  // Getter czy przed duchem jest œciana
    int getHowManyWalls(const Map& map);    // Getter ile œcian jest wokó³ ducha
};

