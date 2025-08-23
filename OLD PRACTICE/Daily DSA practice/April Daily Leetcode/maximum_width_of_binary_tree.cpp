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
        int widthOfBinaryTree(TreeNode* root) {
             if(root==NULL) return 0;
                queue<pair<TreeNode*,long long>> q;
                q.push({root,0});
                int maxi = 0;
                while(!q.empty())
                {
                    long long lh;
                    long long rh;
                    int size = q.size();
                    vector<int>level;
                    long long minIn = q.front().second;
                    for(int i = 0;i<size;i++)
                    {
                        auto it = q.front();
                        if(i == size-1) rh = it.second;
                        if(i == 0) lh = it.second;
                        TreeNode* node = it.first;
                        long long index = it.second-minIn;
                        q.pop();
                        if(node->left != NULL) q.push({node->left,2*index+1});
                        if(node->right != NULL) q.push({node->right,2*index+2});
                    }
                    maxi = max(int(rh-lh)+1,maxi);
                }
                return maxi;
        }
    };