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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int,int>inMap;
            for(int i = 0;i<inorder.size();i++)
            {
                inMap[inorder[i]] = i;
            }
    
            return buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
        }
        TreeNode* buildTree(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&inMap)
        {
            if(postStart > postEnd || inStart > inEnd) return NULL;
    
            TreeNode* node = new TreeNode(postorder[postEnd]);
    
            int inIndex = inMap[node->val];
            int postLeft = inEnd - inIndex;
    
            node->left = buildTree(postorder,postStart,postEnd-postLeft-1,inorder,inStart,inIndex-1,inMap);
            node->right = buildTree(postorder,postEnd-postLeft,postEnd-1,inorder,inIndex+1,inEnd,inMap);
    
            return node;
        }
    };