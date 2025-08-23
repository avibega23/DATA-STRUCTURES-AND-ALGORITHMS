class TrieNode {
public:
    TrieNode* child[2]; // child[0] -> for bit 0, child[1] -> for bit 1
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

   
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->child[opposite]) {
                maxXOR |= (1 << i); 
                node = node->child[opposite];
            } else {
                node = node->child[bit];
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) trie.insert(num);

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, trie.findMaxXOR(num));
        }
        return maxResult;
    }
};