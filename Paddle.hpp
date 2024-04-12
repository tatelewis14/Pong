#include<SFML/Graphics.hpp>

class Paddle {
public:
	Paddle();
	void movePaddleDest(sf::Vector2f _position);
	void setPaddleDest(sf::Vector2f _position);
	void interpolatePosition(float t);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::RectangleShape& getShape();
private:
	sf::RectangleShape rect;
	sf::Vector2f next_position = rect.getPosition(); 
};