/**
 * Intuition:
 * The binary number is stored in a linked list, where each node represents a bit (0 or 1).
 * We want to convert this binary number into its decimal form.
 * We do this by traversing the linked list and treating it like we would build a number from left to right:
 * Every time we move to the next bit, we shift the current result to the left (multiply by 2)
 * and add the new bit using bitwise OR.
 */

#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Convert array to singly linked list
Node* convertarrtoLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

// Convert binary linked list to decimal number
int convertLLtonumber(Node* head) {
    int result = 0;
    Node* temp = head;

    while (temp != nullptr) {
        result = (result * 2) | temp->data; // Left shift and add current bit
        temp = temp->next;
    }
    return result;
}

int main() {
    vector<int> arr = {1, 0, 1};
    Node* head = convertarrtoLL(arr);
    cout << convertLLtonumber(head) << endl;
}
