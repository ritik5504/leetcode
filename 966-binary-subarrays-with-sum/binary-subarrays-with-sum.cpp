class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int ,int>mp;
        mp[0]=1;
        int prefix=0,count=0;

        for(int num:nums){
            prefix += num;

            if(mp.count(prefix-goal)){
                count+= mp[prefix-goal];

            }
            mp[prefix]++;
        }
        return count;
        
    }
};