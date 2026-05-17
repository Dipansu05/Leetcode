class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(start);
        vis[start]=true;

        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0) return true;
            int forward=i+arr[i];
            int back=i-arr[i];

            if(forward<n && !vis[forward]){
                vis[forward]=true;
                q.push(forward);
            }

            if(back>=0 && !vis[back]){
                vis[back]=true;
                q.push(back);
            }
        }
        return false;
    }
};