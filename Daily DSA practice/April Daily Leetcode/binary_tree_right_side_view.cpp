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
        void preOrder(map<int,int>&mpp,TreeNode* root,int row)
        {
            if(root == NULL) return;
    
            if(mpp.find(row)==mpp.end())
            {
                mpp[row] = root->val;
            }
            preOrder(mpp,root->right,row+1);
            preOrder(mpp,root->left,row+1);
        }
        vector<int> rightSideView(TreeNode* root) {
            map<int,int>mpp;
            preOrder(mpp,root,0);
            vector<int>ans;
            for(auto it:mpp)
            {
                ans.push_back(it.second);
            }
            return ans;
        }
    };