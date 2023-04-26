#include <iostream>
#include "MySort.h"

using namespace std;

int main() {
    const int SIZE = MySort::SIZE;
    int array[SIZE] = {32, 4, 77, 23, 11, 43, 89, 66, 33};

    MySort sorter;
    sorter.sort(array);

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
