class Solution {
public:
    int solve(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int time=i;time>=0;time--){
                int inc=satisfaction[i]*(time+1)+dp[i+1][time+1];
                int exc=dp[i+1][time];

                 dp[i][time]=max(inc,exc);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        return solve(satisfaction);
        
        
    }
};