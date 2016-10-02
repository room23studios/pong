#include <SFML/Graphics.hpp>

using namespace sf;

class Game {
private:
	RenderWindow window;

	CircleShape ball;
	RectangleShape player1;
	RectangleShape player2;

	const int WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;
	const float BALL_RADIUS = 10, PADDLE_WIDTH = 10, PADDLE_HEIGHT = 50;

public:
	Game();

	void start();
	void loop();
	void setBallAndPaddlesPosition();
};
