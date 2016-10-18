clean: build
	rm *.o

build:
	g++ -c src/*.cpp src/*.hpp --std=gnu++11
	g++ *.o -o pong.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
