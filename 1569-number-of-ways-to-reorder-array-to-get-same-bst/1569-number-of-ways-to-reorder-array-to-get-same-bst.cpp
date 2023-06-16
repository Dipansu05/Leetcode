class Solution {
public:
    long long solve(vector<int> &nums, vector<vector<long long>> &pascal)
    {
        int mod=1000000007;
        if(nums.size()<=2)  return 1;//refer example with nodes (1-->2)
        vector<int> leftsubtree,rightsubtree;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[0]) leftsubtree.push_back(nums[i]);//calculate for left subtree 
            else    rightsubtree.push_back(nums[i]);//to calculate for right sub tree
        }
        //total number of ways will be ways of placing left, right and wrt the current node
//for current node, we have to find ways of placing the left subtree nodes in the remaining places. then the ways of keeping the right sub tree will automatically become 1.
//(l+r)C*(l+r-l)Cr---> the second term becomes 1
        return (solve(leftsubtree,pascal)%mod*solve(rightsubtree,pascal)%mod*pascal[nums.size()-1][leftsubtree.size()]%mod)%mod;//nums.size()-1 cuz we will skip on eplace for the root node
    }
    int numOfWays(vector<int>& nums) {
        int mod=1000000007;
        //calculate nCr using pascal triangle logic
        int n=nums.size();
        vector<vector<long long>> pascal(n);
        //n-1Cr-1
        for(int i=0;i<n;i++)
        {
            pascal[i].resize(i+1);
            pascal[i][0]=1;
            pascal[i][i]=1;
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;//refer pascal triangle logic of finding nCr in O(N) time complexity
            }
        }
        return solve(nums,pascal)-1;
        
    }
};