class Solution {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEnd;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i] = nullptr;
        }
        newNode -> isEnd = false;
        return newNode;
    }

    trieNode* root;

    void insert(string &word){
        trieNode* crawl = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(crawl->children[idx]==nullptr){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
        }
        crawl -> isEnd = true;
    }

    string search(string word){
        trieNode* crawl = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(crawl->children[idx]==nullptr){
                //crawl->children[idx]=getNode();
                return word;
            }
            crawl=crawl->children[idx];
            if(crawl->isEnd==true) return word.substr(0,i+1);
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        string word;
        root = getNode();
        stringstream ss(sentence);
        for(string& word: dictionary){
            insert(word);
        }

        while(getline(ss, word, ' ')){
            ans += search(word) + " ";
        }

        ans.pop_back();
        return ans;
        
    }
};