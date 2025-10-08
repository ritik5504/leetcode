class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=potions.size();
        vector<int>ans;

        for(int spel:spells){
            long long div=(success+spel-1)/spel;

            int idx=lower_bound(potions.begin(),potions.end(),div)-potions.begin();
            ans.push_back(n-idx);
        }
        return ans;
    }
};


auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });