/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=INT_MIN;
    int solve(TreeNode* root){
        if(root==nullptr)return 0;

        int l=solve(root->left);
        int r=solve(root->right);

        int allMax=l+r+root->val;
        int oneMax=max(l,r)+root->val;
        int rootMax=root->val;

        maxSum=max({maxSum,allMax,oneMax,rootMax});

        return max(oneMax,rootMax);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
        
    }
};