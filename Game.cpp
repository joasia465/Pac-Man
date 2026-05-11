#include <iostream>
#include <vector>
#include "raylib.h"
#include "Game.h"
#include "Map.h"
#include "Ghost.h"
#include "Point.h"
#include "Score.h"
#include "PacMan.h"

using namespace std;

Game::Game() : selectedMap(1), map(map.getWidth(), map.getHeight(), map.getcellSize(), selectedMap), score(), isGameOver(false), isMenu(true), 
                player(30 + 15, 30 + 15, 15, YELLOW)    // PacMan na pozycji (1, 1) z promieniem 15 i kolorem YELLOW, TODOOO wycentrowaæ
{
    initializeObjects();
}

void Game::Menu()
{
    isMenu = true;

    while (isMenu && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        int textWidth = MeasureText("Press 1 for Map 1", 20);
        DrawText("Press 1 for Map 1", (getScreenWidth() - textWidth) / 2, 300, 20, WHITE);

        textWidth = MeasureText("Press 2 for Map 2", 20);
        DrawText("Press 2 for Map 2", (getScreenWidth() - textWidth) / 2, 350, 20, WHITE);

		if (IsKeyPressed(KEY_ONE)) 
        {
			selectedMap = 1;
            map.setWidth(21);
			map.setHeight(22);
			map.setcellSize(30);
			map = Map(map.getWidth(), map.getHeight(), map.getcellSize(), selectedMap);
			initializeObjects();
			break;
		}
        if (IsKeyPressed(KEY_TWO))
        {
            selectedMap = 2;
            map.setWidth(21);
            map.setHeight(22);
            map.setcellSize(30);
            map = Map(map.getWidth(), map.getHeight(), map.getcellSize(), selectedMap);
            initializeObjects();
            break;
        }

        EndDrawing();
    }
}

void Game::run()
{
    setScreenWidth(1000);
	setScreenHeight(800);

    InitWindow(getScreenWidth(), getScreenHeight(), "Pac-Man Game");
    SetTargetFPS(60);

    // Menu wyboru mapy
    Menu();

    // Pêtla gry
    while (!WindowShouldClose()) {
        if (isGameOver) { if (IsKeyPressed(KEY_R)) { reset(); } }
        if (!isGameOver) { update(); }

        BeginDrawing();
        ClearBackground(BLACK);
        draw();
        EndDrawing();
    }

    CloseWindow();
}

void Game::update()
{
    int tileX = static_cast<int>(player.getPosition().x / map.getcellSize());
    int tileY = static_cast<int>(player.getPosition().y / map.getcellSize());

    player.move(map, player.getCurrentDirection());
	player.updateMouth();
   
    for (auto& point : points) 
    {
        if (point.checkCollision(player.getPosition(), player.getRadius())) 
        {
            score.addPoints(10); // Dodaj punkty do wyniku
			if (point.getIsBig() == true) // Jeœli punkt to du¿y punkt
			{
				score.addPoints(40); // Dodaj dodatkowe punkty
			}
            // Usuñ punkt z mapy
            int pointTileX = static_cast<int>(point.getPosition().x / map.getcellSize());
            int pointTileY = static_cast<int>(point.getPosition().y / map.getcellSize());

			point = Point(-1, -1, 0, BLANK); // Usuñ punkt
        }
    }

    for (auto& ghost : ghosts)
    {
        ghost.move(map, ghost.getCurrentDirection());

		if (player.checkCollision(ghost.getPosition(), static_cast<int>(map.getcellSize() / 2))) // other position, other radius
        {
            isGameOver = true;
        }
    }

    if (selectedMap == 1)
    {
        if (score.getPoints() == 2550)
        {
            isGameOver = true;
        }
    }

    if (selectedMap == 2)
    {
        if (score.getPoints() == 2520)
        {
            isGameOver = true;
        }
    }


}

void Game::initializeObjects()  // Tworzy punkty i duchy
{
    points.clear();
    ghosts.clear();

    for (int y = 0; y < map.getHeight(); y++)
    {
        for (int x = 0; x < map.getWidth(); x++)
        {
            if (map.getGrid()[y][x] == 0)
            {
                points.emplace_back(x * map.getcellSize() + map.getcellSize() / 2,
                                    y * map.getcellSize() + map.getcellSize() / 2,
                                        map.getcellSize() / 8, WHITE); // Dodanie punktów
				points.back().setIsBig(false); // Ustawienie ma³ego punktu
            }
            else if (map.getGrid()[y][x] == 3)
            {
                ghosts.emplace_back(x * map.getcellSize() + map.getcellSize() / 2,          
                                    y * map.getcellSize() + map.getcellSize() / 2, WHITE); // Dodanie ducha           
            }
            else if (map.getGrid()[y][x] == 4)
            {
				points.emplace_back(x * map.getcellSize() + map.getcellSize() / 2,
					                y * map.getcellSize() + map.getcellSize() / 2,
					                    map.getcellSize() / 4, WHITE); // Dodanie punktów
				points.back().setIsBig(true); // Ustawienie du¿ego punktu
            }
        }
    }
}

void Game::draw()
{
    int offsetX = (getScreenWidth() - map.getWidth() * map.getcellSize()) / 2;
    int offsetY = (getScreenHeight() - map.getHeight() * map.getcellSize()) / 2;

    map.draw(offsetX, offsetY);

    if (isGameOver) {

        if (selectedMap == 1)
        {
            if (score.getPoints() == 2550)
            {
                int textWidth = MeasureText("You win!", 50);
                DrawText("You win!", (getScreenWidth() - textWidth) / 2, 350, 50, YELLOW);

                return;
            }
        }

        if (selectedMap == 2)
        {
            if (score.getPoints() == 2520)
            {
                int textWidth = MeasureText("You win!", 50);
                DrawText("You win!", (getScreenWidth() - textWidth) / 2, 350, 50, YELLOW);

                return;
            }
        }



        int textWidth = MeasureText("Game Over!", 50);
        DrawText("Game Over!", (getScreenWidth() - textWidth) / 2, 200, 50, RED);

        textWidth = MeasureText("Press R to Restart", 20);
        DrawText("Press R to Restart", (getScreenWidth() - textWidth) / 2, 300, 20, WHITE);

        return; // Nie rysuj innych elementów gry      
    }


    player.draw(offsetX, offsetY, player.getCurrentDirection());

    for (const auto& point : points) 
    {
        point.draw(offsetX, offsetY);
    }
    int i = 0;
    for (auto& ghost : ghosts)
    {
        ghost.draw(offsetX, offsetY, map, ghost.setColor(i));
        i++;
    }

    score.draw(10, 10, 30, YELLOW);
}

void Game::reset()
{
    Menu();
    player = PacMan(1 * 30 + 15, 1 * 30 + 15, 15, YELLOW);
	initializeObjects();
    score.reset();
    isGameOver = false;
}




