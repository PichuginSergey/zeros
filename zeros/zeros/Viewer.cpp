#include <iostream>
#include "Viewer.h"

void ConsoleGameFieldViewer::display(Field<char> field) {
	for (size_t i = 0; i < field.getSize(); ++i) {
		Field<char>::FieldRowIterator it(field, i);
		for (size_t j = 0; j < field.getSize(); ++j) {
			std::cout << *it;//field(i, j);
			++it;
			if (j != field.getSize() - 1)
				std::cout << '|';
		}
		std::cout << std::endl;
	}
}