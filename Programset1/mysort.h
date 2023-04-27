#ifndef MYSORT_H
#define MYSORT_H


class MySort
{
public:
    MySort();
    static const int SIZE = 9;

    int bucket[10][SIZE + 1];
    int array[SIZE];
    void sort(int[]);

private:
    int determineMaximumDigits (int [], int);
    void distributeValues (int[], int);
    void collectValues(int []);
    void resetBucket();
    void printBucket();
};

#endif // MYSORT_H
