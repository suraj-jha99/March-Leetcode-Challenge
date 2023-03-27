class Solution {
public:
    //approach 2:: Recursion + Memo
    int cost(int i,int j,int row,int col,vector<vector<int>>& mat,vector<vector<int>> &dp){
        if(i>=row || j>=col)
            return INT_MAX; //returning 0 will make this invalid path's cost less/minm.
        
        if(i==row-1 && j==col-1)
            return mat[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int cost1=cost(i+1,j,row,col,mat,dp);
        int cost2=cost(i,j+1,row,col,mat,dp);
        
        return dp[i][j] = mat[i][j] + min(cost1,cost2);
    }
    int minPathSum(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return cost(0,0,r,c,mat,dp);
    }
};
