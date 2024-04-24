#include<SFML/Graphics.hpp>

class Ball {
public:
	Ball();
	void update();
	void draw(sf::RenderWindow& window);
	sf::CircleShape& getShape();
	void setInitialSpeed(sf::Vector2f _speed);
	bool check_rect_collision(sf::RectangleShape& rect);
	sf::Vector2f getPosition();
	sf::Vector2f get_velocity();
private:
	sf::CircleShape ball;
	sf::Vector2f velocity;
	int radius = 15;
};