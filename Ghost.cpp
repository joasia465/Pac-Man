#include "raylib.h"
#include "Game.h"
#include "Map.h"
#include "Ghost.h"


void Ghost::move(const Map& map, int currentDirection)
{
	setGoing(map);

    // Aktualna pozycja w kafelkach
    int tileX = static_cast<int>(position.x / map.getcellSize());
    int tileY = static_cast<int>(position.y / map.getcellSize());

    // Oblicz œrodek bie¿¹cego kafelka
    int centerX = static_cast<int>(tileX * map.getcellSize() + map.getcellSize() / 2);
    int centerY = static_cast<int>(tileY * map.getcellSize() + map.getcellSize() / 2);

	// Jeœli duch nie jest na œrodku kafelka, dokoñcz ruch w aktualnym kierunku
	if (abs(position.x - centerX) >= speed || abs(position.y - centerY) >= speed )	// abs - wartoœæ bezwzglêdna	
    {																				//position.x - centerX - ró¿nica miêdzy pozycj¹ ducha a œrodkiem kafelka
		switch (currentDirection) 
		{
		case 0: position.y -= speed; break; // Góra
		case 1: position.y += speed; break; // Dó³
		case 2: position.x -= speed; break; // Lewo
		case 3: position.x += speed; break; // Prawo
		}
		return; // Duch jeszcze siê przesuwa, wiêc nie zmieniaj kierunku
    }

	// Wybierz nowy kierunek losowy
	if (getHowManyWalls(map) >= 1 && getGoing() == false) // Jeœli duch ma 1 œcianê wokó³ niego, to idŸ losowo
	{
		int direction;
		do 
		{
			direction = GetRandomValue(0, 3);
		} while (map.isWall(tileX + (direction == 3) - (direction == 2),
							tileY + (direction == 1) - (direction == 0)));
		setCurrentDirection(direction);
		setGoing(map);
	}

	// kontynuuj ruch w aktualnym kierunku
	switch (currentDirection) 
	{
	case 0: if (!map.isWall(tileX, tileY - 1)) position.y -= speed; break; // Góra
	case 1: if (!map.isWall(tileX, tileY + 1)) position.y += speed; break; // Dó³
	case 2: if (!map.isWall(tileX - 1, tileY)) position.x -= speed; break; // Lewo
	case 3: if (!map.isWall(tileX + 1, tileY)) position.x += speed; break; // Prawo
	}

}

void Ghost::draw(int offsetX, int offsetY, const Map& map, Color color) const
{
    DrawCircleV({ position.x + offsetX, position.y + offsetY }, static_cast<int>(map.getcellSize()/2) , color); // G³ówne cia³o jako kó³ko
    // bia³e oczy
    DrawCircle(static_cast<int>(position.x + offsetX - 5.0f), static_cast<int>(position.y + offsetY - 5.0f), 5, WHITE); // Lewe oko
    DrawCircle(static_cast<int>(position.x + offsetX + 5.0f), static_cast<int>(position.y + offsetY - 5.0f), 5, WHITE); // Prawe oko
    // czarne oczy
    DrawCircle(static_cast<int>(position.x + offsetX - 5.0f), static_cast<int>(position.y + offsetY - 2.0f), 2, BLACK); // Lewe oko
    DrawCircle(static_cast<int>(position.x + offsetX + 5.0f), static_cast<int>(position.y + offsetY - 2.0f), 2, BLACK); // Prawe oko

}

int Ghost::getHowManyWalls(const Map& map)
{
	HowManyWalls = 0;
	int tileX = static_cast<int>(position.x / map.getcellSize());
	int tileY = static_cast<int>(position.y / map.getcellSize());

	if (map.isWall(tileX, tileY - 1)) HowManyWalls++; 
	if (map.isWall(tileX, tileY + 1)) HowManyWalls++; 
	if (map.isWall(tileX - 1, tileY)) HowManyWalls++; 
	if (map.isWall(tileX + 1, tileY)) HowManyWalls++;

	return HowManyWalls;
}

void Ghost::setGoing(const Map& map)
{
	if (getIsWallInfront(map) == true)
	{
		isGoing = false;
	}
	if (getIsWallInfront(map) == false)
	{
		isGoing = true;
	}
}

bool Ghost::getIsWallInfront(const Map& map)
{
	// Aktualna pozycja w kafelkach
	int tileX = static_cast<int>(position.x / map.getcellSize());
	int tileY = static_cast<int>(position.y / map.getcellSize());

	switch (getCurrentDirection())
	{
	case 0: if (map.isWall(tileX, tileY - 1)) return true; break; // Góra
	case 1: if (map.isWall(tileX, tileY + 1)) return true; break; // Dó³
	case 2: if (map.isWall(tileX - 1, tileY)) return true; break; // Lewo
	case 3: if (map.isWall(tileX + 1, tileY)) return true; break; // Prawo
	default: return false;
	}
}

Color Ghost::setColor(int ghostcolor)
{
	switch (ghostcolor)
	{
	case 0: return RED; break;
	case 1: return SKYBLUE ; break;
	case 2: return PINK; break;
	case 3: return YELLOW; break;
	case 4: return BLUE; break;
	default: return WHITE; break;
	}
}
