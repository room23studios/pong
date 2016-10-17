#include <SFML/Graphics.hpp>

class Ball {
private:
	sf::Vector2f velocity;

public:
	Ball();
	Ball(float radius);

	void update();

	sf::CircleShape sprite;
};
