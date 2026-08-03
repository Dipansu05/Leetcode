class Solution {
public:
    int n;
    
    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        //t.resize(n+1, -1);
        vector<int> t(n+1);
        for(int i=n-1;i>=0;i--){
            t[i]=stones[i]-t[i+1];
            if(i+2<=n)
                t[i]=max(t[i], stones[i]+stones[i+1]-t[i+2]);
            if(i+3<=n)
                t[i]=max(t[i], stones[i]+stones[i+1]+stones[i+2]-t[i+3]);
        }
        int res = t[0];
        if(res > 0) return "Alice";
        if(res < 0) return "Bob";
        return "Tie";
    }
};