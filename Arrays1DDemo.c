//  Arrays1DDemo.c
//  Nina Perone, 9/16/22, CIS2107 sec 002, tul44843
//  Lab 4 "Processing1DArrays": Write a C Program to design and implement functions to process 1D Arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MIN 0
#define RAND_MAX1 100
#define SIZE 40


// prototypes
void fillArray(int array[], int size);
int findWithRange(int array[], int low, int high);
void reverseArray(int array[], int size, int reverseArray[]);
void reverseSelectedRangeWithinArray(int array[], int revSelect[], int size, int startRange, int endRange);
void findSequence(int array[], int size, int num1, int num2);

// main
int main() {
    
    int array[SIZE];
    fillArray(array, SIZE);
    
    printf("\nOriginal:");
    for(int i = 0; i < SIZE; i++) {
        if(i % 10 == 0) {
            printf("\n");
        }
        printf("\t%d", array[i]);
    }
    printf("\n");
    
    // find largest in range, calls findWithRange
    printf("%s", "\nTo find largest value in selected range...\n");
    int lowSelectRange;
    int highSelectRange;
    printf("Enter lower bound of selected range: ");
    scanf("%d", &lowSelectRange);
    printf("Enter higher bound of selected range: ");
    scanf("%d", &highSelectRange);
    
    printf("\n\tMax = %d\n", findWithRange(array, lowSelectRange, highSelectRange));
    
    // reverse array, calls reverseArray
    printf("\nReversed:");
    int reverseArr[SIZE];
    reverseArray(array, SIZE, reverseArr);
    for(int i = 0; i < SIZE; i++) {
        if(i % 10 == 0) {
            printf("\n");
        }
        printf("\t%d", reverseArr[i]);
    }
    printf("\n");
    
    // reverse select range of array, calls reverseSelectedRangeWithinArray
    printf("%s", "\nTo reverse selected range...\n");
    printf("Enter lower bound of selected range: ");
    scanf("%d", &lowSelectRange);
    printf("Enter higher bound of selected range: ");
    scanf("%d", &highSelectRange);
    
    printf("\n\tReversing between %d and %d\n", lowSelectRange, highSelectRange);
    int revSelect[SIZE];
    reverseSelectedRangeWithinArray(array, revSelect, SIZE, lowSelectRange, highSelectRange);
    for(int i = 0; i < SIZE; i++) {
        if(i % 10 == 0) {
            printf("\n");
        }
        printf("\t%d", revSelect[i]);
    }
    printf("\n");
    
    // find index of sequence, calls findSequence
    printf("\nTo find the index of a sequence...");
    int seqNum1;
    int seqNum2;
    printf("\n\tEnter two numbers: ");
    scanf("%d%d", &seqNum1, &seqNum2);
    findSequence(array, SIZE, seqNum1, seqNum2);
    
    // end program
    exit(0);
}


// filles given array with random ints in given size and range
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));
    for (size_t i=0 ; i< SIZE; ++i){
        array[i]= rand() % (RAND_MAX1+1)+ RAND_MIN;
    }
}

int findWithRange(int array[], int lowSelectRange, int highSelectRange) {
    int max = array[lowSelectRange];
    if(highSelectRange < lowSelectRange) {
        printf("%s", "Not a valid input\n");
        return -1;
    }
    for(int i = lowSelectRange+1; i <= highSelectRange; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// fills array with reversed order of original array
void reverseArray(int array[], int size, int reverseArray[]) {
    //int size = sizeof(array) / sizeof(int);
    int countDown = size-1;

    for(int i = 0; i < size; i++) {
        reverseArray[i] = array[countDown];
        countDown--;
    }
}

// fills array with reversed values of original array in selected range
void reverseSelectedRangeWithinArray(int array[], int revSelect[], int size, int startRange, int endRange) {
    
    if(endRange < startRange) {
        printf("%s", "Not a valid input\n");
    }
    for(int i = 0; i < startRange; i++) {
        revSelect[i] = array[i];
    }
    int countDown = endRange;
    for(int i = startRange; i <= endRange; i++) {
        revSelect[i] = array[countDown];
        countDown--;
    }
    for(int i = endRange+1; i < size; i++) {
        revSelect[i] = array[i];
    }
}

// returns int index of where a sequence of numbers is in given array
void findSequence(int array[], int size, int num1, int num2) {
    int index = -1;
    for(int i = 0; i < size; i++) {
        if((array[i] == num1) && array[i+1] == num2) {
            printf("\tSequence found at index %d", i);
            index = i;
        }
    }
    if(index == -1) {
        printf("\tSequence not found");
    }
}
