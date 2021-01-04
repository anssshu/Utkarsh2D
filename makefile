
all:main.cpp
	g++ -o app main.cpp -lSDL2 -lGL
	./app