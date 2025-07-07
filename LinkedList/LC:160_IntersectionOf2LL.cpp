/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 1st approach: Using a hash map to detect the intersection node
    // TC:O(N1+N2)
    // SC:O(N1) or O(N2)
    // ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    //     // Create a hash map to store nodes of the first list
    //     unordered_map<ListNode*, int> mpp;

    //     // Traverse the first linked list and store each node in the map
    //     ListNode* temp = head1;
    //     while(temp != nullptr){
    //         mpp[temp] = 1;
    //         temp = temp->next;
    //     }

    //     // Traverse the second linked list
    //     // Check if any node is already present in the map
    //     // If yes, it means that node is the intersection point
    //     temp = head2;
    //     while(temp != nullptr){
    //         if(mpp[temp] == 1){
    //             return temp; // Intersection node found
    //         }
    //         temp = temp->next;
    //     }

    //     // No intersection node found
    //     return nullptr;
    // }


    
    // 2nd approach
    // TC:O(N1+2N2)
    // SC:O(1)

    // Moves the longer list's pointer ahead by 'd' steps to align both pointers
    // ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d) {
    //     while(d--) {
    //         t2 = t2->next;
    //     }

    //     // Move both pointers until they meet (intersection) or reach end
    //     while(t1 != t2) {
    //         t1 = t1->next;
    //         t2 = t2->next;
    //     }
    //     return t1;
    // }

    // ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
    //     // Count nodes in first list
    //     ListNode* temp = head1;
    //     int N1 = 0;
    //     while(temp != nullptr) {
    //         N1++;
    //         temp = temp->next;
    //     }

    //     // Count nodes in second list
    //     temp = head2;
    //     int N2 = 0;
    //     while(temp != nullptr) {
    //         N2++;
    //         temp = temp->next;
    //     }

    //     // Always call collisionPoint with (shorter, longer, diff)
    //     if(N1 < N2) {
    //         return collisionPoint(head1, head2, N2 - N1);
    //     } else {
    //         return collisionPoint(head2, head1, N1 - N2);
    //     }
    // }

    // MAIN APPROACH

    // TC:O(N1+N2)
    // SC:O(1)

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;

        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==nullptr) t1=headB;
            if(t2==nullptr) t2=headA;
        }
        return t1; // if both heads are at single node form starting
    }

};