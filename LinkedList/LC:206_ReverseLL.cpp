/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // //Using Recursion
    // ListNode* reverseList(ListNode* head) {
    //     if(head==nullptr || head->next==nullptr){
    //         return head;
    //     }

    //     ListNode* newHead=reverseList(head->next);
    //     ListNode* front=head->next;
    //     front->next=head;
    //     head->next=nullptr;
    //     return newHead;
    // }
    
    //Using Iterative Method
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
        

    }
};