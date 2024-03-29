/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int i=1;
    int s=0;
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
            s++;
        }
    }
    
    int getRandom() {
        int x=(rand()%s);
        //i=(i+2)%s;
        return v[x];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
