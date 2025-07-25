class Solution {
public:

    int solve(vector<int>& nums,int start,int end){
        int pre1=0,pre2=0;
        for(int i=start;i<end;i++){
            int curr=max(pre1,nums[i]+pre2);
            pre2=pre1;
            pre1=curr;
        }
        return pre1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int case1=solve(nums,0,n-1);
        int case2=solve(nums,1,n);
        return max(case1,case2);


        
    }
};