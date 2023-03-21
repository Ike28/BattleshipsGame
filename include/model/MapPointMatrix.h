#pragma once
#include "Matrix.h"
#include "MapPoint.h"

class MapPointMatrix : public Matrix<MapPoint*> {
	public:
		MapPointMatrix();
		MapPointMatrix(int squareMatrixSize);
		MapPointMatrix(const MapPointMatrix& other);
		~MapPointMatrix();

		void registerEntity(int row, int column, Ship * otherEntity);
};

inline MapPointMatrix::MapPointMatrix() : Matrix<MapPoint*>() {

}

inline MapPointMatrix::MapPointMatrix(int squareMatrixSize) {
	rows = columns = squareMatrixSize;
	storage = new MapPoint * * [rows];
	for (int i = 0; i < rows; ++i) {
		storage[i] = new MapPoint * [columns];
		for (int j = 0; j < columns; ++j) {
			storage[i][j] = new MapPoint(i, j);
		}
	}
}

inline MapPointMatrix::MapPointMatrix(const MapPointMatrix& other) : Matrix<MapPoint*>(other) {

}

inline MapPointMatrix::~MapPointMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			delete storage[i][j];
		}
		delete[] storage[i];
	}
	delete[] storage;
}

inline void MapPointMatrix::registerEntity(int row, int column, Ship* otherEntity) {
	storage[row][column]->registerEntity(otherEntity);
}
