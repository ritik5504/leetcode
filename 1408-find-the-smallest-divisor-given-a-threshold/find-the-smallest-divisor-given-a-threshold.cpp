class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
         int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            int sum=0;
            for(int num:nums)
                sum+=(num+mid-1)/mid;
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }   else{
                low=mid+1;
            }

        }
        return ans;
    }
};