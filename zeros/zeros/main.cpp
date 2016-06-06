#include <iostream>
#include "Game.h"
#include "Viewer.h"

int main(int argc, char* argv[]) {

	Game game(3, new ConsoleGameFieldViewer());
	while (!game.isGameEnd())
		game.getStep();
	return EXIT_SUCCESS;
}