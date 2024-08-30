//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool ok(int i , int j , int num , int grid[N][N]){
        
       
       int row =i;
       int col = j;
       
       for(int x =0 ; x < 9 ; x++){
           if(grid[row][x] == num){
               return false;
           }
       }
       for(int x =0 ; x < 9 ; x++){
           if(grid[x][col] == num){
               return false;
           }
       }
       
       
       int st = row - row% 3;
       int en = col - col% 3;
       
       for(int p = 0 ; p< 3 ; p++){
           for(int q = 0 ; q < 3 ; q++){
               if(grid[p+st][q+en] == num){
                   return false;
               }
           }
       }
       
       return true;
       
       
    }
    
    bool solve(int row , int col , int grid[N][N]){
        
        if(col >= N){
            
            row++;
            col =0;
            if(row >= N){
                return true;
                
            }
        }
        if(grid[row][col]> 0){
            return solve(row  , col+1 , grid);
        }
        
        for(int val = 1 ; val <= 9 ; val++){
            
            if(ok(row , col , val , grid)){
                
                grid[row][col]=val;;
                
                if(solve(row , col+1 , grid)){
                    return true;
                }
            }
            grid[row][col]=0;
            
        }
        
        return false;
        
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
       return  solve(0 ,0 , grid);
        
        
      
    }
    
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ;j < N ; j++){
                cout << grid[i][j]<< " ";
            }
           // cout << endl;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends