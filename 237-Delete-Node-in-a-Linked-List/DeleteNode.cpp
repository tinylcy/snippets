/*
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.

 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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

/*
 *这道题目和以往遇到的单链表题目不太一样：题目要求从单链表中删除给定的结点，
 *deleteNode函数的参数node即为指向要删除结点的指针，以往我们的做法是先得到
 *要删除结点的前一个结点，但是这道题目并没有给我们头结点。
 *
 *思路：用要删除结点的下一个结点的值替换要删除的结点的值，然后删除下一个结点
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete(temp);
    }
};

