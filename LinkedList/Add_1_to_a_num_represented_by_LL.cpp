#include<iostream>
#include<vector>
using namespace std;

// Definition of a singly linked list node
class Node {
public:
    int data;
    Node* next;

   
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

  
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Converts a vector of integers into a singly linked list
Node* ConvertArrToLL(vector<int> arr) {
    Node* head = new Node(arr[0]); // First element becomes head
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create new node for each element
        mover->next = temp;            // Link current node to next
        mover = mover->next;           // Move forward in the list
    }
    return head;  // Return head of the linked list
}

class Solution{
    private:
    // Recursive helper to add 1 to the number
    int helper(Node* head) {
        // Base case: if at the end of the list, propagate a carry of 1
        if (head == nullptr) {
            return 1;
        }
        // Recurse to the end and get carry from next node
        int carry = helper(head->next);

        // Add carry to current node’s value
        int val = head->data + carry;

        if (val < 10) {
            head->data = val;
            return 0; // No further carry needed
        }

        // If val is 10, set current to 0 and pass carry 1 upwards
        head->data = 0;
        return 1;
    }

    public:
    // Adds 1 to the number represented by linked list
    Node* add1tonum(Node* head) {
        int carry = helper(head);

        // If carry still exists after full traversal (e.g. 999 → 000), add a new node
        if (carry) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            return newNode;
        }

        return head;
    }

};
int main() {
    // Input: number 999 represented as linked list
    vector<int> arr = {9, 9,9,9,9,9, 8};

    // Convert to linked list
    Node* head = ConvertArrToLL(arr);

    // Add 1 to the number
    Solution sol;
    head=sol.add1tonum(head);

    // Print resulting linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
