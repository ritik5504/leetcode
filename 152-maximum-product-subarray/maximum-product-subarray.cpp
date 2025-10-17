class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int currMax=nums[0];
        int currMin=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++){
            int temp=currMax;
            currMax=max({nums[i],nums[i]*currMax,nums[i]*currMin});
            currMin=min({nums[i],nums[i]*temp,nums[i]*currMin});
            ans=max(currMax,ans);
        }
        return ans;
    }
};