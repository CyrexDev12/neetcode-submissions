class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false; 
        }

        int idx = 0; 

        while (!t.empty()) {
            bool found = false; 
          
            char curr = s[idx]; 

            for (int i = 0; i < t.size(); i++) {
                if (curr == t[i]) {
                    found = true; 
                    t.erase(i, 1); // Remove one character at index
                 //   cout << "Curr: " << curr << " IDX: " << idx << " Erasing: " << t[i] << " At Index: " << i << endl; 
                    break;
                }

            }

            if (!found) {
                return false; 
            }

            idx++;

        }

        return true; 




    }
};
