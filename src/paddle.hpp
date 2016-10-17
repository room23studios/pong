#include <SFML/Graphics.hpp>

class Paddle {
public:
	Paddle();
	Paddle(float width, float height);

	void moveUp();
	void moveDown();

	sf::RectangleShape sprite;
};
