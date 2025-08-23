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
        void recurse(int cnt,TreeNode* root,int &mainCnt)
        {
            if(root == NULL) return;
            cnt++;
            mainCnt = max(cnt,mainCnt);
            recurse(cnt,root->left,mainCnt);
            recurse(cnt,root->right,mainCnt);
        }
        int maxDepth(TreeNode* root) {
            int cnt = 0;
            recurse(0,root,cnt);
            return cnt;
        }
    };