#include"Bullet.hpp"
#include<SFML/Graphics.hpp>
#include<array>
#include"Global.hpp"
#include<vector>

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
void Bullet::set_position(float _x, float _y) {
	x = _x; 
	y = _y;
	ball.setPosition(x, y);
}
float Bullet::getRadius() {
	return radius;
}
void Bullet::bounce_on_edge() {
	float x = ball.getPosition().x;
	float y = ball.getPosition().y;
	float radius = ball.getRadius();

	if (x + radius > SCREEN_WIDTH) {
		set_position(SCREEN_WIDTH - radius, y);
		vx = -vx;
	}
	if (x - radius  < 0) {
		set_position(radius, y);
		vx = -vx;
	}
	if (y + radius > SCREEN_HEIGHT) {
		set_position(x, SCREEN_HEIGHT - radius);
		vy = -vy;
	}
	if (y - radius < 0) {
		set_position(x, radius);
		vy = -vy;
	}
}
sf::Vector2f Bullet::get_velocity() {
	return sf::Vector2f(vx, vy);
}
void Bullet::set_velocity(sf::Vector2f& new_velocity) {
	vx = new_velocity.x;
	vy = new_velocity.y;
}
float Bullet::dot_product(const sf::Vector2f& v1, const sf::Vector2f& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
float Bullet::get_mass() {
	return mass;
}
void Bullet::handle_static_collision(Bullet& target) {
	float ball_x = x;
	float ball_y = y;
	float target_x = target.getPosition().x;
	float target_y = target.getPosition().y;

	float distance_x = ball_x - target_x;
	float distance_y = ball_y - target_y;

	float midpoint_x = (ball_x + target_x) / 2;
	float midpoint_y = (ball_y + target_y) / 2;

	float radii_sum = ball.getRadius() + target.getRadius();

	float length = sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));

	if (length == 0) length = 1;

	float unit_x = distance_x / length;
	float unit_y = distance_y / length;

	set_position(midpoint_x + ((radii_sum + 1) * unit_x) * 0.5, midpoint_y + ((radii_sum + 1) * unit_y) * 0.5);
	target.set_position(midpoint_x - ((radii_sum + 1) * unit_x) * 0.5, midpoint_y - ((radii_sum + 1) * unit_y) * 0.5);
}
void Bullet::handle_dynamic_collision(Bullet& target) {

}
float magnitude(sf::Vector2f vector) {
	return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

