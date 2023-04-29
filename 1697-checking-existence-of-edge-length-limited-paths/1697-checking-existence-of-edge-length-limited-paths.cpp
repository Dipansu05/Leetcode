class Solution {
public:
    vector<int> parent;

    int findParent(int a){
        if(parent[a]==a){
            return a;
        }
        return findParent(parent[a]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {        
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        map<int, vector<int>> val2index;
        map<int, vector<int>> limit2index;

        for(int i=0; i<edgeList.size(); i++){
            val2index[edgeList[i][2]].push_back(i);
        }
        for(int i=0; i<queries.size(); i++){
            limit2index[queries[i][2]].push_back(i);
        }


        auto iter = val2index.begin();

        vector<bool> res(queries.size());
        for(auto l: limit2index){
            int limit = l.first;
            while(iter!=val2index.end() && iter->first<limit){
                for(auto node:iter->second){
                    int a = edgeList[node][0];
                    int b = edgeList[node][1];
                    int x = findParent(a);
                    int y = findParent(b);

                    if(x<y){
                        parent[x] = y;
                    }else{
                        parent[y] = x;
                    }
                }
                iter = next(iter);
            }
            for(auto index:l.second){
                int a = queries[index][0];
                int b = queries[index][1];
                int x = findParent(a);
                int y = findParent(b);

                res[index] = (x==y);
            }
        }
        return res;
    }

};