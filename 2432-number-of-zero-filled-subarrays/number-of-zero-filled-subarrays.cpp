class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        // int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                long long r = i+1;
                long long count = 1;
                while(r < nums.size() && nums[r] == 0){
                    r++;
                    count++;
                }
                ans += (count*(count+1))/2;
                i = r-1;
            }
        }
        return ans;

        
    }
};