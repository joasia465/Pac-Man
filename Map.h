#pragma once
#include <iostream>
#include "raylib.h"
#include "Point.h"
#include <vector>

using namespace std;

class Map
{
private:
	vector<vector<int>> grid;	// Tablica 2D przechowuj¹ca elementy planszy (0 - puste, 1 - œciana, 2 - punkt, 3 - duch, 4 - du¿y punkt, 5 - pusta przestrzeñ)
	int cellSize;				// Rozmiar kafelków
	int width, height;			// Wymiary planszy

public:
	Map(int mapWidth, int mapHeight, int tileSize, int selectedMap);	// Konstruktor z parametrami
	
	void draw(int x, int y) const;		// Rysuje mapê
	bool isWall(int x, int y) const;	// Flaga czy dane pole to œciana

	// Gettery
	const vector<vector<int>>& getGrid() const { return grid; }		// Zwraca tablicê 2D z cyframi
	int getcellSize() const { return cellSize; }					// Zwraca rozmiar kafelka
	int getWidth() const { return width; }							// Zwraca szerokoœæ mapy
	int getHeight() const { return height; }						// Zwraca wysokoœæ mapy
	
	// Settery
	void setGrid(vector<vector<int>> new_grid) { this->grid = new_grid; }	// Ustawia now¹ tablicê 2D
	void setcellSize(int new_cellSize) { this->cellSize = new_cellSize; }	// Ustawia now¹ wielkoœæ kafelka
	void setWidth(int new_width) { this->width = new_width; }				// Ustawia now¹ szerokoœæ
	void setHeight(int new_height) { this->height = new_height; }			// Ustawia now¹ wysokoœæ
};

