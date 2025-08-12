class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int n, int x,int curr,vector<vector<int>>&dp){

        long long power=pow(curr,x);

        if(power>n) return 0;
        if(power==n) return 1;

        if(dp[n][curr] != -1) return dp[n][curr];

        int take=solve(n-power,x,curr+1,dp)%MOD;
        int skip=solve(n,x,curr+1,dp)%MOD;

        return dp[n][curr]=(take+skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,1,dp);
    }
};