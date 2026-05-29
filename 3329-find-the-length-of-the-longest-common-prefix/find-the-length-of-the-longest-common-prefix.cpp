class Solution {
public:
    struct trieNode{
        trieNode* children[10];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<10;i++){
            newNode -> children[i] = nullptr;
        }
        return newNode;
    }
    void insert(int num, trieNode* root){
        trieNode* crawl = root;
        string numStr = to_string(num);

        for( char ch: numStr){
            int idx= ch-'0';
            if(!crawl->children[idx]){
                crawl->children[idx]=getNode();
            }
            crawl = crawl -> children[idx];
        }
    }
    int search(int num, trieNode* root){
        trieNode* crawl = root;
        int length{0};
        string numStr = to_string(num);

        for( char ch: numStr){
            int idx= ch-'0';
            if(crawl->children[idx]){
                //crawl->children[idx]=getNode();
                length++;
            }else{
                break;
            }
            crawl = crawl -> children[idx];
        }
        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        trieNode* root = getNode();

        int ans{0};
        for(int num: arr1){
            insert(num, root);
        }
        for(int num: arr2){
            ans = max(ans, search(num, root));
        }

        return ans;
    }
};