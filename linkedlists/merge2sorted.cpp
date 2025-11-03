class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL and list2==NULL) return list1;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* pri;
        ListNode* sec;
        if(list1->val < list2->val){
            pri=list1;
            sec=list2;
        }else{
            pri=list2;
            sec=list1;
        }
        ListNode* fin_head=pri;
        while(pri!=NULL && sec!=NULL){
            ListNode* tmp;

            if(sec==NULL){
                pri=pri->next;
                continue;
            }

            if(pri->next==NULL){
                pri->next=sec;
                sec=tmp;
                break;
            }

            if(sec->val < pri->next->val){
                tmp=sec->next;

                sec->next=pri->next;
                pri->next=sec;
                
                pri=pri->next;
                sec=tmp;
            }else{
                pri=pri->next;
            }
        }
        return fin_head;
    }
};