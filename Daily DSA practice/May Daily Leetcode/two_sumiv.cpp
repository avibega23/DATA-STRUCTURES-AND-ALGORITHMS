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
    unordered_set<int>st;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        if(st.find(k-(root->val))!=st.end())
        {
            return true;
        }
        else
        {
            st.insert(root->val);
        }
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};



// optimal solution

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
class BstIterator{
    public:
        stack<TreeNode*>st;
        bool reverse;
        BstIterator(TreeNode* root,bool reverse)
        {
            this->reverse = reverse;
            pushAll(root);
        }
        bool hasNext()
        {
            return !st.empty();
        }
        int next()
        {
            TreeNode* temp = st.top(); st.pop();
            if(reverse == true)
            {
                TreeNode* node = temp->left;
                for(; node!= NULL;)
                {
                    st.push(node);
                    node = node->right;
                }
            }
            else
            {
                TreeNode* node = temp->right;
                for(; node!= NULL;)
                {
                    st.push(node);
                    node = node->left;
                }
            }
            return temp->val;
        }
        void pushAll(TreeNode* node)
        {
            for( ; node!= NULL ;)
            {
                st.push(node);
                if(reverse)
                {
                    node = node->right;
                }
                else
                {
                    node = node->left;
                }
            }
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BstIterator a(root,false);
        BstIterator b(root,true);

        int i = a.next();
        int j = b.next();
        while(i<j)
        {
            if(i + j == k) return true;
            else if(i+j < k) i = a.next();
            else j = b.next();
        }
        return false;
    }
};