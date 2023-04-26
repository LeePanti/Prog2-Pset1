#include "mysort.h"

MySort::MySort()
{
    resetBucket();
}

void MySort::resetBucket(){
    for (int i = 0; i < 10; i++) {
          for (int j = 0; j <= SIZE; j++) {
            bucket[i][j] = 0;
          }
        }

}



int MySort::determineMaximumDigits (int a[], int b){

    return b;
}
void MySort::distributeValues (int array[], int currentDigit){

    int divisor = 10;
    int columnNumber = 1;
    int rowNumber;

        for (int i = 1; i < currentDigit; i++) {
          divisor *= 10;
        }

        for (int i = 0; i < SIZE; i++) {
            rowNumber = (array[i] / divisor) % 10;


          while (bucket[rowNumber][columnNumber] != 0) {
            columnNumber++;
          }

          bucket[rowNumber][columnNumber] = array[i];
        }

}
void MySort::collectValues(int []){

}

void MySort::sort(int a[]){
    int totalDigits;

    totalDigits =  determineMaximumDigits(a, SIZE);
    resetBucket();

    for(int currentDigit=0;currentDigit<totalDigits; currentDigit++){
        distributeValues(a,currentDigit);
        collectValues(a);
        if(currentDigit != totalDigits){
            resetBucket();
        }

    }

}

