class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        // if(n==2) return max(nums[0],nums[1]);

        int pre2=nums[0];
        int pre1=max(nums[0],nums[1]);
        int curr;

        for(int i=2;i<n;i++){
            curr=max(nums[i]+pre2,pre1);
            pre2=pre1;
            pre1=curr;
        }
        return pre1;
    }
};