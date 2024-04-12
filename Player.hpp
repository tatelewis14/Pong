#include <SFML/Graphics.hpp>

class Player {
public:
	Player(float _x, float _y);
	sf::CircleShape circle;
	sf::VertexArray line;
	void move(sf::Vector2f velocity);
	/*void rotate(float angle);*/

private:
	float x;
	float y;
	float radius = 10;
};