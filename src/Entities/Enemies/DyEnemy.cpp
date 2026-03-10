#include "DyEnemy.hpp"
#include "raylib.h"

DyEnemy::DyEnemy(float x, float y) : Enemy(x, y) { 
    this->cooldown = GetRandomValue(90, 300); 

    int rarity = GetRandomValue(1, 100);
    if (rarity <= 20) {
        this->sourceRect = {155, 129, 13, 13};
        this->health = 3;
        this->color = YELLOW;
    } else if (rarity <= 55) {
        this->sourceRect = {2, 128, 13, 14};
        this->color = WHITE;
        this->health = 1;
    } else {
        this->sourceRect = {2, 147, 13, 13};
        this->color = WHITE;
        this->health = 1;
    }
}

void DyEnemy::draw() {
    if (HitBox::drawHitbox) this->hitBox.draw();
    DrawTexturePro(
    ImageManager::SpriteSheet, 
    this->sourceRect, 
    Rectangle{this->position.first + 15, this->position.second + 15, 30, 30}, 
    Vector2{15, 15}, 
    this->aimAngle, 
    this->color
);
}
void DyEnemy::update(std::pair<float, float> pos, HitBox target) {
    this->cooldown--;

    if (!loop) {
        this->angle += 0.25;
        this->aimAngle += 0.25;
        if (fmod(this->angle, 180) == 0) {
            loop = true;
        }
    } else {
        this->angle += 2;
        this->aimAngle += 2;
        if (fmod(this->angle, 540) == 0) {
            loop = false;
        }
    }

    this->position.first += 3 * cos(angle * M_PI / 180);
    this->position.second += 3 * sin(angle * M_PI / 180);
    this->hitBox.box.x = this->position.first;
    this->hitBox.box.y = this->position.second;

    if (this->cooldown <= 0) {
        Projectile::projectiles.push_back(Projectile(Projectile(position.first + 15, position.second, 1)));
        PlaySound(SoundManager::shoot);
        this->cooldown = GetRandomValue(90, 300);
    }
}

void DyEnemy::attack(HitBox target) { /* Not used */ }