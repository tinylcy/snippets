/*Sort a linked list using insertion sort.*/

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 一开始有点思维定式地新建一个头结点，然后把头结点指向给定的参数head，然后再排序，这样反而麻烦，
 * 因为每次取出结点的时候还得照顾到取出结点的前一个结点的位置，这就相当于在不开辟其余空间的情况
 * 下，仅仅依靠指针的变动让单链表有序。
 *
 * 正确的思路是新建一个结点，取名为sortedHead，然后顺序的将原链表的每个结点插入到sortedHead之后。
 * 其实，麻烦的思路和简单的思路唯一的区别就是“一开始新建的头结点指不指向head！！”
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sortedHead=new ListNode(-1);
        ListNode *index=NULL;
        ListNode *current=head;
        ListNode *tmp=NULL;
        while(current!=NULL) {
            index=sortedHead;
            while(index->next != NULL&&index->next->val<current->val) {
                index=index->next;
            }
            tmp=current->next;
            current->next=index->next;
            index->next=current;
            current=tmp;
        }
        return sortedHead->next;
    }
};

int main()
{
    ListNode *L1=new ListNode(2);
    ListNode *L2=new ListNode(1);
    ListNode *L3=new ListNode(5);
    ListNode *L4=new ListNode(4);
    ListNode *L5=new ListNode(3);
    L1->next=L2;
    L2->next=L3;
    L3->next=L4;
    L4->next=L5;
    Solution object;
    ListNode *sortedHead=object.insertionSortList(L1);
    while(sortedHead!=NULL){
        cout<<sortedHead->val<<" ";
        sortedHead=sortedHead->next;
    }
    cout<<endl;
    return 0;
}
