#pragma once
#include <iostream>
#include "raylib.h"
#include "Map.h"
#include "Ghost.h"
#include "Point.h" 
#include "Score.h"
#include "PacMan.h"

class Game
{
private:
    Map map;
    int selectedMap;
    PacMan player;
    vector<Ghost> ghosts;
    vector<Point> points;
    Score score;
    bool isGameOver = false;
    bool isMenu = true;

    int screenWidth;
	int screenHeight;

public:
    Game();                     // Ustawia podstawowe wartoœci (np. ¿e gra trwa), podaje wartoœci wyjœciowe dla Pac-Mana 
    void Menu();                // Rysuje menu i daje opcje wyboru gry
    void run();                 // Tworzy okno i aktualizuje grê
    void update();              // Aktualizuje pozycje i kolizje obiektów
	void initializeObjects();   // Tworzy punkty i duchy
    void draw();                // Rysuje grê
    void reset();               // Wraca do ustawieñ pierwotnych
    int getSelectedMap() const { return selectedMap; }  // Getter która flaga zosta³a wybrana
	bool getisMenu() const { return isMenu; }   // Flaga czy menu ma siê wyœwietlaæ 

	int getScreenWidth() const { return screenWidth; }      // Getter szerokoœæ okna gry
	int getScreenHeight() const { return screenHeight; }    // Getter wysokoœæ okna gry
	void setScreenWidth(int new_width) { this->screenWidth = new_width; }       // Seter szerokoœci okna gry
	void setScreenHeight(int new_height) { this->screenHeight = new_height; }   // Setter wysokoœci okna gry
};

