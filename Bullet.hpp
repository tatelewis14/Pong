#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Global.hpp"

class Bullet {
public:
	void move();
	sf::Vector2f getPosition();
	sf::CircleShape& getShape();
	float getRadius();
	Bullet(float _x, float _y, float _vx, float _vy);
	~Bullet();
private:
	sf::CircleShape ball;
	float x;
	float y;
	float vx;
	float vy;
	int radius = 15;
};