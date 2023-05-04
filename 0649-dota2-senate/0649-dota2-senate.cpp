class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int> rd, di;
        int n = senate.size();
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R')
                rd.push(i);
            else
                di.push(i);
        }
        while(!rd.empty() && !di.empty()){
            int rindex = rd.front();
            int dindex = di.front();
            rd.pop();
            di.pop();
            if(rindex < dindex)
                rd.push(rindex + n);
            else
                di.push(dindex + n);
        }
        return rd.empty() ? "Dire" : "Radiant"; 
    }
};