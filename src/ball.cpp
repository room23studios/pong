#include "ball.hpp"

Ball::Ball() {

}

Ball::Ball(float radius) {
	sprite = sf::CircleShape(radius);

	velocity = { 2.0f, -2.0f };
}

void Ball::update() {
	sprite.move(velocity);
}
