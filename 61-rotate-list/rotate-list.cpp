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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=nullptr){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        k=k%nums.size();
        if(k==0) return head;
        k=nums.size()-k;
        int count{0};

        temp=head;
        while(count<nums.size()){
            temp->val=nums[k];
            k++;
            k=k%nums.size();
            count++;
            temp=temp->next;
        }
        return head;
    }
};