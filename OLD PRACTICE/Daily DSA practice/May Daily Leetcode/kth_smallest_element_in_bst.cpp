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
        void inorder(TreeNode* root,int &value,int &cnt,int k)
        {
            if(root == NULL) return;
    
            inorder(root->left,value,cnt,k);
            cnt++;
            if(k == cnt)
            {
                value = root->val;
                return;
            }
            inorder(root->right,value,cnt,k);
        }
        int kthSmallest(TreeNode* root, int k) {
            int value = 0;
            int cnt = 0;
            inorder(root,value,cnt,k);
            return value;
        }
    };