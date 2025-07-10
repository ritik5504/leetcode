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
private:
    int solve(TreeNode* node){
        if(!node)return 0;

        int leftmax=max(solve(node->left),0);
        int rightmax=max(solve(node->right),0);

        int curr=node->val+leftmax+rightmax;

        maxsum=max(maxsum,curr);
        return node->val+max(leftmax,rightmax);
    }
public:
    int maxsum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
        
    }
};