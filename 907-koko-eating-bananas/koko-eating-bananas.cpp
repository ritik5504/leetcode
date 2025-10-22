class Solution {
public:
    bool solve(vector<int>& piles,int k,int h){
        long long hour=0;

        for(int pile:piles){
            hour += (pile +k-1)/k;

        }return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=right;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(solve(piles,mid,h)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};