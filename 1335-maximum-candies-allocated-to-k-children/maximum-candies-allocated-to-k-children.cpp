class Solution {
public:
    int solve(vector<int>& candies, long long k,long long mid){
        long long total=0;
        for(long long c:candies){
            total += c/mid;
        }
        return total >=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long left=1;
        long long right = *max_element(candies.begin(),candies.end());
        long long ans=0;

        while(left <= right){
            long long mid=left +(right - left)/2;
            if(solve(candies,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
    }
};