class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

  void unite(int x, int y){
    int px=find(x);
    int py=find(y);

    if(px==py) return;

    if(rank[px]>rank[py]){
        parent[py]=px;
    }else if(rank[px]<rank[py]){
        parent[px]=py;
    }else{
        parent[py]=px;
        rank[px]++;
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1) unite(i,j);
            }
        }

        int prov{0};
        for(int i=0;i<n;i++){
            if(parent[i]==i) prov++;
        }

        return prov;
    }
};