#pragma once
#include "Field.h"

class GameFieldViewer {

public:
	virtual void display(Field<char> field) abstract;
};

class ConsoleGameFieldViewer : public GameFieldViewer{

public:
	void display(Field<char> field) override;
};