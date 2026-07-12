class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> rank;
        int r{1};
        for(int n: temp){
            if(!rank.count(n)) rank[n] = r++;
        }
        for(int &n: arr){
            n = rank[n];
        }
        return arr;
    }
};