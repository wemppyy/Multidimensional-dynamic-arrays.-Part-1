#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
T** create_2d_array(int rows, int cols)
{
    T** arr = new T * [rows];

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new T[cols];
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    return arr;
}

template <typename T>
void print_2d_array(T** arr, int rows, int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void delete_2d_array(T** arr, int rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

template <typename T>
void delete_column(T** &arr, int rows, int &cols, int pos)
{
    T** new_arr = new T * [rows];
    for (size_t i = 0; i < rows; i++)
    {
        new_arr[i] = new T[cols-1];
        for (size_t j = 0; j < pos; j++)
        {
            new_arr[i][j] = arr[i][j];
        }
        for (size_t j = pos; j < cols-1; j++)
        {
            new_arr[i][j] = arr[i][j+1];
        }
    }
	delete_2d_array(arr, rows);
	arr = new_arr;
    cols--;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int cols, rows, pos;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** arr = create_2d_array<int>(rows, cols);

    print_2d_array(arr, rows, cols);

    cout << "Enter the position to delete a column: ";
    cin >> pos;

	delete_column(arr, rows, cols, pos);
    print_2d_array(arr, rows, cols);

    delete_2d_array(arr, rows);
    return 0;
}