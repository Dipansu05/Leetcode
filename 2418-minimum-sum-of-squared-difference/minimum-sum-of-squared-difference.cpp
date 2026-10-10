class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> cd(1e5+1, 0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            cd[d]++;
        }
        int k=k1+k2;
        for(int dif=1e5;dif>0 && k>0; dif--){
            int count=min(cd[dif],k);
            cd[dif] -= count;
            cd[dif-1] += count;
            k -= count;
        }
        long long res=0;
        for(long long d=1;d<=1e5;d++){
            res+=(cd[d]* d*d);
        }
        return res;
    }
};