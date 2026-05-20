class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap; // Int Arr[i], int count
        vector<int> result; 

        for (int i = 0; i < nums.size(); i++) {

            if (myMap.find(nums[i]) != myMap.end()) { // See if already exists in HashMap
                myMap[nums[i]] += 1; 
            } else {
                myMap[nums[i]] = 1; // If doesnt exist we create it and set it to 1
            }

        }


        // Return in ascending order with respect to k
        // Find the first most frequent, second most frequent, all the way to kth most frequent 
        int n = 1; 

        while (n <= k) {
        int maxVal = INT_MIN; 
        int maxKey = 0; 

        for (auto& pair : myMap) { // Get Max at kth position
            if (pair.second > maxVal) {
                maxVal = pair.second;
                maxKey = pair.first; 
            }
           // cout << "n = " << n << " Pair First: " << pair.first << " Pair Second: " << pair.second << endl; 

        }
        // Now we add that max key to the array, and then set its pair.second to zero
        result.push_back(maxKey);
        myMap[maxKey] = 0; 

        n++;
        }

        return result; 

    }
};
