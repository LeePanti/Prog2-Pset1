#include <iostream>
#include "mysort.h"
using namespace std;


// default constructor
MySort::MySort() {
    resetBucket();
}

void MySort::sort(int array[]) {
    int totalDigits;

    // determines the biggest number of digits that a value in the array has. 
    totalDigits =  determineMaximumDigits(array, SIZE);
    resetBucket();

    // loops through the algorithm 'x' times based on the total number of digits
    for(int currentDigit = 1; currentDigit <= totalDigits; currentDigit++) {
        // separates the values in the array into the specific positions in the 2D array
        distributeValues(array, currentDigit);
        // joins the semi-sorted values back to the original array
        collectValues(array);

        // resets the 2D array back to zeros. 
        if(currentDigit != totalDigits) {
            resetBucket();
        }
    }
}

void MySort::resetBucket() {
    // loops through the 2D array and sets all the values to zero
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= SIZE; j++) {
            bucket[i][j] = 0;
        }
    }
}

void MySort::printBucket() {
    // loops through the 2D array and prints the values. 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= SIZE; j++) {
          cout << bucket[i][j] << " ";
        }
        cout << endl;
    }
}

int MySort::determineMaximumDigits (int a[], int size){
    // loops through the array and determines which value is the largest. 
    int maxNum = a[0];
    for (int i = 0; i < size; i++) {
        if (maxNum < a[i]) {
          maxNum = a[i];
        }
    }

    // counts how many digits are in the largest value. 
    int digitNum = 0;
    while (maxNum > 0) {
        maxNum /= 10;
        digitNum++;
    }
    return digitNum;
}

void MySort::distributeValues (int array[], int currentDigit) {

    int divisor = 10, columnNumber, rowNumber;

    // determines what the divisor number should be depending on how many times the array has been sorted. 
    for (int i = 1; i < currentDigit; i++) {
        divisor *= 10;
    }

    for (int j = 0; j < SIZE; j++) {
        // determines in which row the current value should be inserted into. 
        rowNumber = (array[j] % divisor - array[j] % (divisor / 10)) / (divisor / 10);

        // determines in which column the current value should be inserted into. and updates the counter located at column 0 in the specific row.
        int columnNumber = ++bucket[rowNumber][0];
        // inserts the current value into the appropriate row and column for the 2D array. 
        bucket[rowNumber][columnNumber] = array[j];
    }
}

// puts the values in the 2D array back into the original array
void MySort::collectValues(int array[]) {
    // determines what index the original array should be at. 
    int arrayIndex = 0;

    // loops through all the rows in the 2D array.
    for (int i = 0; i < 10; i++) {
        // determines how many values are in the current row. 
        int amountInRow = bucket[i][0];
        // loops through the amount of values in the current row sets them to the original array.
        for (int j = 1; j <= amountInRow; j++) {
            array[arrayIndex] = bucket[i][j];
            // updates the array index after each value is inserted. 
            arrayIndex++;
        }
    }
}