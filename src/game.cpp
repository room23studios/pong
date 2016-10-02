#include "game.hpp"

Game::Game() {
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong");

	ball = CircleShape(BALL_RADIUS);
	player1 = RectangleShape(Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	player2 = RectangleShape(Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
}

void Game::start() {
	setBallAndPaddlesPosition();
	loop();
}

void Game::setBallAndPaddlesPosition() {
	ball.setPosition(WINDOW_WIDTH / 2 - BALL_RADIUS / 2, WINDOW_HEIGHT / 2 - BALL_RADIUS / 2);
	player1.setPosition(WINDOW_WIDTH - PADDLE_WIDTH, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2);
	player2.setPosition(0, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2);
}

void Game::loop() {
	while(window.isOpen()) {
		Event event;
		while(window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
			}
		}

		window.clear();

		window.draw(ball);
		window.draw(player1);
		window.draw(player2);

		window.display();
	}
}
