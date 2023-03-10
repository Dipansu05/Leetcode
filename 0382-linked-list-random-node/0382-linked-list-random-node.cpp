
class Solution {
public:
    int s=0;
    int x;
    vector<int> v;
    Solution(ListNode* head) {
        while(head){
            v.push_back(head->val);
            head=head->next;
            s++;
        }
    }
    int getRandom() {
        x=(rand()%s);
        return v[x];
        }
};
