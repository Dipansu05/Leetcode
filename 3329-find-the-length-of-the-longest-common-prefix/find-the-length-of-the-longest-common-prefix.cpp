class Solution {
public:
    struct trieNode{
        trieNode* children[10];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        for(int i=0;i<10;i++){
            newNode->children[i] = nullptr;
        }

        return newNode;

    }

    void insert(int num, trieNode* root){
        trieNode* crawl = root;
        string numStr = to_string(num);

        for(char ch: numStr){
            int idx = ch - '0';
            if(!crawl -> children[idx]){
                crawl -> children[idx] = getNode();
            }
            crawl = crawl -> children[idx];
        }
    }

    int search (int num, trieNode* root){
        trieNode* crawl = root;
        string numStr = to_string(num);
        int length{0};

        for(char ch: numStr){
            int idx = ch-'0';
            if(crawl -> children[idx]){
                length++;
                crawl = crawl -> children[idx];
            }else{
                break;
            }
        }
        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        trieNode* root = getNode();

        for(int num: arr1){
            insert(num, root);
        }

        int result{0};
        for(int num: arr2){
            result = max(result, search(num, root));
        }

        return result;
        
    }
};