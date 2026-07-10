class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0; 
        }

        // Using unordered_set
        unordered_set<int> s(nums.begin(), nums.end()); 
        // Start counting from numbers that dont have predecessors
        // (x - 1 not in the set). 
        int longest = 0; 
        int curr = 0; 
        for (auto& elem : s) {
            if (!s.contains(elem - 1)) {
                int count = 1; 
                curr = elem; 

                while (s.count(curr + 1)) {
                    curr++; 
                    count++; 
                }

                longest = max(longest, count); 
        }

        }   


        return longest; 


    }
};
