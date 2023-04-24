class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
   int n = stones.size();
        if(n==1)    return stones[0];
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int diff  = max(a,b) - min(a,b);
            if(diff>0)  pq.push(diff);
        }

        int weight = 0;
        if(!pq.empty())   weight = pq.top();
        return weight;
            
        }
    
};