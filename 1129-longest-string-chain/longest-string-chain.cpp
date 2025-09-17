class Solution {
public:
    bool pres(string& a,string& b){
        if(b.size() != a.size()+1) return false;
        int i=0,j=0;

        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
            
        }
        return i==a.length();

    }
     int solve(int curr,int pre,vector<string>& words,vector<vector<int>>&dp){
        if(curr==words.size()) return 0;
        if(dp[curr][pre+1] != -1) return dp[curr][pre+1];

        int take=0;
        if(pre==-1 || pres(words[pre],words[curr])){
            take=1+solve(curr+1,curr,words,dp);
        }
        int skip=solve(curr+1,pre,words,dp);

        return dp[curr][pre+1]=max(take,skip);
    }

      
        
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](string &a, string &b) {
        return a.size() < b.size();
        });

        
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0,-1,words,dp);
        
    }
};