class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, temp(n);
        for (auto& e: edges)
            temp[e[1]] = 1;
        for (int i = 0; i < n; ++i)
            if (temp[i] == 0)
                ans.push_back(i);
                
        return ans;
    }
};