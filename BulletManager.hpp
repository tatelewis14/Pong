#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"Global.hpp"
#include"Bullet.hpp"

class BulletManager {
public:
	BulletManager();
	std::vector<Bullet> getBullets();
	void shoot(float _x, float _y, float _vx, float _vy);
	void render(sf::RenderWindow& window);
	void update();
	void detectCollision(sf::CircleShape& circle);
private:
	std::vector<Bullet> bullets;
};