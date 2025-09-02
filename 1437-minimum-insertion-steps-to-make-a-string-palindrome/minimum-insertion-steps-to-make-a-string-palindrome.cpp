class Solution {
public:
    int solve(string &s,int l,int r, vector<vector<int>>&dp){
        if(l>=r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l]==s[r]){
            return solve(s,l+1,r-1,dp);
        }else{
            int left=solve(s,l+1,r,dp);
            int right=solve(s,l,r-1,dp);

            return  dp[l][r]=1+min(left,right);
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
        
    }
};