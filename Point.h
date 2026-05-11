#pragma once
#include <iostream>
#include "raylib.h"
#include "Map.h"

class Point
{
private:
    Vector2 position;  // Pozycja punktu na planszy (x,y)
    float radius;      // Promieñ punktu
    Color color;       // Kolor punktu
	bool isBig;        // Flag czy punkt jest du¿ym punktem
public:
    Point(float x, float y, float r, Color c);      //Konstruktor
    void draw(int offsetX, int offsetY) const;      // Rysowanie punktu 
    bool checkCollision(const Vector2& playerPosition, float playerRadius) const;   // Flaga czy kolizja z graczem
    Vector2 getPosition() const { return position; }    // Getter dla pozycji punktu
	bool getIsBig() const { return isBig; }             // Getter dla isBig
	void setIsBig(bool new_isBig) { isBig = new_isBig; }    // Setter dla isBig
};
