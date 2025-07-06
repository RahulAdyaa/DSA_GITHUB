//  Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is nullptr (means n==length of LL),
        // we need to remove the head node
        if(fast == nullptr) {
            ListNode* dummyhead = head;
            // Return the next node as new head
            return head->next;
            delete(dummyhead); 
        }

        // Move both pointers until fast reaches the end
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete(delnode);

        return head;
    }
};
