class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for(auto x: grid){
            for(int v : x)
                arr.push_back(v);
        }

        int base=arr[0];
        for(int v : arr){
            if(abs(v-base) % x != 0) return -1;
        }

        sort(begin(arr),end(arr));

        int median=arr[arr.size()/2];
        int ops{0};

        for(int v : arr){
           ops += abs(v-median)/x;       
        }

        return ops;
    }
};