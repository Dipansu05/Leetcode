#define ll long long int
int dp[105][105][2];
class Solution {
public:
    vector<int>prefix;
     int getPrefix(int start,int size){
        int end=prefix.size()-1;
        if(start+size<prefix.size())
            end=start+size-1;
        return start? prefix[end]-prefix[start-1]: prefix[end];
     }
    int fun(vector<int>&nums, int p, int m, int turn){
        if(p>=nums.size() || m>nums.size())
            return 0;
        ll ans=0,temp,alice=INT_MAX;
        if(dp[p][m][turn]!=-1)
            return dp[p][m][turn];
        for(int i=1;i<=2*m;i++){
            temp=fun(nums,p+i,max(i,m),!turn);
            ans=max(ans,temp+getPrefix(p,i));
            if(!turn)
                alice=min(temp,alice);
        }
        return dp[p][m][turn]= turn?ans:alice;
    }
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        prefix=piles;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
            prefix[i]=sum;
        }
        memset(dp,-1,sizeof(dp));
        return fun(piles,0,1,1);
    }
};