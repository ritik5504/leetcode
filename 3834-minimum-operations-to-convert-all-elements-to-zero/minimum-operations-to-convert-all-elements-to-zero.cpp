class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long ans=0;
        vector<int>st;

        for(int x:nums){
            if(x==0){
                ans += st.size();
                st.clear();
                continue;
            }

            while(!st.empty() && st.back()>x){
                ans++;
                st.pop_back();
            }
            if(!st.empty() && st.back()==x)continue;

            st.push_back(x);
        }
        ans += st.size();

        return (int)ans;
        
    }
};