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
            if(root == NULL || root == p||root == q)
            {
                return root;
            }
    
            TreeNode* left = preorder(root->left,p,q);
            TreeNode* right = preorder(root->right,p,q);
    
            if(left!= NULL && right!=NULL) return root;
            if(left == NULL) return right;
            if(right == NULL) return left;
    
            return NULL;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return preorder(root,p,q);
        }
    };