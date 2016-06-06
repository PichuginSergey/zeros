#include <iostream>
#include<cstdlib>
#include "Game.h"
#include "Field.h"


void Game::getStep() {
	this->drawField();
	if (this->playerFlag == HUMAN) {
		this->humanStep();
		this->playerFlag = MASHINE;
	}
	else {
		this->playerFlag = HUMAN;
		this->mashineStep();
	}
	this->checkWiner();
}

void Game::drawField() const {
	this->gameViwer->display(this->playField);
}

void Game::humanStep() {

	size_t i = 0, j = 0;
	do {
		std::cout << std::endl << "Enter your step:";
		std::cin >> i >> j;
	} while (this->playField(i, j) != ' ');
	this->playField(i, j) = 'X';
}

void Game::mashineStep() {
	const auto size = this->playField.getSize();
	size_t i = 0, j = 0;
	do {
		i = rand() % (size - 1);
		j = rand() % (size - 1);
	} while (this->playField(i, j) != ' ');
	this->playField(i, j) = 'O';
	std::cout << std::endl << "My step: " << i << " " << j << std::endl;
}

void Game::checkWiner() {

}

