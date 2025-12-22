class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total=0;

        for(int x:cost) total+=x;

        vector<long long>keep(26,0);

        for(int i=0;i<s.size();i++){
            keep[s[i]-'a'] += cost[i];
        }
        long long ans=total;
        for(int i=0;i<26;i++){
            if(keep[i]>0){
                ans=min(ans,total-keep[i]);

            }
        }
        return ans;
    }
};