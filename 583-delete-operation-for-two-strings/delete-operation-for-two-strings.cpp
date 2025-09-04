class Solution {
public:
    int solve(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans=0;
        if(a[i]==b[j]){
            return solve(a,b,i+1,j+1,dp);
        }else{
            int dele1=1+solve(a,b,i+1,j,dp);
            int dele2=1+solve(a,b,i,j+1,dp);
            ans=min(dele1,dele2);

        }
        return dp[i][j]= ans;

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        
        vector<vector<int>>dp(n,vector<int>(m,-1));


        return solve(word1,word2,0,0,dp);
        
    }
};