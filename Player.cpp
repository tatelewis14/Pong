#include "Player.hpp"
#include<SFML/Graphics.hpp>
#include<cmath>

Player::Player(float _x, float _y) {
	x = _x;
	y = _y;
	circle.setRadius(radius);
	circle.setPosition(x, y);
	circle.setFillColor(sf::Color::Blue);
}
void Player::move(sf::Vector2f velocity) {
	x += velocity.x;
	y += velocity.y;
	circle.setPosition(x, y);
}
/*
void Player::rotate(float angle) {
	circle.setRotation(angle);
	line[0] = sf::Vertex(circle.getPosition());
	line[1] = sf::Vertex(sf::Vector2f(
		circle.getPosition().x + radius * cos(degreesToRadians(angle)),
		circle.getPosition().y + radius * sin(degreesToRadians(angle))
	));
	
}*/
static float degreesToRadians(float degree) {
	return degree * (float)3.14159265 / 180;
}