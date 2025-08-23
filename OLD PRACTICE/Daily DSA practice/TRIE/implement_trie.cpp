//https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    vector<Trie*>children;
    bool isEnd;
public:
    Trie() {
       children = vector<Trie*>(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;

        for(char c:word)
        {
            int index = c - 'a';

            if(!node->children[index])
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;

        for(char c:word)
        {
            int index = c -'a';

            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return (node->isEnd)?true:false;
    }

    bool startsWith(string prefix) {
         Trie* node = this;

        for(char c:prefix)
        {
            int index = c -'a';

            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
