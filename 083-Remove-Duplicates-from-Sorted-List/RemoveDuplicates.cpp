/* Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp=new ListNode(-1);
        tmp->next=head;
        head=tmp;
        ListNode *current=head;
        ListNode *index=head->next;
        current->next=NULL;
        bool isFirst=true;
        int key=-1;
        while(index!=NULL){
            if(isFirst){
                key=index->val;
                current->next=index;
                current=index;
                isFirst=false;
                index=index->next;
                current->next=NULL;
            }else{
                if(index->val==key){
                    index=index->next;
                }else{
                    current->next=index;
                    current=index;
                    key=index->val;
                    index=index->next;
                    current->next=NULL;
                }
            }
        }
        tmp=head->next;
        delete(head);
        return tmp;
    }
};

int main()
{
    ListNode *node1=new ListNode(1);
    ListNode *node2=new ListNode(1);
    ListNode *node3=new ListNode(2);
    ListNode *node4=new ListNode(3);
    ListNode *node5=new ListNode(3);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    Solution object;
    ListNode *head=object.deleteDuplicates(node1);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
