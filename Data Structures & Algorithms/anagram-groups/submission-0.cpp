class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> result; // Store result 
        unordered_map<string, vector<string>> myMap; // Int = map to first occurence of anogram

        for (int i = 0; i < strs.size(); i++) { 
            string sorted = strs[i]; 
            sort(sorted.begin(), sorted.end()); 
            if (myMap.find(sorted) != myMap.end()) {
                myMap[sorted].push_back(strs[i]);
            } else {
                myMap[sorted] = {strs[i]};
            }
    }

    for (auto& pair : myMap) {
        result.push_back(pair.second);
    }

    return result; 

    }

};
