files = main.cpp src/libs/classes/*.cpp src/libs/functions/*.cpp 
all:main.cpp 
	g++ -I./include -I./src  $(files) -o app  -L./libs -lSDL2  -lGL -lSDL2_image
	./app