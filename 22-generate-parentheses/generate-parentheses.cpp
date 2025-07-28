class Solution {
public:
    void solve(int oc, int cc, string curr, vector<string>& ans, int n) {
        if (oc == n && cc == n) {
            ans.push_back(curr);
            return;
        }

        if (oc < n) {
            solve(oc + 1, cc, curr + '(', ans, n);
        }

        if (cc < oc) {
            solve(oc, cc + 1, curr + ')', ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0, cc = 0;
        string curr = "";
        solve(oc, cc, curr, ans, n);  
        return ans;
    }
};
