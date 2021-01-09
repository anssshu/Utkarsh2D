files = main.cpp src/libs/classes/*.cpp src/libs/functions/*.cpp src/app/*.cpp
all:main.cpp 
	g++  -I./src   $(files) -o app    -lSDL2  -lGL -lSDL2_image -lSDL2_mixer -lpthread -ldl
	./app