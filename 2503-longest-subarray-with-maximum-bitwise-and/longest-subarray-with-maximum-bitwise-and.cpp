class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv=*max_element(nums.begin(),nums.end());

        int curr=0,maxlen=0;

        for(int num:nums){
            if(num==maxv){
                curr++;
                maxlen=max(maxlen,curr);
            }else{
                curr=0;
            }
        }
        return maxlen;
        
    }
};