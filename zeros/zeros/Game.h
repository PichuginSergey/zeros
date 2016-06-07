#pragma once
#include <iostream>
#include <memory>
#include<ctime>
#include "Viewer.h"
#include "Field.h"

class Game {

public:
	Game(int N, GameFieldViewer* view) : playField(N), gameViwer(view) {
		for (size_t i = 0; i < playField.getSize(); ++i)
			for (size_t j = 0; j < playField.getSize(); ++j)
				playField(i,j) = ' ';
		srand(time(NULL));
	}
	bool isGameEnd() const { return gameEndFlag; }
	void getStep();
	void drawField() const;

private:
	void humanStep();
	void mashineStep();
	void checkWiner(char ch);
	void checkEndTheGame();
	bool checkSeq(Field<char>::FieldIterator& it);
	Field<char> playField;
	std::unique_ptr<GameFieldViewer> gameViwer;
	int playerFlag = HUMAN;
	bool gameEndFlag = false;
	enum {HUMAN, MASHINE};
};
