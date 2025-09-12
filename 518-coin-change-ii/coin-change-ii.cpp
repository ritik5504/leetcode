class Solution {
public:
    int solve(int i,int amount, vector<int>& coins,vector<vector<int>>&dp){
        if(i==coins.size()){
            if(amount==0) return 1;
            else{
                return 0;
            }

        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int skp=solve(i+1,amount,coins,dp);
        int take=0;
        if(coins[i]<=amount){
            take=solve(i,amount-coins[i],coins,dp);

        }
        return dp[i][amount]=take+skp;
    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};