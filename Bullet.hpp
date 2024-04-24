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
	float get_mass();
	void set_position(float _x, float _y);
	void set_velocity(sf::Vector2f& new_velocity);
	void bounce_on_edge();
	sf::Vector2f get_velocity();
	void handle_static_collision(Bullet& target);
	void handle_dynamic_collision(Bullet& target);
	float dot_product(const sf::Vector2f& v1, const sf::Vector2f& v2);
	Bullet(float _x, float _y, float _vx, float _vy);
private:
	sf::CircleShape ball;
	float x;
	float y;
	float vx;
	float vy;
	float mass = radius;
	int radius{ 10 };
};