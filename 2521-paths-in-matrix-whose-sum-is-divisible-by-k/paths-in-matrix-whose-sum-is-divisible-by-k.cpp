class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int m,n,key;

    int solve(int i,int j,int r,vector<vector<int>>& grid){
        int rem=(r+grid[i][j])%key;
        if(i==m-1 && j==n-1){
            return rem==0;
        }

        if(dp[i][j][r] != -1) return dp[i][j][r];

        long long ans=0;

        if(i+1<m){
            ans+= solve(i+1,j,rem,grid);
        }
        if(j+1<n){
            ans+=solve(i,j+1,rem,grid);
        }

        return dp[i][j][r]=ans%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         m=grid.size();
         n=grid[0].size();
         key=k;

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0,0,0,grid);

        
        
    }
};