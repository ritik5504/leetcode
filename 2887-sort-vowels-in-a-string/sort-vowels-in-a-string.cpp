class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        unordered_set<char>v={'A','E','I','O','U','a','e','i','o','u'};

        for(char c:s){
            if(v.count(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (char &c : s) {
            if (v.count(c)) {
                c = vowels[j++];
            }
        }

        return s;
        
    }
};