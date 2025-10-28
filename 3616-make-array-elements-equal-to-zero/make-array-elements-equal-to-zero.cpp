class Solution {

public:
    bool solve(vector<int> nums,int curr,int dir){
        int n=nums.size();

        while(curr>=0 && curr<n){
            if(nums[curr]==0){
                curr += dir;
            }
            else if(nums[curr]>0){
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }          
        }
        for(int x : nums){
                if(x != 0) return false;
            }
            return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(solve(nums,i,-1)) count++;
                if(solve(nums,i,+1)) count++;
            }
        }
        return count;
        
    }
};