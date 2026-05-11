#pragma once
#include <iostream>
#include "raylib.h"

class Score
{
private:
    int points; // Iloœæ posiadanych podczas gry punktów
public:
    Score() : points(0) {}          // Konstruktor podaj¹cy pocz¹tkow¹ iloœæ punktów
    void reset() { points = 0; }    // Zeruje iloœæ punktów
    void addPoints(int value);      // Dodanie zebranego punktu do wyniku
    void draw(int x, int y, int fontSize, Color color) const;    // Rysuje na ekranie wynik
    int getPoints() const { return points; }                     // Getter iloœci punktów
};

