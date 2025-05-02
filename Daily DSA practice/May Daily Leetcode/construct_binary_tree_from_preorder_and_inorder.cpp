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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int,int>inMap;
            for(int i = 0;i<inorder.size();i++)
            {
                inMap[inorder[i]] = i;
            }
    
            return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        }
        TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&inMap)
        {
            if(inStart>inEnd || preStart > preEnd) return NULL;
    
            TreeNode* node = new TreeNode(preorder[preStart]);
            int inIndex = inMap[preorder[preStart]];
            int numsLeft = inIndex -  inStart;
    
            node->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inIndex-1,inMap);
            node->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inIndex+1,inEnd,inMap);
            return node;
        }
    };