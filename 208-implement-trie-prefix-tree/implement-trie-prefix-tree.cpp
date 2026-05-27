class Trie {
public:
    struct trieNode{
        bool endOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<26;i++){
            newNode -> children[i] = nullptr;
        }
        newNode -> endOfWord=false;
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* pCrawl = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            int idx = ch-'a';
            if(pCrawl->children[idx]==nullptr){
                pCrawl->children[idx]=getNode();
            }
            pCrawl=pCrawl->children[idx];
        }
        pCrawl -> endOfWord = true;
    }
    
    bool search(string word) {
        trieNode* pCrawl = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            int idx = ch-'a';
            if(pCrawl->children[idx]==nullptr){
                //pCrawl->children[idx]=getNode();
                return false;
            }
            pCrawl=pCrawl->children[idx];
        }
        if(pCrawl!=nullptr && pCrawl -> endOfWord == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* pCrawl = root;
        int i{0};
        for(;i<prefix.size();i++){
            char ch = prefix[i];
            int idx = ch-'a';
            if(pCrawl->children[idx]==nullptr){
               // pCrawl->children[idx]=getNode();
               return false;
            }
            pCrawl=pCrawl->children[idx];
        }
        if(i==prefix.size()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */