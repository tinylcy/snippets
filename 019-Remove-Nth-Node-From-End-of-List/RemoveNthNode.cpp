/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preHead=new ListNode(0);
        preHead->next=head;
        ListNode* first=head;
        ListNode* second=head;
        ListNode* preSecond=preHead;
        int count=1;
        while(count<n){
            first=first->next;
            ++count;
        }
        while(first->next!=NULL){
            first=first->next;
            second=second->next;
            preSecond=preSecond->next;
        }
        preSecond->next=second->next;
        second->next=NULL;
        return preHead->next;
    }
};

int main()
{
    ListNode* L1=new ListNode(1);
    ListNode* L2=new ListNode(2);
    ListNode* L3=new ListNode(3);
    ListNode* L4=new ListNode(4);
    ListNode* L5=new ListNode(5);
    L1->next=L2;
    L2->next=L3;
    L3->next=L4;
    L4->next=L5;
    Solution object;
    ListNode *head=object.removeNthFromEnd(L1,5);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
