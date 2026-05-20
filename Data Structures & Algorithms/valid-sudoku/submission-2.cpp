class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Cleaned up version 
        int n = board.size(); // 9 for standard Sudoku

        // Check all 3x3 boxes
        for (int boxRow = 0; boxRow < n; boxRow += 3) {
            for (int boxCol = 0; boxCol < n; boxCol += 3) {
                unordered_set<char> seen;

                for (int row = boxRow; row < boxRow + 3; row++) {
                    for (int col = boxCol; col < boxCol + 3; col++) {
                        char val = board[row][col];

                        if (val == '.') continue;

                        if (val < '1' || val > '9') {
                            return false;
                        }

                        if (seen.find(val) != seen.end()) {
                            return false;
                        }

                        seen.insert(val);
                    }
                }
            }
        }

        // Check rows and columns
        for (int i = 0; i < n; i++) {
            unordered_set<char> seenRow;
            unordered_set<char> seenCol;

            for (int j = 0; j < n; j++) {
                char rowVal = board[i][j];
                char colVal = board[j][i];

                // Row check
                if (rowVal != '.') {
                    if (rowVal < '1' || rowVal > '9') {
                        return false;
                    }

                    if (seenRow.find(rowVal) != seenRow.end()) {
                        return false;
                    }

                    seenRow.insert(rowVal);
                }

                // Column check
                if (colVal != '.') {
                    if (colVal < '1' || colVal > '9') {
                        return false;
                    }

                    if (seenCol.find(colVal) != seenCol.end()) {
                        return false;
                    }

                    seenCol.insert(colVal);
                }
            }
        }

        return true;
    }
};