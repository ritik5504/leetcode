class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int>nums;
        for(auto &it:intervals){
            int start=it[0];
            int end=it[1];

            int count=0;

            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>end)continue;
                if(nums[i]<start) break;
                count++;
                if(count==2) break;
            }
            while(count<2){
                nums.push_back(end-(1-count));
                count++;
            }
        }
        return nums.size();
    }
};