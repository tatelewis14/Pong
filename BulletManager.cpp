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
		bullets[i].move();
	}
}
void BulletManager::detectCollision(sf::CircleShape& circle) {
	for (int i = 0; i < bullets.size(); i++) {
		for (int j = 0; j < i; j++) {
			float dist_x = std::sqrt(std::pow(bullets[i].getPosition().x, 2) + std::pow(bullets[j].getPosition().x, 2));
			float dist_y = std::sqrt(std::pow(bullets[i].getPosition().y, 2) + std::pow(bullets[j].getPosition().y, 2));
			if (dist_x < bullets[i].getRadius() + bullets[j].getRadius() && dist_y < bullets[i].getRadius() + bullets[j].getRadius()) {
				std::cout << "Collision\n";
			}
		}
	}
}