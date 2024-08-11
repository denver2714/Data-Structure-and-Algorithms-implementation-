#include <iostream>

void swap(int array[], int firstIndex, int secondIndex){
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex){ // Goal: to sort the first index in the array
    int swapIndex = pivotIndex;
    for(int i = pivotIndex + 1; i <= endIndex; i++){
        if(array[i] < array[pivotIndex]){
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex; //returns the index not the value
}

void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return;
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);  //first from the left
    quickSort(array, pivotIndex+1, rightIndex); //second from the right
}


int main(){
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    //Code for Pivot function
    // int returnedIndex = pivot(myArray, 0, size-1);
    // std::cout << "Returned Index: " << returnedIndex << "\n\n";

    for(auto value: myArray){
        std::cout << value << " ";
    }

    return 0;
}