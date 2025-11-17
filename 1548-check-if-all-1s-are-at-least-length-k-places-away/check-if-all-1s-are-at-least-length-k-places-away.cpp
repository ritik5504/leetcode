class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lst=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(lst != -1 && (i-lst-1)<k){
                    return false;
                }
                lst=i;
            }
        }
        return true;
    }
};