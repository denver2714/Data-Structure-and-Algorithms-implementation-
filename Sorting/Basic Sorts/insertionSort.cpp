#include <iostream>


void insertionSort(int array[], int size){
    for(int i = size - 1; i >0; i--){
        int temp = array[i];
        int j = i - 1;
        while(j > -1 && temp < array[j]){
            array[j+1] = array[j]; // assign the previous j to next j
            array[j] = temp; // initially put j to current
            j--; // then decrement j so it becomes previous
        }
    }
}


int main(){
    int myArray[] = {6,4,2,5,1,3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    insertionSort(myArray, size);

    for(auto value: myArray){
        std::cout << value << " ";
    }

    return 0;
}