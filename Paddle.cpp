#include"Paddle.hpp"
#include<SFML/Graphics.hpp>
#include"Global.hpp"
#include<iostream>

void Paddle::movePaddleDest(sf::Vector2f _position) {
	float rect_y = rect.getPosition().y;
	float rect_x = rect.getPosition().x;
	float rect_height = rect.getSize().y;

	if (rect_y + rect_height + _position.y > SCREEN_HEIGHT) rect.setPosition(rect_x, SCREEN_HEIGHT - rect_height);
	else if (rect_y + _position.y < 0) rect.setPosition(rect_x, 0);
	else next_position.y = rect.getPosition().y + _position.y;
	next_position.x = rect.getPosition().x + _position.x;
	//rect.setPosition(lerp(rect.getPosition(), next_position, 0.5f));
}
void Paddle::setPaddleDest(sf::Vector2f _position) {
	next_position = _position;
}
Paddle::Paddle() {
	rect.setSize(sf::Vector2f(10.f, 100.f));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(800 - rect.getSize().x * 2, 0);
	next_position.x = 0;
}
void Paddle::interpolatePosition(float t) {
	sf::Vector2f interpolated_velocities;
	interpolated_velocities.y = rect.getPosition().y + t * (next_position.y - rect.getPosition().y);
	interpolated_velocities.x = rect.getPosition().x;
	rect.setPosition(interpolated_velocities);
};
sf::Vector2f Paddle::getPosition() {
	return rect.getPosition();
}
sf::Vector2f Paddle::getSize() {
	return rect.getSize();
}
void Paddle::draw(sf::RenderWindow& window) {
	window.draw(rect);
}
sf::RectangleShape& Paddle::getShape() {
	return rect;
}