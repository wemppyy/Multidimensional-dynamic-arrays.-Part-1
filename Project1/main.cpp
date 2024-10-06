#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
T** create_2d_array(int rows, int cols)
{
    T** arr = new T*[rows];
    
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new T [cols];
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
void add_new_line(T**& arr, int &rows, T* line) {
    T** new_arr = new T * [rows + 1];
    for (size_t i = 0; i < rows; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[rows] = line;
    delete[] arr;
    arr = new_arr;
    rows++;
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
void add_row_sum(T**& arr, int &rows, int cols) {  
   int temp = 0;  
   T* new_line = new T[cols];  
   for (size_t i = 0; i < cols; i++) {  
       new_line[i] = 0;  
   }  
   for (size_t i = 0; i < rows - 1; i++) {  
       for (int j = cols - 1; j >= 0; j--) {  
		   int sum = arr[i][j] + arr[i + 1][j] + temp;
		   temp = sum / 10;
		   if (sum > 9) {
			   sum = sum % 10;
           }
           
		   new_line[j] = sum;
       }  
   }  
   add_new_line<int>(arr, rows, new_line);  
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int rows = 2;
    int cols = 3;
    // int** arr = create_2d_array<int>(rows, cols);
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 8;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 8;


    print_2d_array<int>(arr, rows, cols);

    system("pause");

    add_row_sum(arr, rows, cols);
    print_2d_array<int>(arr, rows, cols);

    delete_2d_array<int>(arr, rows);

    return 0;
}