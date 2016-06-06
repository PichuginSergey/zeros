#include <iostream>
#include "Viewer.h"

void ConsoleGameFieldViewer::display(Field<char> field) {
	for (size_t i = 0; i < field.getSize(); ++i) {
		for (size_t j = 0; j < field.getSize(); ++j) {
			std::cout << field(i, j);
			if (j != field.getSize() - 1)
				std::cout << '|';
		}
		std::cout << std::endl;
	}
}