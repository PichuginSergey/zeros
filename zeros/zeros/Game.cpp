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

bool Game::checkSeq(Field<char>::FieldIterator& it) {

	char ch = *it;
	size_t j = 0;
	if (ch == 'X' || ch == 'O') {
		for (j = 1; j < this->playField.getSize(); ++j) {
			it++;
			if (*it!= ch) break;
		}
	}
	if (j == this->playField.getSize()) {
		checkWiner(ch);
		return true;
	}
	return false;
}

void Game::checkEndTheGame() {

	// Check Row
	for (size_t i = 0; i < this->playField.getSize(); ++i) {
		Field<char>::FieldRowIterator it(playField, i);
		if (checkSeq(it))
			return;
	}

	// Check column
	for (size_t i = 0; i < this->playField.getSize(); ++i) {
		Field<char>::FieldColumnIterator it(playField, i);
		if (checkSeq(it))
			return;
	}
	// Check main diagonal
	Field<char>::FieldDiagonalIterator it1(playField, Field<char>::FieldDiagonalIterator::MAIN_DIAGONAL);
	if (checkSeq(it1))
		return;

	// Check other diagonal
	Field<char>::FieldDiagonalIterator it2(playField, Field<char>::FieldDiagonalIterator::NO_MAIN_DIAGONAL);
	if (checkSeq(it2))
		return;
}

