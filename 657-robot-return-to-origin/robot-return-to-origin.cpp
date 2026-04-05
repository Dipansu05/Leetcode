class Solution {
public:
    bool judgeCircle(string moves) {
        int count_v{0},count_h{0};
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') count_v++;
            else if(moves[i]=='D') count_v--;
            else if(moves[i]=='R') count_h++;
            else count_h--;
        }

        return (count_v==0 && count_h==0) ? true : false;
        
    }
};