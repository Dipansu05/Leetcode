class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int a=nums1.size(),b=nums2.size();
        int arr[a][b];
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    if(i==0||j==0)
                    {
                        arr[i][j]=1;
                    }
                    else
                    {
                    arr[i][j]=arr[i-1][j-1]+1;
                    }
                }
                else
                {
                    int c=0,d=0;
                    if(i>=1)
                    {
                        c=arr[i-1][j];
                    }
                    if(j>=1)
                    {
                        d=arr[i][j-1];
                    }
                    arr[i][j]=max(c,d);
                }
            }
        }
        return arr[a-1][b-1];
    }
};