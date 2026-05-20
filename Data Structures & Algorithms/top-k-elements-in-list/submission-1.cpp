class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket Sort implementation
        unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    vector<vector<int>> buckets(nums.size() + 1);

    for (auto& pair : freq) {
        int num = pair.first;
        int count = pair.second;

        buckets[count].push_back(num);
    }

    vector<int> result;

    for (int i = buckets.size() - 1; i >= 0; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);

            if (result.size() == k) {
                return result;
            }
        }
    }

    return result;

    }
};
