clean: build
	rm main.o game.o

build:
	g++ -c src/ball.hpp src/ball.cpp src/game.hpp src/game.cpp src/main.cpp
	g++ main.o game.o ball.o -o pong.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
