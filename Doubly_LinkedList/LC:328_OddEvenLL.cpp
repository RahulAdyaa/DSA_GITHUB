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
    ListNode* oddEvenList(ListNode* head) {
        // Handle empty or single-node list
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // Pointers for odd and even nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next; // Store start of even list

        // Re-link nodes to separate odd and even indices
        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;
        return head;
    }
};
