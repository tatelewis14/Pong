#include"BulletManager.hpp"
#include"Bullet.hpp"
#include<SFML/Graphics.hpp>
#include"Global.hpp"
#include<iostream>

BulletManager::BulletManager() {
	std::cout << "Bullet manager\n";
}
std::vector<Bullet> BulletManager::getBullets() {
	return bullets;
};
void BulletManager::shoot(float _x, float _y, float _vx, float _vy) {
	Bullet temp(_x, _y, _vx, _vy) ;
	bullets.push_back(temp);
}
void BulletManager::render(sf::RenderWindow& window) {
	for (int i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i].getShape());
	}
}
void BulletManager::update() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].bounce_on_edge();
		bullets[i].move();
	}
}
void BulletManager::detectCollision(sf::CircleShape& circle) {
	for (int i = 0; i < bullets.size(); i++) {
	float dist = std::sqrt(std::pow(bullets[i].getPosition().x - circle.getPosition().x, 2) + std::pow(bullets[i].getPosition().y - circle.getPosition().y, 2));
	if (dist < bullets[i].getRadius() + circle.getRadius()) {
		std::cout << "Collision\n";
	}
	}
}