class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dia(m + n - 1);

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dia[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

      
        for(int d = 0; d < dia.size(); d++) {
            if(d % 2 == 0) {
                reverse(dia[d].begin(), dia[d].end());
            }
            for(int val : dia[d]) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};
