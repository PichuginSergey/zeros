#include <iostream>
#include<cstdlib>
#include "Game.h"
#include "Field.h"

void Game::getStep() {
	if (this->playerFlag == HUMAN) {
		this->humanStep();
		this->playerFlag = MASHINE;
	}
	else {
		this->playerFlag = HUMAN;
		this->mashineStep();
	}
	this->drawField();
	this->checkEndTheGame();
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
		i = rand() % size;
		j = rand() % size;
	} while (this->playField(i, j) != ' ');
	this->playField(i, j) = 'O';
	std::cout << std::endl << "My step: " << i << " " << j << std::endl;
}

void Game::checkWiner(char ch) {
	if (ch == 'X')
		std::cout << "You are win!!!";
	else
		std::cout << "I'm win! YHAAAAAAA!!!";
	this->gameEndFlag = true;
}

void Game::checkEndTheGame() {

	// Check Row
	for (size_t i = 0; i < this->playField.getSize(); ++i) {
		
		char ch = this->playField(i, 0);
		size_t j = 0;
		if (ch == 'X' || ch == 'O') {
			for (j = 1; j < this->playField.getSize(); ++j)
				if (playField(i, j) != ch) break;
		}
		if (j == this->playField.getSize()) 
			checkWiner(ch);
	}

	// Check column
	for (size_t i = 0; i < this->playField.getSize(); ++i) {

		char ch = this->playField(0, i);
		size_t j = 0;
		if (ch == 'X' || ch == 'O') {
			for (j = 1; j < this->playField.getSize(); ++j)
				if (playField(j, i) != ch) break;
		}
		if (j == this->playField.getSize())
			checkWiner(ch);
	}
	// Check diagonal
	size_t i = 0;
	char ch = this->playField(i, i);
	if (ch == 'X' || ch == 'O') {
		for (i = 1; i < this->playField.getSize(); ++i) {
				if (playField(i, i) != ch) break;
		}
	}
	if (i == this->playField.getSize())
		checkWiner(ch);

	i = 0;
	ch = this->playField(i, this->playField.getSize() - 1);
	if (ch == 'X' || ch == 'O') {
		for (i = 1; i < this->playField.getSize(); ++i) {
			if (playField(i, this->playField.getSize() - i - 1) != ch) break;
		}
	}
	if (i == this->playField.getSize())
		checkWiner(ch);
}

