#include"Bullet.hpp"
#include<SFML/Graphics.hpp>
#include<array>

Bullet::Bullet(float _x, float _y, float _vx, float _vy) {
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
	ball.setPosition(x, y);
}
Bullet::~Bullet() {
	std::cout << "Deleted\n";
};
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
