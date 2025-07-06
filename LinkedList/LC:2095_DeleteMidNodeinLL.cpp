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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has 0 or 1 node, return nullptr (nothing left after deletion)
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer 2 steps ahead initially
        fast = fast->next->next;
        
        // Important: safe because head->next is guaranteed to exist
        // So fast->next->next does not cause invalid dereference here
        // as if fast->next->next is null , it is legal for fast to jump there
        
        // Traverse until fast reaches the end
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Delete the middle node (node after slow)
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete(delnode);
        
        return head;
    }
};
