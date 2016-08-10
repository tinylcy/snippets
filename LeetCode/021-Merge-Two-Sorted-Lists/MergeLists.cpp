/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *Head1=new ListNode(0);
        ListNode *Head=NULL;
        Head1->next=l1;
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *index=Head1;
        while(p1!=NULL&&p2!=NULL){
            if(p1->val<=p2->val){
                index->next=p1;
                index=p1;
                p1=p1->next;
            }else{
                index->next=p2;
                index=p2;
                p2=p2->next;
            }
        }
        if(p1!=NULL){
            index->next=p1;
        }else{
            index->next=p2;
        }
        Head=Head1->next;
        delete Head1;
        return Head;
    }
};
