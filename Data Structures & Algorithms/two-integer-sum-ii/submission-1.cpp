class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hmap; // key: Comp, Store: Other index 
        int comp = 0; 
        vector<int> result; 

        for (int i = 0; i < numbers.size(); i++) {

            // Get ze complement 
            comp = target - numbers[i]; 

            if (hmap.find(numbers[i]) != hmap.end()) {
                result.emplace_back(hmap[numbers[i]] + 1); // + 1 b/c 1 indexed
                result.emplace_back(i + 1); // i + 1 because is 1 indexed 
                break; 
            }

            // Store in a HashMap 
            hmap[comp] = i; 
        }

        return result; 
    }
};
