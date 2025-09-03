class Solution {
public:
    int solve(int idx,int pre,vector<vector<int>>& pairs, vector<vector<int>>&dp){
        if(idx==pairs.size()) return 0;

        if(dp[idx][pre+1] != -1) return dp[idx][pre+1];

        int take=0;
        if(pre==-1|| pairs[pre][1]<pairs[idx][0]){
            take=1+solve(idx+1,idx,pairs,dp);
        }
        int skp=solve(idx+1,pre,pairs,dp);

        return  dp[idx][pre+1]=max(take,skp);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,pairs,dp);
    }
};