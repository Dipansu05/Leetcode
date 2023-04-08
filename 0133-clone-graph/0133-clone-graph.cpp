class Solution {
public:
    Node* n[101]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    void createnode(Node* origin){
        if(!n[origin->val]){
            n[origin->val]=new Node(origin->val);
        }
        for(auto  x:origin->neighbors){
            if(!n[x->val]) createnode(x);
            n[origin->val]->neighbors.push_back(n[x->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node) createnode(node);
        return n[1];
    }
};