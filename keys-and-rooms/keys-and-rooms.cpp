class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> v(n,0);
        v[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int x=q.front();
                q.pop();
                for(int k: rooms[x]){
                    if(!v[k]){
                        v[k]=1;
                        q.push(k);
                    }
                }
            }
        }
        if(find(v.begin(),v.end(),0)!=v.end()){
            return false;
        }
        return true;
    }
};