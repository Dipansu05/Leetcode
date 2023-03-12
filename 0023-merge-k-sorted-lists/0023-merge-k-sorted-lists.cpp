
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return help(lists,0,lists.size()-1);
    }
    ListNode* help(vector<ListNode*> v,int s,int e){
        if(s==e) return v[s];
        int mid=(s+e)/2;
        ListNode* l= help(v,s,mid);
        ListNode* r=help(v,mid+1,e);
        return merge(l,r);
        }
    ListNode* merge(ListNode* l,ListNode* r){
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(l!=NULL && r!=NULL){
            if(l->val<r->val){
                temp->next=l;
                l=l->next;
            }
            else{
                temp->next=r;
                r=r->next;
                }
            temp=temp->next;
        }
        if(l!=NULL){
            temp->next=l;
            l=l->next;
            temp=temp->next;
        }
        if(r!=NULL){
            temp->next=r;
            r=r->next;
            temp=temp->next;
        }
        return ans->next;
    }
};