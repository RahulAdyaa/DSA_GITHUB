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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        int carry=0;
        
        while(t1!=nullptr || t2!=nullptr){
            int sum=carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;

            ListNode* newNode=new ListNode(sum%10,nullptr);
            carry=sum/10;
            temp->next=newNode;
            temp=temp->next;

            if(t1) t1=t1->next;
            if(t2) t2=t2->next;

            if(carry){
                ListNode* carryNode=new ListNode(carry);
                temp->next=carryNode;

            }
        }
        return dummyNode->next;
        
    }
};