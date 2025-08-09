class Solution {
public:
    int solve(vector<int>& satisfaction,int idx,int time, vector<vector<int>>&dp){
        if(idx==satisfaction.size()) return 0;
        if(dp[idx][time] != -1) return dp[idx][time];

        int inc=satisfaction[idx]*(time+1)+solve(satisfaction,idx+1,time+1,dp);
        int exc=solve(satisfaction,idx+1,time,dp);

        return dp[idx][time]= max(inc,exc);

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(satisfaction,0,0,dp);
    }
};