class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // a '.' is used to indicate that a slot is empty 
        // to check if a slot is 1-10, we do 10 - arr[i][j], if it returns > 10, or < 0, then it is not 1-10. 
        // To check for duplicates in a row we use a hash map for each row iterated, then check if count is > 1 for any of the elements
        // To check for duplicates in a column we cant do that until 

        int n = board.size(); // Gaurenteed to be n x n
        int r = 0; 
        int c = 0;  
        int count = 0;
        
        while (count < n) { // Checking individual subsquares
            unordered_set<int> seen; // Set is perfect here as it cannot contain duplicates 

            if (c == 9) {
                r += 3; 
                c = 0; 
            }

        for (int i = r; i < r + 3; i++) {

            for (int j = c; j < c + 3; j++) {

                if (isdigit(board[i][j])) {
                    int num = board[i][j] - '0'; // Recall that chars operate differently, and we need to convert

                    if ((10 - num) > 10 || (10 - num) < 0) { // Check if 1-9 
                  //  cout << "Returned False! Digit is not 1-9| Digit: " << num << " At indicies: (" << i << " , " << j << ")" << endl; 
                    return false;  
                     }

                    if (seen.find(num) != seen.end()) { // If it already exists in the set, we know its a duplicate value
                       //  cout << "Returned False! Duplicate found! | Digit: " << num <<  " At indicies: (" << i << " , " << j << ")" << endl;
                         return false; 
                    } 
                     else { // Add it to the set if not on there 
                        seen.insert(num);
                    }

                   

                }



            }
        }


        count++;
        c += 3; 

        }

        // Checking rows 
        for (int i = 0; i < board.size(); i++) {
            unordered_set<int> seenRow;
            unordered_set<int> seenCol;
            for (int j = 0; j < board[i].size(); j++) {

                if (isdigit(board[i][j])) {

                int numRow = board[i][j] - '0';
                if (seenRow.find(numRow) != seenRow.end()) {
                   // cout << "Returned False! Digit is a duplicate value in row " << i << " At indicies: (" << i << " , " << j << ")" << endl; 
                    return false; 
                } else {
                    seenRow.insert(numRow);
                }

                }

                if (isdigit(board[j][i])) {

                int numCol = board[j][i] - '0';

                if (seenCol.find(numCol) != seenCol.end()) {
                    // cout << "Returned False! Digit is a duplicate value in col" << j << " At indicies: (" << i << " , " << j << ")" << endl; 
                    return false; 
                } else {
                    seenCol.insert(numCol);
                }


                }




            }

        }



        return true; 


    }
};
