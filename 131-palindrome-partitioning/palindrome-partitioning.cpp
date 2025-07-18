class Solution {
private:
    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
    void solve(string &s,vector<string>output,int index,vector<vector<string>>&ans){
        if(index==s.length()){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                output.push_back(s.substr(index,i-index+1));
                solve(s,output,i+1,ans);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
        int index=0;
        solve(s,output,index,ans);
        return ans;
        
    }
};