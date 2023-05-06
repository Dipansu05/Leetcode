class Solution {
private:
    long long power(long long base,long long n, long long mod){
        long long ans=1;
        while(n!=0){
            if(n%2==1){
                ans=(ans*base)%mod;
                n--;
            }else{
                base=(base*base)%mod;
                n=n/2;
            }
        }
        return ans;
    }
public:
    int numSubseq(vector<int>& nums, int target) {

        int start=0;
        int end=nums.size()-1;

        sort(nums.begin(),nums.end());

        int mod=1000000007;

        int count=0;

        //number of subsequences is 2^n here, n is the range b/w the first and last element index

        while(start<=end){

            if(nums[start]+nums[end]<=target){
                long long totalsubseq=power(2,end-start,mod);
                count=(count+totalsubseq)%mod;
                start++;
            }
            else{
                end--;
            }

        }

        return count;
    }
};