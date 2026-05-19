class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result; 

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i]; 
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == comp && j != i) {
                    result = {i, j}; 
                    return result; 
                }
            }


        }

        return {-1, -1};


    }
};
