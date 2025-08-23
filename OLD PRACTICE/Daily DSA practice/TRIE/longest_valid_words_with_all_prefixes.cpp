//https://www.geeksforgeeks.org/problems/longest-valid-word-with-all-prefixes/1

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

class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        // code here
        
        Trie* node = new Trie();
        string word = "";
        int maxi = 0;
        for(auto it:words)
        {
            node->insert(it);
        }
        for(auto it:words)
        {
            bool flag = true;
            string ans = "";
            for(char c:it)
            {
                ans += c;
                flag = node->search(ans);
                if(flag == false) break;
            }
            if(flag == true && (it.size()>maxi || (it.size()==maxi) && it<word))
            {
                word = it;
                maxi = it.size();
            }
        }
        return word;
    }
};

