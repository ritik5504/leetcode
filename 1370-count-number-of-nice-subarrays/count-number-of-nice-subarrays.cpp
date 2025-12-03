class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0,odd=0;

        for(int i:nums){
            odd += (i%2);

            if(mp.find(odd-k ) != mp.end()){
                count += mp[odd-k];
            }
            mp[odd]++;
        }
        return count;
        
    }
};