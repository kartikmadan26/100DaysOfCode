//Question
// 576. Out of Boundary Paths
// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

// Example 1:
// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
  
// Example 2:
// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12
 
// Constraints:
// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n
//Solution
class Solution {
public:
    int mod=1e9+7;
    int helper(int m,int n,int num,int row,int col,vector<vector<vector<int>>> &dp){
        if(row==m || col==n || row<0 || col<0){
            return 1;
        }
        if(num==0){
            return 0;
        }
        if(dp[row][col][num]!=-1){
            return dp[row][col][num];
        }
        int ans=((helper(m,n,num-1,row-1,col,dp)+
                helper(m,n,num-1,row+1,col,dp))%mod+
                (helper(m,n,num-1,row,col+1,dp)+
                helper(m,n,num-1,row,col-1,dp))%mod)%mod;
        return dp[row][col][num]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // if(startRow==m || startRow<0 || startColumn==n || startColumn<0){
        //     return 1;
        // }
        // if(maxMove==0){
        //     return 0;
        // }
        // return findPaths(m,n,maxMove-1,startRow+1,startColumn)+
        //        findPaths(m,n,maxMove-1,startRow-1,startColumn)+
        //        findPaths(m,n,maxMove-1,startRow,startColumn+1)+
        //        findPaths(m,n,maxMove-1,startRow,startColumn-1);
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return helper(m,n,maxMove,startRow,startColumn,dp);
    }
};
