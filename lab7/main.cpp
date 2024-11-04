#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class Matrix {
public:
	int matrix_size;
	double** matrix_data;

	Matrix(int size = 0) : matrix_size(size) {
		matrix_data = new double*[matrix_size];
		for (int i = 0; i < matrix_size; i++) {
			matrix_data[i] = new double[matrix_size]{0};
		}
	}

	Matrix(const Matrix& other) : matrix_size(other.matrix_size) {
		matrix_data = new double*[matrix_size];
		for (int i = 0; i < matrix_size; ++i) {
			matrix_data[i] = new double[matrix_size];
			for (int j = 0; j < matrix_size; ++j) {
				matrix_data[i][j] = other.matrix_data[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& other) {
		if (this == &other) return *this;  // Self-assignment check

		// Free existing memory
		for (int i = 0; i < matrix_size; ++i) {
			delete[] matrix_data[i];
		}
		delete[] matrix_data;

		// Copy size and allocate new memory
		matrix_size = other.matrix_size;
		matrix_data = new double*[matrix_size];
		for (int i = 0; i < matrix_size; ++i) {
			matrix_data[i] = new double[matrix_size];
			for (int j = 0; j < matrix_size; ++j) {
				matrix_data[i][j] = other.matrix_data[i][j];
			}
		}

		return *this;
	}

	~Matrix() {
		for (int i = 0; i < matrix_size; ++i) {
			delete[] matrix_data[i];
		}
		delete[] matrix_data;
	}
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
	ifstream file(file_name);
	int size;
	if (file.is_open()) {
		if (!(file >> size) || size <= 0) {
			throw runtime_error("Invalid matrix size in file.");
		}

		matrix_1 = Matrix(size);
		matrix_2 = Matrix(size);

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (!(file >> matrix_1.matrix_data[i][j])) {
					throw runtime_error("Invalid matrix data in file.");
				}
			}
		}

		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (!(file >> matrix_2.matrix_data[i][j])) {
					throw runtime_error("Invalid matrix data in file.");
				}
			}
		}
		file.close();
	} else {
		throw runtime_error("Unable to open file");
	}
}

void print_matrix(const Matrix& matrix) {
	for (int i = 0; i < matrix.matrix_size; i++) {
		for (int j = 0; j < matrix.matrix_size; j++) {
			cout << matrix.matrix_data[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
	cout << "Matrix 1:" << endl;
	print_matrix(matrix_1);
	cout << "Matrix 2:" << endl;
	print_matrix(matrix_2);
}

Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) {
	int size = matrix_1.matrix_size;
	Matrix matrix_3(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix_3.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];
		}
	}
	return matrix_3;
}

Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {
	int size = matrix_1.matrix_size;
	Matrix m3(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m3.matrix_data[i][j] = 0;
			for (int k = 0; k < size; k++) {
				m3.matrix_data[i][j] += matrix_1.matrix_data[i][k] * matrix_2.matrix_data[k][j];
			}
		}
	}
	return m3;
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
	return matrix_1 + matrix_2;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
	return matrix_1 * matrix_2;
}

void get_diagonal_sum(const Matrix& matrix) {
	int size = matrix.matrix_size;
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix.matrix_data[i][i];
	}
	cout << "Sum of the diagonal elements: " << sum << endl << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
	if (row1 >= 0 && row1 < matrix.matrix_size && row2 >= 0 && row2 < matrix.matrix_size) {
		swap(matrix.matrix_data[row1], matrix.matrix_data[row2]);
	} else {
		throw out_of_range("Invalid row indices for swapping.");
	}
}

int main() {
	const string RESET = "\033[0m";
	const string RED = "\033[31m";
	const string GREEN = "\033[32m";
	const string BLUE = "\033[34m";

	Matrix matrix_1, matrix_2;
	read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

	cout << RED << "print_matrix" << RESET << endl;
	print_matrix(matrix_1, matrix_2);

	cout << BLUE << "add_matrices result:" << RESET << endl;
	Matrix add_result = add_matrices(matrix_1, matrix_2);
	print_matrix(add_result);

	cout << GREEN << "multiply_matrices result:" << RESET << endl;
	Matrix multiply_result = multiply_matrices(matrix_1, matrix_2);
	print_matrix(multiply_result);

	cout << RED << "get matrix diagonal sum" << RESET << endl;
	get_diagonal_sum(matrix_1);

	cout << BLUE << "swap matrix rows" << RESET << endl;
	swap_matrix_row(matrix_1, 0, 1);
	print_matrix(matrix_1);

	return 0;
}

