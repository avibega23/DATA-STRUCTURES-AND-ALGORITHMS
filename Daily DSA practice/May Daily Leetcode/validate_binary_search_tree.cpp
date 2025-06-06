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
        bool preorder(TreeNode* root,long long left,long long right)
        {
            if(root == NULL) return true;
            if(root->val <= left || root->val >= right) return false;
            return preorder(root->left,left,root->val) && preorder(root->right,root->val,right);
    
    
        }
        bool isValidBST(TreeNode* root) {
            if(root == NULL) return true;
            return preorder(root->left,LLONG_MIN,root->val) && preorder(root->right,root->val,LLONG_MAX);
        }
    };