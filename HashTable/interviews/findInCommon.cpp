#include <iostream>
#include <unordered_map>
#include <vector>



    //Interview Question!
    //check 2 arrays/vector if there are in common ex. [1,3, 5] and [2,4,5]
    // 5 is common, return true
    //Using hash table is O(n)

bool itemInCommon(const std::vector<int>& vect1, const std::vector<int>& vect2){
    std::unordered_map<int, bool> myMap;
    for(int i : vect1){
        myMap.insert({i, true}); //or  myMap[i] = true;
    }
    for(int j: vect2){
        if(myMap[j]) return true; // or even better  if (myMap.find(j) != myMap.end()) return true;
    }
    return false;
}


int main(){
    std::vector<int> vect1 {1,3,5};
    std::vector<int> vect2 {2,4,5};
    
    std::cout << std::boolalpha;
    std::cout << itemInCommon(vect1, vect2);
    return 0;
}