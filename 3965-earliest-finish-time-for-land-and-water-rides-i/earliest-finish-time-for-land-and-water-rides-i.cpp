class Solution {
public:
    int do_cal(vector<int>& start1, vector<int>& fd, vector<int>& start2, vector<int>& sd){
        int first = INT_MAX;
        for(int i =0;i< start1.size(); i++){
            first = min(first, start1[i]+fd[i]);
        }

        int second = INT_MAX;
        for(int i =0;i< start2.size(); i++){
            second = min(second, max(start2[i],first)+sd[i]);
        }
        return second;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            do_cal(landStartTime, landDuration, waterStartTime, waterDuration),
            do_cal(waterStartTime,waterDuration,landStartTime, landDuration)
        );
        
    }
};