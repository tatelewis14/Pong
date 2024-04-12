#include<SFML/Graphics.hpp>

class Ball {
public:
	Ball();
	void update();
	void draw(sf::RenderWindow& window);
	void setInitialSpeed(sf::Vector2f _speed);
	bool checkCollision(sf::RectangleShape& rect);
	sf::Vector2f getPosition();
private:
	sf::CircleShape ball;
	sf::Vector2f velocity;
	int radius = 15;
};