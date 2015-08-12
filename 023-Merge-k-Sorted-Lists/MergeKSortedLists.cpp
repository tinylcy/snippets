/*
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 */

/*
 * 用了归并的思想：要对K条List排序，先排0～K/2,再排(K/2+1)~(K-1)，最后将这左右两部分再进行一次归并，
 * 这个过程递归到只剩下2条序列(或1条)，执行一次归并。
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoList(ListNode *L1,ListNode *L2){
        if(L1==NULL&&L2==NULL){
            return NULL;
        }
        ListNode *head=new ListNode(-1);
        ListNode *index1=L1;
        ListNode *index2=L2;
        ListNode *current=head;
        while(index1!=NULL&&index2!=NULL){
            if(index1->val<=index2->val){
                current->next=index1;
                current=index1;
                index1=index1->next;
            }else{
                current->next=index2;
                current=index2;
                index2=index2->next;
            }
        }
        if(index1!=NULL){
            current->next=index1;
        }
        if(index2!=NULL){
            current->next=index2;
        }
        ListNode *ret=head->next;
        delete(head);
        return ret;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        if(lists.size()==2){
            return mergeTwoList(lists[0],lists[1]);
        }
        int mid=lists.size()/2;
        vector<ListNode*> leftListNode;
        vector<ListNode*> rightListNode;
        for(int i=0;i<mid;i++){
            leftListNode.push_back(lists[i]);
        }
        for(unsigned int i=mid;i<lists.size();i++){
            rightListNode.push_back(lists[i]);
        }
        ListNode *left=mergeKLists(leftListNode);
        ListNode *right=mergeKLists(rightListNode);
        return mergeTwoList(left,right);
    }
};

int main()
{
    ListNode *L1_1=new ListNode(1);
    ListNode *L1_2=new ListNode(4);
    ListNode *L1_3=new ListNode(6);
    ListNode *L2_1=new ListNode(2);
    ListNode *L2_2=new ListNode(3);
    ListNode *L2_3=new ListNode(7);
    ListNode *L2_4=new ListNode(8);
    ListNode *L3_1=new ListNode(4);
    ListNode *L3_2=new ListNode(6);
    ListNode *L3_3=new ListNode(7);
    ListNode *L3_4=new ListNode(9);
    L1_1->next=L1_2;
    L1_2->next=L1_3;
    L2_1->next=L2_2;
    L2_2->next=L2_3;
    L2_3->next=L2_4;
    L3_1->next=L3_2;
    L3_2->next=L3_3;
    L3_3->next=L3_4;
    vector<ListNode*> lists;
    lists.push_back(L1_1);
    lists.push_back(L2_1);
    lists.push_back(L3_1);
    Solution object;
    ListNode *head=object.mergeKLists(lists);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
