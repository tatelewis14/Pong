#include<iostream>
#include "Ball.hpp"
#include "Global.hpp"
#include <cmath>

void Ball::update() {
	if (ball.getPosition().x + radius > SCREEN_WIDTH) {
		velocity.x *= -1;
	}
	if (ball.getPosition().x - radius < 0) {
		velocity.x *= -1;
	}
	if (ball.getPosition().y + radius > SCREEN_HEIGHT) {
		velocity.y *= -1;
	}
	if (ball.getPosition().y- radius < 0) {
		velocity.y *= -1;
	}
	ball.move(velocity);
}
void Ball::setInitialSpeed(sf::Vector2f _speed) {
	velocity = _speed;
}
Ball::Ball() {
	ball.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	ball.setRadius(radius);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
};
bool Ball::checkCollision(sf::RectangleShape& rect) {
	float circle_x = ball.getPosition().x; // circle coordinates(translated to be in the center of the circle)
	float circle_y = ball.getPosition().y;
	float rect_x = rect.getPosition().x; //rectangle coordinates(from the top left)
	float rect_y = rect.getPosition().y;
	
	float test_x = std::max(rect_x, std::min(circle_x, rect_x + rect.getSize().x)); //from chatgpt
	float test_y = std::max(rect_y, std::min(circle_y, rect_y + rect.getSize().y)); // basically checks to see what side of th rectangle the ball is on and only do collision on that side

	
	float dist_x = circle_x - test_x;
	float dist_y = circle_y - test_y;
	float distance = std::sqrt(std::pow(dist_x, 2.0) + std::pow(dist_y, 2.0f));
	if (distance < radius) {
		velocity.x *= -1;
		return true;
	}
	
	return false;
}
sf::Vector2f Ball::getPosition() {
	return ball.getPosition();
}
void Ball::draw(sf::RenderWindow& window) {
	window.draw(ball);
}
sf::CircleShape& Ball::getShape() {
	return ball;
}