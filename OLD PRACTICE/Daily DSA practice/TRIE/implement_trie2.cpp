//https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
class Trie{
    vector<Trie*>children;
    int cntEndWith;
    int endCnt;
    public:

    Trie(){
        // Write your code here.
        children = vector<Trie*>(26,nullptr);
        cntEndWith = 0;
        endCnt = 0;
    }

    void insert(string &word){
        // Write your code here.
         Trie* node = this;

        for(char c:word)
        {
            int index = c - 'a';

            if(!node->children[index])
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
            node->cntEndWith = node->cntEndWith + 1;
        }
        node->endCnt = node->endCnt+1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Trie* node = this;

        for(char c:word)
        {
            int index = c -'a';

            if(!node->children[index]) return 0;
            node = node->children[index];
        }
        return node->endCnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Trie* node = this;

        for(char c:word)
        {
            int index = c -'a';

            if(!node->children[index]) return 0;
            node = node->children[index];
        }
        return node->cntEndWith;
    }

    void erase(string &word){
        // Write your code here.
        Trie* node = this;

        for (char c : word) {
            int index = c - 'a';

            if (!node->children[index]) return; 
            node = node->children[index];
            node->cntEndWith--;   
        }
        node->endCnt--; 
    }
};
