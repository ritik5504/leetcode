class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int start=0,curr=0,maxSum=0;
        for(int end=0;end<nums.size();end++){
            while(seen.count(nums[end])){
                seen.erase(nums[start]);
                curr -= nums[start];
                start++;
            }
            seen.insert(nums[end]);
            curr += nums[end];

             maxSum=max(maxSum,curr);
        }
        return maxSum;
       
        
    }
};