class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        int l =0, r = total-1;
        while(l<=r){
            int mid = l + ((r-l)/2);
            int rx=mid/n, cx=mid%n;
            if (matrix[rx][cx]==target) return true;
            else if (matrix[rx][cx]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};