/* Given a list, rotate the list to the right by k places, where k is non-negative.

 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

 /**
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

    int getLength(ListNode *head){
        int length=0;
        while(head!=NULL){
            ++length;
            head=head->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int ListLength=getLength(head);
        if(k%ListLength==0){
            return head;
        }else{
            k=k%ListLength;
        }
        ListNode *tmp=NULL;
        ListNode *tail=NULL;
        tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tail=tmp;
        tail->next=head;
        int count=1;
        while(count<ListLength-k){
            head=head->next;
            ++count;
        }
        tmp=head;
        head=head->next;
        tmp->next=NULL;
        return head;
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
    ListNode *head=object.rotateRight(L1,6);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
