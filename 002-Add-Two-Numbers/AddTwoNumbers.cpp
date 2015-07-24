/**
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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

    ListNode *index=NULL;
    ListNode *front_index=NULL;

    int getListLength(ListNode *head){
        int length=0;
        while(head!=NULL){
            ++length;
            head=head->next;
        }
        return length;
    }

    /*
     * 一开始定义的函数形式为addOneList(ListNode *L,ListNode *index,ListNode *tail,int &c),
     * index和tail作为地址传递进来，当修改了相应结点内的值后，再返回到main函数，看是否还需要给进位新建一
     * 个结点，这时候问题就出现了：虽然传递进来的是结点地址，但是仅对于地址来说，地址属于值传递，所以index和
     * tail还是指在addOneList函数调用前的那些结点上。解决办法：把index和tail定义为全局变量
     */
    void addOneList(ListNode *L,int &c){
        while(L!=NULL&&index!=NULL){
            int value=L->val;
            index->val=(value+c)%10;
            c=(value+c)/10;
            L=L->next;
            index=index->next;
            front_index=front_index->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(l1==NULL&&l2==NULL) return NULL;
        if(l1==NULL&&l2!=NULL) return l2;
        if(l2==NULL&&l1!=NULL) return l1;

        int length_1=getListLength(l1);
        int length_2=getListLength(l2);

        ListNode *head=new ListNode(0);
        index=NULL;
        front_index=head;
        head->next=l1;
        if(length_1<length_2){
            head->next=l2;
        }
        index=head->next;
        int val_1=0,val_2=0,c=0; //c:进位
        while(l1!=NULL&&l2!=NULL){
            val_1=l1->val;
            val_2=l2->val;
            index->val=(val_1+val_2+c)%10;
            c=(val_1+val_2+c)/10;
            l1=l1->next;
            l2=l2->next;
            index=index->next;
            front_index=front_index->next;
        }
        if(l1!=NULL){
            addOneList(l1,c);
        }
        if(l2!=NULL){
            addOneList(l2,c);
        }
        if(c!=0){
            index=new ListNode(c);
            front_index->next=index;
        }
        return head->next;

    }
};

int main()
{
    ListNode *L1_1=new ListNode(1);
    ListNode *L1_2=new ListNode(2);
    ListNode *L1_3=new ListNode(4);
    ListNode *L1_4=new ListNode(9);
    L1_1->next=L1_2;
    L1_2->next=L1_3;
    L1_3->next=L1_4;
    ListNode *L2_1=new ListNode(5);
    ListNode *L2_2=new ListNode(6);
    ListNode *L2_3=new ListNode(7);
    L2_1->next=L2_2;
    L2_2->next=L2_3;
    Solution object;
    ListNode *head=object.addTwoNumbers(L1_1,L2_1);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
