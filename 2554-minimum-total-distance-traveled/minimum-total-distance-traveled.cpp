class Solution {
public:
    long long solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<long long>> &t){
        if(ri>=robot.size()) return 0;
        if(fi>=positions.size()) return 1e15;
        if(t[ri][fi]!=-1) return t[ri][fi];

        long long take= abs(robot[ri]-positions[fi]) + solve(ri+1, fi+1, robot, positions,t);
        long long skip= solve(ri, fi+1, robot, positions,t);

        return t[ri][fi]=min(take, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        vector<int> positions;
        for(int i=0;i<factory.size();i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j=0;j<limit;j++){
                positions.push_back(pos);
            }
        }

        int n=positions.size();
        int m=robot.size();
        vector<vector<long long>> t(m+1, vector<long long>(n+1, -1));

        return solve(0, 0, robot, positions, t);
    }
};