#include"Bullet.hpp"
#include<SFML/Graphics.hpp>
#include<array>
#include"Global.hpp"

Bullet::Bullet(float _x, float _y, float _vx, float _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
	ball.setPosition(x, y);
	ball.setFillColor(sf::Color::Magenta);
}
void Bullet::move() {
	ball.move(vx, vy);
};
sf::CircleShape& Bullet::getShape() {
	return ball;
}
sf::Vector2f Bullet::getPosition() {
	return ball.getPosition();
}
float Bullet::getRadius() {
	return radius;
}
void Bullet::bounce_on_edge() {
	float x = ball.getPosition().x;
	float y = ball.getPosition().y;
	float radius = ball.getRadius();

	if (x + radius > SCREEN_WIDTH) {
		x = SCREEN_WIDTH - radius;
		vx = -vx;
	}
	if (x - radius  < 0) {
		x = radius;
		vx = -vx;
	}
	if (y + radius > SCREEN_HEIGHT) {
		y = SCREEN_HEIGHT - radius;
		vy = -vy;
	}
	if (y - radius < 0) {
		y = radius;
		vy = -vy;
	}
}
void Bullet::handle_collision() {
	vx = -vx;
	vy = -vy;
};
