class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // note: don't overcomplicate by thinking of the unfilled position
        // Hashset unique: for rows 
        // Hashet columns: determine any duplicate
        // Time: Size of entrie grid (insert & check) O(9^2), same with memory
        // Hashset: check 3x3 grid
        // We can have 3 x 3 hashmap of subsquares (indices to represent them)
        // eg: 4 / 3 = 1, 4 / 3 = 1 (take the coordinates and integer divide by 3 = get the subsquare)
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') 
                    continue;
                int idx = board[i][j] - '0' - 1;
                int area = (i/3) * 3 + (j/3);

                if(row[i][idx] || col[j][idx] || sub[area][idx]) {
                    return false;
                }
                row[i][idx] = true;
                col[j][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};