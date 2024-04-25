#include<SFML/Graphics.hpp>
#include"Bullet.hpp"

class Ball {
public:
	Ball(float _x, float _y, float _vx, float _vy, float _radius);
	void update();
	void draw(sf::RenderWindow& window);
	sf::CircleShape& getShape();
	bool check_rect_collision(sf::RectangleShape& rect);
	void check_bullet_collision(std::vector<Bullet> bullets);
	void handle_bullet_collision(Bullet& target);
	void set_position(float _x, float _y);
	sf::Vector2f getPosition();
	sf::Vector2f get_velocity();
private:
	sf::CircleShape ball;
	float x;
	float y;
	float vx;
	float vy;
	float radius;
};