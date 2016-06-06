#include <iostream>
#include "Game.h"
#include "Viewer.h"

int main(int argc, char* argv[]) {

	std::cout << "I greet you, human!\n" <<
					"Do you dare to challenge me, perfect intelligence!\n" <<
					"Let see what you can do, mortal" << std::endl;
	Game game(3, new ConsoleGameFieldViewer());
	game.drawField();
	while (!game.isGameEnd())
		game.getStep();
	return EXIT_SUCCESS;
}