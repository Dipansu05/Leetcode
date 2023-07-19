class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        while(l<=h){
            long long m=(l+h)/2;
            long long v=m*m;
            if(v<=x) l=m+1;
            else h=m-1;
        }
        return h;
    }
    
};