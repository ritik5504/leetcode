class Solution {
public:
    int solve(vector<int>& obstacles,int curr,int pos,vector<vector<int>>&dp){
        int n=obstacles.size()-1;
        if(pos == n) return 0;

        if(dp[curr][pos] != -1) return dp[curr][pos];

        if(obstacles[pos+1] != curr){
            return solve(obstacles,curr,pos+1,dp);
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(curr != i && obstacles[pos] != i){
                    ans=min(ans,1+solve(obstacles,i,pos,dp));
                }
            }
            dp[curr][pos]=ans;
            return dp[curr][pos];

        }
        
    }
    int minSideJumps(vector<int>& obstacles) {
       vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solve(obstacles,2,0,dp);
        
    }
};