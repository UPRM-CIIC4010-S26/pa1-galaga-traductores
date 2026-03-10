#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "StdEnemy.hpp"
#include "SpEnemy.hpp"
#include "StEnemy.hpp"
#include "DyEnemy.hpp"
class Program {
    private:
        Background background = Background();
        Player* player = new Player((GetScreenWidth() / 2) - 15, GetScreenHeight() * 0.75f);
        int respawnCooldown = 1080;
        int respawns = 0;
        int count = 0;
        int delay = 0;
        int lives = 3;
        int pauseFrames = 0;
        int score = 0;  //Added
        int nextLifeScore = 1000;  //Added
        int gameMode = 0;

        bool startup = true;
        bool paused = false;
        bool gameOver = false;

        static const int STAR_COUNT = 100;
        float starX[STAR_COUNT];
        float starY[STAR_COUNT];

        void InitStars();
        void UpdateStars();
        void DrawStars();

    public:
        Program();
        
        void Update();
        void Draw();
        void ManageEnemyRespawns();
        void DrawStartup();
        void DrawPauseScreen();
        void DrawGameOver();
        void KeyInputs();
        void PlayerReset();
        void Reset();
        
          
        ~Program() {}
};