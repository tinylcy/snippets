 /*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed.
 */

 /*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *index=new ListNode(-1);
        ListNode *current=head;
        ListNode *afterCurrent=head->next;
        index->next=head;
        head=index;
        while(current!=NULL&&afterCurrent!=NULL){
            current->next=afterCurrent->next;
            afterCurrent->next=current;
            index->next=afterCurrent;
            index=current;
            current=current->next;
            if(current!=NULL){
                afterCurrent=current->next; //avoid the situation of "NULL->next=?"
            }
        }
        return head->next;
    }
};

int main()
{
    ListNode *L1=new ListNode(1);
    ListNode *L2=new ListNode(2);
    ListNode *L3=new ListNode(3);
    ListNode *L4=new ListNode(4);
    ListNode *L5=new ListNode(5);
    L1->next=L2;
    L2->next=L3;
    L3->next=L4;
    L4->next=L5;
    Solution object;
    ListNode *head=object.swapPairs(L1);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
