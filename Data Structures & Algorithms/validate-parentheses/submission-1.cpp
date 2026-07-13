class Solution {
public:

    
    bool isOpen(char c) {
        return c == '(' || c == '{' || c == '[';
    }

bool isValidPair(char open, char close) {
    static const std::unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    return pairs.count(close) && pairs.at(close) == open;
}


    bool isValid(string s) {
        // Every open brakcet is closed by the same type of close bracket
        // Open brackets are closed in the correct order
        // Every close bracket has a corresponding open bracket of the same type 
        
        if (s.empty() || s.length() % 2 != 0) {
            return false; 
        }

        // VARS 
        stack<char> stck;
        int iterLen = s.length() / 2;

        // Populate the stack
        for (int i = 0; i < s.length(); i++) {
            stck.push(s[i]); 
        }

        int count = 0; 
        while (iterLen != 0) {
            cout << "Iteration num: " << count << endl; 
            char curr = stck.top(); 
            stck.pop(); 

            if (isValidPair(stck.top(), curr)) {
            // Is validPair(char open, char close)
            // Returns true if open and close are indeed a pair 
                stck.pop(); 
            } else if (!isValidPair(s[count], curr)) {
             cout << "Is not a valid pair! " << "s: " << s[count] << " curr: " << curr << endl;
                return false;  
           }

            count++; 
            iterLen--; 
        }
         

        return true; 

    }



};
