// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int i=1,m,j=n;
        while(i<=j){
            m=(i+j)/2;
            if(isBadVersion(m)==true and isBadVersion(m-1)==false) return m;
            if(isBadVersion(m)==true) j=m-1;
            else i=m+1;
        }
        return  m;
    }
};