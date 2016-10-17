#include <SFML/Graphics.hpp>

#include "ball.hpp"
#include "paddle.hpp"

using namespace sf;

class Game {
private:
	RenderWindow window;

	Ball ball;
	Paddle player1;
	Paddle player2;

	const int WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;
	const float BALL_RADIUS = 10, PADDLE_WIDTH = 10, PADDLE_HEIGHT = 50;
	const unsigned int MAX_FPS = 60;

public:
	Game();

	void start();
	void loop();
	void setBallAndPaddlesPosition();
};
