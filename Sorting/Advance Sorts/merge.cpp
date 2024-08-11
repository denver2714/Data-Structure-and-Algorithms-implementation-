#include <iostream>


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex - leftIndex + 1; //mid index is 3 if there 8 list, indices (0-7) index 3 is middle
    int rightArraySize = rightIndex - midIndex; // right index is last index and left index is beginning of the array, first index

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for(int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i]; //store the left side here
     for(int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[midIndex + 1 + j];
    
    int index = leftIndex;
    int i = 0; //index for left array
    int j = 0; //index for right array
    while(i < leftArraySize && j < rightArraySize){ //run until the 2 arrays are empty
        if(leftArray[i] <= rightArray[j]){
            array[index] = leftArray[i]; //Whole array to store the compared values
            index++;//moves the index for the whole array
            i++; // moves the index from the left array
        }else{
            array[index] = rightArray[j];
            index++;
            j++; // Now moves the index from the right
        }
    }
    //These 2 while loops only covers when we only have one array left, either right or left
    while(i < leftArraySize){
        array[index] = leftArray[i];
        index++;
        i++;
    }
    while(j < rightArraySize){
        array[index] = rightArray[i];
        index++;
        j++;
    }
}

int main(){
    int myArray[] = {1,3,7,8,2,4,5,6};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size/2) - 1;

    merge(myArray, leftIndex, midIndex, rightIndex);

    for(auto value: myArray){
        std::cout << value << " ";
    }

    return 0;
}