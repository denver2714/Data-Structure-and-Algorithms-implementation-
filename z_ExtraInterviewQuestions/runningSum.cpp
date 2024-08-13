#include <iostream>
#include<vector>

// Input [1,2,3]
// 1, 1+2, 1+2+3
// Output [1,3,6]

std::vector<int> sums(const std::vector<int>& vecs){
    std::vector<int> addedVector;
    int toBeAdded{0};
    for(int v: vecs){
        toBeAdded += v;
        addedVector.push_back(toBeAdded);
    }
    return addedVector;
}


int main(){
    std::vector<int> myVec = {1,2,3,4,5};
    std::vector<int> results = sums(myVec);


    std::cout << "Original vector: ";
    for(int v : myVec){ std::cout << v << " "; }

    std::cout << "\n";

    std::cout << "Summed vector: "; 
    for(int r : results) { std::cout << r << " "; }

    return 0;
}