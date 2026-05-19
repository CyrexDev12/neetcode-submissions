class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> myMap; // Initate HashMap 


        for (int i = 0; i < nums.size(); i++) {
            if (myMap[nums[i]] == 1) { 
                return true;
            }

            myMap[nums[i]] += 1;
            
        }  

        return false; 


    }
};