class Solution {
public:
    int solve(string s,int i,vector<int> &dp){
        int n=s.size();
        if(i==n)return 1;
        if(s[i]=='0')return 0;
        if(dp[i] != -1) return dp[i];

        int way=solve(s,i+1,dp);

        if(i+1 <n){
            int num=stoi(s.substr(i,2));
            if(num >=10 && num<=26){
                way += solve(s,i+2,dp);
            }

        }
        return dp[i]=way;
        
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1); 
        return solve(s,0,dp);
        
    }
};