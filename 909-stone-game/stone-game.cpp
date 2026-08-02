class Solution {
public:
    int t[501][501];
    int solve(int i, int j, vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(t[i][j]!=-1) return t[i][j];
        int take1 = nums[i]-solve(i+1, j, nums);
        int take2 = nums[j]-solve(i, j-1, nums);
        return t[i][j]=max(take1, take2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t, -1, sizeof(t));
        return solve(0, n-1, piles) > 0;
    }
};