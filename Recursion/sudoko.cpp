#include <iostream>
#include <vector>

using namespace std;

/*
🧠 Intuition:
We use backtracking to fill empty cells ('.') with digits '1' to '9'. 
At each empty cell, we try every valid digit. 
If placing a digit doesn't violate Sudoku rules (row, column, and 3x3 box), we proceed to fill the next cell.
If at any point no digit works, we backtrack (undo the last move) and try another option.

The `isValid` function checks if placing a number is allowed.

Once all cells are filled validly, we’ve solved the puzzle.
*/

// 🔎 Function to check if placing digit c at board[row][col] is valid
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        // Check column
        if (board[i][col] == c)
            return false;
        
        // Check row
        if (board[row][i] == c)
            return false;
        
        // Check 3x3 subgrid
        // 🔍 Check if digit c is already in the same 3x3 subgrid:

        // Let's say (row, col) = (4, 5)
        // Then its subgrid starts at:
        //     3 * (row / 3) = 3 * (4 / 3) = 3
        //     3 * (col / 3) = 3 * (5 / 3) = 3
        // So subgrid is from (3,3) to (5,5)

        // We loop i from 0 to 8 to cover all 9 cells inside the subgrid:
        //     - Row inside subgrid: 3*(row/3) + i/3
        //     - Col inside subgrid: 3*(col/3) + i%3
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

// 🧩 Backtracking function to solve Sudoku
bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // If the cell is empty
            if (board[i][j] == '.') {
                // Try all digits from '1' to '9'
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c; // place the digit

                        // Recurse: try to fill rest of board
                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.'; // backtrack if not solvable
                    }
                }

                // No digit fits here, must backtrack
                return false;
            }
        }
    }
    return true; // All cells filled correctly
}

int main() {
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    solveSudoku(board);

    // ✅ Print the solved board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

/*
📊 Time Complexity (TC):
- Worst-case: O(9^(n)) where n is the number of empty cells.
  At each cell, we try at most 9 options, and potentially backtrack all the way.
- But due to pruning via isValid, it's much faster in practice.

🧠 Space Complexity (SC):
- O(1) extra space (in-place)
- But recursion stack may go up to O(n), where n is number of empty cells.

📝 Note for future revision:
- Could optimize using bitsets for row/col/box tracking.
- Could preprocess empty cells list to avoid scanning full board each time.
*/
