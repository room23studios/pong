clean: build
	rm main.o

build:
	g++ -c src/main.cpp
	g++ main.o -o pong.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
