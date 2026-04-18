class Solution {
public:
    int revNum(int x){
        int rev{0};
        while(x){
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev=revNum(n);

        return abs(n-rev);
    }
};