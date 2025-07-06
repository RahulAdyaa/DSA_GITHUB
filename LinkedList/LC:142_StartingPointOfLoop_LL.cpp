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
    ListNode *detectCycle(ListNode *head) {

        //  BRUTE FORCE METHOD
        // unordered_map<ListNode* , int> mpp;
        // ListNode* temp=head;
        // while(temp!=nullptr){
            
        //     if(mpp[temp]==1){
        //         return temp;
        //     }
        //     mpp[temp]=1;
        //     temp=temp->next;
        // }
        // return nullptr;
        

        //  TORTOISE AND HARE
        //STEP-1 DETECTING A LOOP

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;

            fast=fast->next->next;

            //Step 2  If they collide at some point , then find the starting point
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
        
        
        
        
        
        
        
        
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast && fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         return slow->next;
        //     }
        // }
        // return nullptr;
    }
};