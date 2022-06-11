all:
	g++ -o main src/main.cpp src/cli.cpp src/game/game.cpp src/game/grid/grid.cpp src/game/minemap/minemap.cpp

debug:
	g++ -g -o main src/main.cpp src/cli.cpp src/game/game.cpp src/game/grid/grid.cpp src/game/minemap/minemap.cpp
