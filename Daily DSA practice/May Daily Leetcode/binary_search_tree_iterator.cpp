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
class BSTIterator {
public:
    vector<int>ans;
    int index = 0;
    void preorder(vector<int>&ans,TreeNode* root)
    {
        if(root == NULL) return;

        preorder(ans,root->left);
        ans.push_back(root->val);
        preorder(ans,root->right);
    }
    BSTIterator(TreeNode* root) {
        preorder(ans,root);
    }
    
    int next() {
        return ans[index++];
    }
    
    bool hasNext() {
        return (index < ans.size())?true:false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


//  optimal approach

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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = st.top(); st.pop();
        if(top->right)
        {
            TreeNode* temp = top->right;
            while(temp!=NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */