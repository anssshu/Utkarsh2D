files = main.cpp src/libs/classes/*.cpp src/libs/functions/*.cpp src/app/*.cpp

engine_files = src/libs/classes/*.cpp src/libs/functions/*.cpp
game_files = main.cpp src/app/*.cpp

all:main.cpp 
	g++  -I./src   $(files) -o app    -lSDL2  -lGL -lSDL2_image -lSDL2_mixer -lpthread -ldl
	./app

engine: $(engine_files) 
	g++ -c $(engine_files)	-I./src -lSDL2  -lGL -lSDL2_image -lSDL2_mixer -lpthread -ldl
	ar rvs -o libs/libMyEngine.a  *.o 
	rm -r  *.o

game: $(game_files)
	g++ -o game $(game_files) -I./src -L./  -lMyEngine	-lSDL2  -lGL -lSDL2_image -lSDL2_mixer -lpthread -ldl
	./game