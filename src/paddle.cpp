#include "paddle.hpp"

Paddle::Paddle() {

}

Paddle::Paddle(float width, float height) {
	sprite = sf::RectangleShape({ width, height });
}

void Paddle::moveUp() {
	sprite.move(0, -5);
}

void Paddle::moveDown() {
	sprite.move(0, 5);
}
