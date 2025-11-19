class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();

        while(true){
            bool ans=false;

            for(int i=0;i<n;i++){
                if(nums[i]==original){
                    original *= 2;
                    ans=true;
                    break;
                }
                

            }
            if(!ans){
                    break;
                }
        }
        return original;
        
    }
};