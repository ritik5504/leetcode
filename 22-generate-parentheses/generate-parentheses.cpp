class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0]={""};

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string in:dp[j]){
                    for(string out:dp[i-1-j]){
                        dp[i].push_back("("+in+")"+out);
                    }
                }
            }
        }
        return dp[n];
        
    }
};