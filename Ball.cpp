#include <iostream>
#include "Ball.hpp"
#include "Global.hpp"
#include "Bullet.hpp"
#include <cmath>

void Ball::update() {
	if (ball.getPosition().x + radius > SCREEN_WIDTH) {
		vx *= -1;
	}
	if (ball.getPosition().x - radius < 0) {
		vx *= -1;
	}
	if (ball.getPosition().y + radius > SCREEN_HEIGHT) {
		vy *= -1;
	}
	if (ball.getPosition().y- radius < 0) {
		vy *= -1;
	}
	x += vx;
	y += vy;
	ball.setPosition(x, y);
}
Ball::Ball(float _x, float _y, float _vx, float _vy, float _radius) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	radius = _radius;
	ball.setPosition(x,y);
	ball.setRadius(radius);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
};
bool Ball::check_rect_collision(sf::RectangleShape& rect) {
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
		vx *= -1;
		return true;
	}
	
	return false;
}
void Ball::set_position(float _x,float _y) {
	x = _x;
	y = _y;
}
void Ball::handle_bullet_collision(Bullet& target) {
	float ball_x = x;
	float ball_y = y;
	float target_x = target.getPosition().x;
	float target_y = target.getPosition().y;

	float distance_x = ball_x - target_x;
	float distance_y = ball_y - target_y;

	float midpoint_x = (ball_x + target_x) / 2;
	float midpoint_y = (ball_y + target_y) / 2;

	float radii_sum = ball.getRadius() + target.getRadius();

	float length = sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));

	if (length > radii_sum) return;

	if (length == 0) length = 1;

	float unit_x = distance_x / length;
	float unit_y = distance_y / length;

	set_position(midpoint_x + ((radii_sum + 1) * unit_x) * 0.5, midpoint_y + ((radii_sum + 1) * unit_y) * 0.5);
	target.set_position(midpoint_x - ((radii_sum + 1) * unit_x) * 0.5, midpoint_y - ((radii_sum + 1) * unit_y) * 0.5);
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
sf::Vector2f Ball::get_velocity() {
	return sf::Vector2f(vx, vy);
}
void Ball::check_bullet_collision(std::vector<Bullet> bullets) {
	for (int i = 0; i < bullets.size(); i++) {
		Bullet* temp = &bullets[i];
		handle_bullet_collision(*temp);
	}
}