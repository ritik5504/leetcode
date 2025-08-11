class Solution {
public:
    int solve(vector<vector<int>>& cuboids, int n, int curr, int pre, vector<vector<int>>& dp) {
        if (curr == n) return 0; 

        if (dp[curr][pre + 1] != -1) return dp[curr][pre + 1];

        int inc = 0;
        
        if (pre == -1 ||
            (cuboids[curr][0] <= cuboids[pre][0] &&
             cuboids[curr][1] <= cuboids[pre][1] &&
             cuboids[curr][2] <= cuboids[pre][2])) {
          
            inc = cuboids[curr][2] + solve(cuboids, n, curr + 1, curr, dp);
        }

        
        int exc = solve(cuboids, n, curr + 1, pre, dp);

        return dp[curr][pre + 1] = max(inc, exc);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        for (auto &c : cuboids) {
            sort(c.begin(), c.end());
        }

        
        sort(cuboids.begin(), cuboids.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] > b[0];
            if (a[1] != b[1]) return a[1] > b[1];
            return a[2] > b[2];
        });

        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        
        return solve(cuboids, n, 0, -1, dp);
    }
};
