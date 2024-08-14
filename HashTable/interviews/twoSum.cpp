#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> prevMap; // value : index
    
    for (int i = 0; i < nums.size(); ++i) {
        int diff = target - nums[i];
        
        if (prevMap.find(diff) != prevMap.end()) {
            return {prevMap[diff], i}; // Return indices if the solution is found
        }
        
        prevMap[nums[i]] = i; // Store the index of the current number
    }
    
    return {}; // Return an empty vector if no solution is found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    std::vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }
    
    return 0;
}
