#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
T** create_2d_array(int rows, int cols)
{
    T** arr = new T*[rows];

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
void insert_row(T**& arr, int cols, int& rows, int pos, T* line) {
    T** new_arr = new T*[rows + 1];
    for (size_t i = 0; i < pos; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[pos] = line;
    for (size_t i = pos; i < rows; i++)
    {
        new_arr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    rows++;
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

    cout << "Enter the position to insert a row: ";
    cin >> pos;

    cout << "Enter the row to insert: ";
    int* line = new int[cols];
    for (size_t i = 0; i < cols; i++)
    {
        cin >> line[i];
    }

    insert_row(arr, cols, rows, pos, line);
    print_2d_array(arr, rows, cols);

    delete_2d_array(arr, rows);
    return 0;
}