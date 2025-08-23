/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:
        void recurse(TreeNode* root,string &ans)
        {
            if(root == NULL)
            {
                ans+="n,";
                return;
            } 
            else 
            {
                ans += (to_string(root->val));
                ans += ",";
            }
            recurse(root->left,ans);
            recurse(root->right,ans);
        }
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string ans = "";
            recurse(root,ans);
            cout << ans;
            return ans;
        }
    
        TreeNode* recurse(string data,int &i)
        {
            if(i >= data.size())
            {
                i++;
                return NULL;
            }
            string val;
            while(data[i]!=',')
            {
                val+= data[i];
                i++;
            }
            if(val=="n") return NULL;
            
            TreeNode* root = new TreeNode(stoi(val));
            i++;
            root->left = recurse(data,i);
            i++;
            root->right = recurse(data,i);
    
            return root;
        }
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            int index = 0;
            return recurse(data,index);
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));