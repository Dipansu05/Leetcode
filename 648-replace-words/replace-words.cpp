class Solution {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEnd;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<26;i++){
            newNode -> children[i] = NULL;
        }
        newNode -> isEnd = false;
        return newNode;
    }

    trieNode* root;

    void insert(string &word){
        trieNode* crawler = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler ->children[idx];
        }
        crawler -> isEnd = true;
    }

    string search(string &word){
        trieNode* crawler = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(crawler->children[idx]==NULL){
                //root->children[idx] = getNode();
                return word;
            }
            crawler = crawler ->children[idx];
            if(crawler->isEnd) return word.substr(0, i+1);
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string word;
        string result;
        root = getNode();
        for(string word: dictionary){
            insert(word);
        }

        while(getline(ss, word, ' ')){
            result += search(word) + " ";
        }
        result.pop_back();
        return result;
        
    }
};