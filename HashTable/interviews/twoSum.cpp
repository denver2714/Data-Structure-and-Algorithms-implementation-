#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) { // The O(n^2)
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }



int main() {
    std::vector<int> n = {2,7,11,15};
    int target = 9;

    std::vector<int> result = twoSum(n, target);
    for(int i: result){
        std::cout << i << " ";
    
    }

}