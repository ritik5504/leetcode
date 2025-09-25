class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];
        
        for(int i = 1; i < n; i++) {
            int num = nums[i];
            int tempMax = max({num, num * currMax, num * currMin});
            int tempMin = min({num, num * currMax, num * currMin});
            
            currMax = tempMax;
            currMin = tempMin;
            
            ans = max(ans, currMax);
        }
        
        return ans;
    }
};
