class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; 

        int ans=1;

        for(int i=0;i<arr.size();i++){
            int curr=arr[i];

            if(dp.count(curr-difference)){
                dp[curr]=dp[curr-difference]+1;
            }else{
                dp[curr]=1;
            }
            ans=max(ans,dp[curr]);
        }
        return ans;
        
    }
};