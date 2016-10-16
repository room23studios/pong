#include <SFML/Graphics.hpp>

#include "ball.hpp"

using namespace sf;

class Game {
private:
	RenderWindow window;

	Ball ball;
	RectangleShape player1;
	RectangleShape player2;

	const int WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;
	const float BALL_RADIUS = 10, PADDLE_WIDTH = 10, PADDLE_HEIGHT = 50;
	const unsigned int MAX_FPS = 60;

public:
	Game();

	void start();
	void loop();
	void setBallAndPaddlesPosition();
};
