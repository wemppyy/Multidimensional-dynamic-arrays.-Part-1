#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T** init_2d_array(int rows, int cols) {
    T** arr = new T * [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new T[cols];
    }
    return arr;
}

template <typename T>
void delete_2d_array(T** arr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T>
void print_2d_array(T** arr, int rows, int cols) {
	cout << "   "; // Отступ для нумерации столбцов
	for (int j = 0; j < cols; j++) {
		cout << j << "  "; // Нумерация столбцов
	}
	cout << endl;
	cout << "   -------------" << endl;

	for (int i = 0; i < rows; i++) {
		cout << i << ": "; // Нумерация строк
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << "  "; // Вывод элементов
		}
		cout << endl;
	}
}
template <typename T>
void fill_2d_array(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

template<typename T>
void shift_array(T** array, int rows, int cols, int shift, char direction) {
	T** newArray = new T * [rows];
	for (int i = 0; i < rows; ++i) {
		newArray[i] = new T[cols];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int newI = i, newJ = j;

			if (direction == 'L') {
				newJ = (j - shift + cols) % cols;
			}
			else if (direction == 'R') {
				newJ = (j + shift) % cols;
			}
			else if (direction == 'U') {
				newI = (i - shift + rows) % rows;
			}
			else if (direction == 'D') {
				newI = (i + shift) % rows;
			}

			newArray[newI][newJ] = array[i][j];
		}
	}

	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
		array[i] = newArray[i];
	}
	delete[] newArray;
}

int main()
{
	srand(time(0));
    int M, N, shift_count;
	char direction;
	cout << "Enter the number of rows: ";
	cin >> M;
	cout << "Enter the number of columns: ";
	cin >> N;

	int** arr = init_2d_array<int>(M, N);
	fill_2d_array<int>(arr, M, N);

	system("cls");
	print_2d_array<int>(arr, M, N);

	cout << "Enter the direction of the shift (U, D, R, L): ";
	cin >> direction;
	cout << "Enter the number of shifts: ";
	cin >> shift_count;

	shift_array<int>(arr, M, N, shift_count, direction);
	system("cls");
	print_2d_array<int>(arr, M, N);
	delete_2d_array<int>(arr, M);

    return 0;
}