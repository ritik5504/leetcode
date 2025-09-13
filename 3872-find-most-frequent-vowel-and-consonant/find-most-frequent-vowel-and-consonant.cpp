class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26];
        int vow = 0, cons = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vow = max(vow, freq[i]);
            }
            else {
                cons = max(cons, freq[i]);
            }
        }
        return vow + cons;
    }
};