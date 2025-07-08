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
    // Helper function to find the middle node of the list
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move fast by 2 steps and slow by 1 step to stop at Middle 1
        // for even length LL
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    
    // Helper function to merge two sorted linked lists
    ListNode* mergelist(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        // Merge nodes in sorted order
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        // Attach any remaining nodes
        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummyNode->next;
    }

    // Main function to sort the linked list using Merge Sort
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 node is already sorted
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // Find the middle node to split the list
        ListNode* middle = findMiddle(head);

        // Split the list into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return mergelist(left, right);
    }
};
