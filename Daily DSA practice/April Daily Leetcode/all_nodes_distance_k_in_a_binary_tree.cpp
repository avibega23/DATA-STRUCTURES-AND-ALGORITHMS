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
        void mark_parents(unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode* root)
        {
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    mpp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    mpp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*,TreeNode*>mpp;
            mark_parents(mpp,root);
    
            unordered_map<TreeNode*,bool>visited;
            queue<TreeNode*>q;
            q.push(target);
            visited[target] = true;
            int dist = 0;
            while(!q.empty())
            {
                int size = q.size();
                if(dist++ == k) break;
                for(int i = 0;i<size;i++)
                {
                    TreeNode* node = q.front(); q.pop();
                    if(node->left && !visited[node->left])
                    {
                        q.push(node->left);
                        visited[node->left] = true;
                    }
                    if(node->right && !visited[node->right])
                    {
                        q.push(node->right);
                        visited[node->right] = true;
                    }
                    if(mpp[node] && !visited[mpp[node]])
                    {
                        q.push(mpp[node]);
                        visited[mpp[node]] = true;
                    }
                }
            }
            vector<int>ans;
            while(!q.empty())
            {
                TreeNode* node = q.front(); q.pop();
                ans.push_back(node->val);
            }
            return ans;
        }
    };