/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5  */

/*思想：
 *遍历单链表，每次将以left为首结点的连续k个结点做倒置，需要注意的就是保存倒置后的
 *那条链表的首结点和尾结点，这样就可以把倒置后的那部分链表汇入原来的链表中去。
 *以下的代码运行的时间复杂度为O(n)，空间复杂度为常量。
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
    void reverseList(ListNode *beforeLeft,ListNode *left,int k){ //将单链表中从left开始的k个结点倒置
        ListNode * head=new ListNode(-1);
        ListNode *index=left;
        ListNode *tail=left; //头结点到最后成为尾结点，用tail记录下位置，连接链表的剩余部分
        ListNode *tmp=NULL;
        int count=1;
        while(count<=k){
            tmp=index->next;
            index->next=head->next;
            head->next=index;
            index=tmp;
            count++;
        }
        beforeLeft->next=head->next; //head->next为倒置后的链表的头结点
        tail->next=tmp; //tail为倒置后的单链表的尾结点，tmp实际上指向right的下一个结点，倒置完了将tail和tmp连接起来
        delete(head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmp=new ListNode(-1);
        tmp->next=head;
        head=tmp;
        ListNode *left=head->next;
        ListNode *right=head->next;
        ListNode *beforeLeft=head;
        while(left!=NULL&&right!=NULL){
            int count=1;
            while(count<k&&right!=NULL){
                right=right->next;
                count++;
            }
            if(right==NULL){
                break;
            }
            ListNode *tail=left; //tail的作用同上，用于保存倒置后的尾结点
            reverseList(beforeLeft,left,k);
            beforeLeft=tail;
            left=beforeLeft->next;
            right=beforeLeft->next;
        }
        tmp=head->next;
        delete(head);
        return tmp;
    }
};

int main()
{
    Solution object;
    ListNode *node1=new ListNode(1);
    ListNode *node2=new ListNode(2);
    ListNode *node3=new ListNode(3);
    ListNode *node4=new ListNode(4);
    ListNode *node5=new ListNode(5);
    ListNode *node6=new ListNode(6);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;
    ListNode *head=object.reverseKGroup(node1,5);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
