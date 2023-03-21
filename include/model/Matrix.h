#pragma once

template <class Entity> class Matrix {
	protected:
		int rows;
		int columns;
		Entity * * storage;
	
	public:
		Matrix();
		Matrix(int rows, int columns);
		Matrix(int squareMatrixSize);
		Matrix(const Matrix<Entity>& other);
		~Matrix();

		int getRows();
		int getColumns();
		Entity* getElement(int row, int column);
};

template<class Entity>
inline Matrix<Entity>::Matrix() {
	rows = 0;
	columns = 0;
	storage = nullptr;
}

template<class Entity>
inline Matrix<Entity>::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	storage = new Entity * [rows];
	for (int i = 0; i < rows; ++i) {
		storage[i] = new Entity[columns];
	}
}

template<class Entity>
inline Matrix<Entity>::Matrix(int squareMatrixSize) {
	this->Matrix(squareMatrixSize, squareMatrixSize);
}

template<class Entity>
inline Matrix<Entity>::Matrix(const Matrix<Entity>& other) {
	for (int i = 0; i < rows; ++i) {
		delete[] storage[i];
	}
	delete[] storage;

	this->rows = other.rows;
	this->columns = other.columns;
	storage = new Entity * [rows];
	for (int i = 0; i < rows; ++i) {
		storage[i] = new Entity[columns];
	}
}

template<class Entity>
inline Matrix<Entity>::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] storage[i];
	}
	delete[] storage;
}

template<class Entity>
inline int Matrix<Entity>::getRows() {
	return rows;
}

template<class Entity>
inline int Matrix<Entity>::getColumns() {
	return columns;
}

template<class Entity>
inline Entity* Matrix<Entity>::getElement(int row, int column) {
	return &storage[row][column];
}
