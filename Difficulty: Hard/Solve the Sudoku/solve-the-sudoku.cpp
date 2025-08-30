class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isValid(int row , int col , int num ,vector<vector<int>>& board ){

        for(int x  = 0 ; x <=8 ; x++){
            if(board[row][x]== num)return false;
        }
        for(int x  = 0 ; x <=8 ; x++){
            if(board[x][col]== num)return false;
        }

        int startRow = row -(row % 3) , startCol= col - (col%3);
        set<char> st;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j <  3 ; j++){
               if(board[i+startRow][j+startCol] == num) return false;
            }
        }

        return true;
    }
    bool sodukuSolve(int row , int col ,vector<vector<int>>& board){
        int n = board.size();
        if(row == n-1 && col == n){
            return true;
        }

        if(col == n){
            row++;
            col =0;
        }


        if(board[row][col] !=0){
            return sodukuSolve(row , col+1 , board);
        }

        for(int num = 1 ; num <= 9 ; num++){

            if(isValid(row  , col ,num , board)){
                board[row][col] = num;
              
                if(sodukuSolve(row , col +1 , board)){
                    return true;
                }
                board[row][col] = 0;
            }
        }

        return false;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        sodukuSolve(0, 0 , mat);
        
        // for(auto t: mat){
        //     for(auto tt : t){
        //         cout << tt << " ";
        //     }
        //     cout << endl;
        // }
        
    }
};