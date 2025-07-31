class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv=*max_element(nums.begin(),nums.end());
        int curr=0;
        int maxlen=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxv){
                curr++;
                maxlen=max(maxlen,curr);
            }else{
                curr= 0;
            }
        }
        return maxlen;
        
    }
};