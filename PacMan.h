#pragma once
#include <iostream>
#include "raylib.h"
#include "Map.h"

class PacMan
{
private:
    Vector2 position;   // Pozycja Pac-Mana (x,y)
    float radius;       // Promieñ Pac-Mana
    float mouthAngle;   // K¹t otwarcia buzi
    float startAngle;   // K¹t pocz¹tkowy sektora (do rysowania otwarcia buzi)
    float endAngle;     // K¹t pocz¹tkowy sektora (do rysowania otwarcia buzi)
    Color color;        // Kolor Pac-Mana
    float speed;        // Prêdkoœæ Pac-Mana
    bool mouthOpening;  // Flaga okreœlaj¹ca, czy buzia siê otwiera
    enum Direction { UP, DOWN, LEFT, RIGHT };   // Kieruneki
    Direction currentDirection;                 // Obecny kierunek

public:
    PacMan(float startX, float startY, float r, Color c);                   // Konstruktor
    Direction getCurrentDirection() const { return currentDirection; }      // Getter kierunku
    void move(const Map& map, Direction dir);                               // Poruszanie siê gracza
    void updateMouth();                                                     // Aktualizuje otwarcie ust
    void draw(int offsetX, int offsetY, Direction dir);                     // Rysuje gracza
    Vector2 getPosition() const;                                            // Getter pozycji gracza (x,y)
    float getRadius() const;                                                // Getter promienia 
    bool checkCollision(const Vector2& otherPosition, float otherRadius);   // Flaga czy nast¹pi³a kolizja z innym objektem
};

