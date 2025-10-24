class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int day) {
    int cons = 0, bouq = 0;
    for (int i : bloomDay) {
        if (i <= day) {
            cons++;
            if (cons == k) {
                bouq++;
                cons = 0; 
            }
        } else {
            cons = 0; 
        }
    }
    return bouq >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total=(long long )m*k;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(solve(bloomDay,m,k,mid)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
        
    }
};