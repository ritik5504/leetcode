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
    bool valid(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;

        if(node->val<=minVal || node->val>=maxVal){
            return false;
        }
        return valid(node->left,minVal,node->val)&&
        valid(node->right,node->val,maxVal);
    }
    


   
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN, LONG_MAX);
        
    }
};