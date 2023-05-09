class Trie {
public:
    
    struct TrieNode{
        bool isEnd;
        TrieNode *child[26];
    };
    
    TrieNode* getNode(){
        TrieNode*  newNode=new TrieNode();
        newNode->isEnd=false;
        
        for(int i=0;i<26;i++){
            newNode->child[i]=NULL;
        }
        return newNode;
    }
    
    TrieNode* root;
    Trie() {
        
        root= getNode();
        
    }
    
    void insert(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            
            if(crawler->child[idx]==NULL){
            crawler->child[idx]=getNode();
            }
            crawler=crawler->child[idx];
        }
        crawler->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            
            if(crawler->child[idx]==NULL){
            return false;;
            }
            crawler=crawler->child[idx];
        }
        if(crawler!=NULL && crawler->isEnd==true) return true;
        return false;
        
    }
    
    bool startsWith(string word) {
        TrieNode* crawler=root;
        int i=0;
        for(i;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            
            if(crawler->child[idx]==NULL){
            return false;
            }
            crawler=crawler->child[idx];
        }
        if(i==word.length()) return true;
        return  false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */