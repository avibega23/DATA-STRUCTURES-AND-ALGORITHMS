/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* preorder(TreeNode* root,TreeNode* p,TreeNode* q)
        {
            if((root->val <= p->val && root->val >= q->val)||(root->val >= p->val && root->val <= q->val)) return root;
    
            else if(p->val <= root->val && q->val <= root->val)
            {
                return preorder(root->left,p,q);
            }
            return preorder(root->right,p,q);
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return preorder(root,p,q);
        }
    };