#pragma once
#include <vector>

template<typename T>
class Field {

public:
	Field(size_t N) : size(N), field(N*N) {}
	size_t getSize() const { return size; }
	T& operator()(size_t i, size_t j) { return field[i*size + j]; }
	
	class FieldIterator {
	public:
		FieldIterator() {}
		T& operator*() { return elm[curIdx]; }
		virtual void operator++() { ++curIdx; }
		virtual void operator++(int idx) { ++curIdx; }
		virtual ~FieldIterator() {}
	protected:
		size_t curIdx = 0;
		T* elm;
	};

	class FieldRowIterator : public FieldIterator {
	public:
		FieldRowIterator(Field& field, size_t num) {
			elm = &field.field[num*field.size];
		}
		~FieldRowIterator() override {}
	};

	class FieldColumnIterator : public FieldIterator {
	public:
		FieldColumnIterator(Field& field, size_t num):size(field.size) {
			elm = &field.field[num];
		}
		void operator++() override { curIdx+=size; }
		void operator++(int idx) override { curIdx+=size; }
		~FieldColumnIterator() override {}
	private:
		size_t size;
	};

	class FieldDiagonalIterator : public FieldIterator {
	public:
		FieldDiagonalIterator(Field& field, int dt) : size(field.size), diagonal_type(dt) {
			if (diagonal_type == MAIN_DIAGONAL)
				elm = &field.field[0];
			else
				elm = &field.field[size - 1];
		}
		void operator++() override { 
			if (diagonal_type == MAIN_DIAGONAL)
				curIdx += size + 1;
			else
				curIdx += size - 1;
		}
		void operator++(int idx) override { this->operator++(); }
		~FieldDiagonalIterator() override {}
		enum {MAIN_DIAGONAL, NO_MAIN_DIAGONAL};

	private:
		size_t size;
		int diagonal_type;
	};

private:
	size_t size = DEFAULT_SIZE;
	std::vector<T> field;
	enum {DEFAULT_SIZE = 3};
};