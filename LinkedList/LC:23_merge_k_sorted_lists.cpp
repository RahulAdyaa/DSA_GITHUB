#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Comparator for the min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap: smallest value on top
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the current heads of all k lists
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push the head of each list into the min-heap
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node to build the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Process the heap
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            // Append the smallest node to the result
            tail->next = curr;
            tail = tail->next;

            // If there is a next node in the list, push it into heap
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy->next; // Skip dummy node
    }
};

// Function to create a linked list from vector
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create sample input lists
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};

    // Convert arrays to linked lists
    ListNode* list1 = createList(l1);
    ListNode* list2 = createList(l2);
    ListNode* list3 = createList(l3);

    // Add them to the vector
    vector<ListNode*> lists = {list1, list2, list3};

    // Call the merge function
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // Print result
    cout << "Merged List: ";
    printList(result);

}
