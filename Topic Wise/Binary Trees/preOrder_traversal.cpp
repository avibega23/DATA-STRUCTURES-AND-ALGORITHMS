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
        void preOrder(vector<int>&nums,TreeNode* root)
        {
            if(root == NULL) return;
            
            nums.push_back(root->val);
            preOrder(nums,root->left);
            preOrder(nums,root->right);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int>ans;
            preOrder(ans,root);
            return ans;
        }
    };