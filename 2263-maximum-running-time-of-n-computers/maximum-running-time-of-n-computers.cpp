class Solution {
public:
    bool solve(long long t, int n, vector<int>& batteries){
        long long time=0;
        for(long long b:batteries){
            time += min(b,t);
        }
        return time >= t*n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long left=0,right=0;
        long long ans=0;

        for(int b:batteries){
            right+=b;
        }
        right /=n;

        while(left<=right){
            long long mid=left+(right-left)/2;

            if(solve(mid,n,batteries)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
        
    }
};