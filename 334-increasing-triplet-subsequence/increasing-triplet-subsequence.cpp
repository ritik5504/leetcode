class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;

        for(int i=0;i<n;i++){
            int ans=nums[i];

            if(ans <= first){
                first=ans;
            }else if(ans <= second){
                second=ans;
            }else{
                return true;
            }
        }
        return false;

        
    }
};