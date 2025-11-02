class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }

        ListNode* cur=head;
        ListNode* prev=NULL;
        while(true){
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            if(tmp==NULL){
                return cur;
            }
            cur=tmp;
        }
    }
};