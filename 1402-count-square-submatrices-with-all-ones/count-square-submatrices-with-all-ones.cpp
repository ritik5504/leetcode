class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(matrix[i][j]==0) return 0;

        int top=solve(i-1,j,matrix,dp);
        int left=solve(i,j-1,matrix,dp);
        int dio=solve(i-1,j-1,matrix,dp);

        return dp[i][j]= 1+min({top,left,dio});


    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total += solve(i,j,matrix,dp);
            }
        }
        return total;
        
    }
};