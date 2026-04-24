class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r_count{0};
        int l_count{0};
        int d_count{0};
        for(auto itr : moves){
            if(itr=='R') r_count ++;
            else if(itr=='L') l_count++;
            else d_count++;
        }
        int ans;
        if (r_count>l_count) return (r_count+d_count)-l_count;
        if (l_count>r_count) return (l_count+d_count)-r_count;
        return (r_count+d_count)-l_count;

    }
};