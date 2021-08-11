#include <iostream>

using namespace std;

int *apply_all (int const *const array1, size_t size1, int const *const array2, size_t size2);
void print (int const *const arr, size_t size);

int main(int argc, char **argv)
{
	const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1 [] {1, 2, 3, 4, 5};
    int array2 [] {10, 20, 30};
    
    cout << "Array 1: ";
    print (array1, array1_size);
    
    cout << "Array 2: ";
    print (array2, array2_size);
    
    int *results = apply_all (array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};
    
    cout << "Result: ";
    print (results, results_size);
    
    delete [] results;
    cout << endl;
	return 0;
}

int *apply_all (int const *const array1, size_t size1, int const *const array2, size_t size2)
{
    int *result_array {nullptr};
    result_array = new int [size1 * size2];
    int position {0};
    
    for (size_t i {0}; i < size2; ++i)
    {
        for (size_t j {0}; j < size1; ++j)
        {
            result_array [position] = array2 [i] * array1 [j];
            ++position;
        }
    }
    return result_array;
}

void print (int const *const arr, size_t size)
{
    cout << "[ ";
    for (size_t i {0}; i < size; ++i)
    {
        cout << arr [i] << " ";
    }
    cout << "]";
    cout << endl;
}
