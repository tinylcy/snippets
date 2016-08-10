/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *tmp=new ListNode(-1);
        tmp->next=head;
        head=tmp;
        ListNode *index=NULL;
        ListNode *left=NULL,*preLeft=NULL;
        ListNode *right=NULL,*afterRight=NULL;
        int count=0;
        index=head;
        while(index!=NULL){
            if(count==m-1){
                preLeft=index;
            }
            if(count==m){
                left=index;
            }
            if(count==n){
                right=index;
                break;
            }
            count++;
            index=index->next;
        }
        afterRight=right->next;
        preLeft->next=afterRight;
        right->next=NULL;
        while(left!=NULL){
            tmp=left->next;
            left->next=preLeft->next;
            preLeft->next=left;
            left=tmp;
        }
        tmp=head->next;
        delete(head);
        return tmp;
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
    ListNode *head=object.reverseBetween(L1,2,4);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
