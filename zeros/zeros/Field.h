#pragma once
#include <vector>

template<typename T>
class Field {

public:
	Field(size_t N) : size(N), field(N*N) {}
	size_t getSize() const { return size; }
	T& operator()(size_t i, size_t j) { return field[i + j*size]; }

private:
	size_t size = DEFAULT_SIZE;
	std::vector<T> field;
	enum {DEFAULT_SIZE = 3};
};