class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;

       // get rid of any character that is not alphanumeric 
       string cleaned; 

       for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c); 
        }
       }

        int iters = cleaned.length() / 2;

        for (int i = 0; i < iters; i++) {
            int j = cleaned.length() - i - 1;

                // Lowercase it for simplicity 
            if (cleaned[i] != cleaned[j]) {
                return false;
            }
        }

        return true;
    }
};