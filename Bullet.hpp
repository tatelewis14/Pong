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
	void bounce_on_edge();
	void handle_collision();
	Bullet(float _x, float _y, float _vx, float _vy);
private:
	sf::CircleShape ball;
	float x;
	float y;
	float vx;
	float vy;
	int radius = 15;
};