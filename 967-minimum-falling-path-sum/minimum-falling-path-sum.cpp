class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if (j < 0 || j >= n) return 1e9;

        if(i==n-1 ) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int leftdio=matrix[i][j]+ solve(i+1,j-1,n,m,matrix,dp);
        int down=matrix[i][j]+solve(i+1,j,n,m,matrix,dp);
        int rightdio=matrix[i][j]+solve(i+1,j+1,n,m,matrix,dp);

        return dp[i][j]=min(leftdio,min(down,rightdio));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        int ans=1e9;
        for(int j=0;j<n;j++){
            ans=min(ans,solve(0,j,n,m,matrix,dp));
        }
        return ans;
      
    }
};