#include<iostream>
using namespace std;

// Definition for singly linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor for node with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    // Constructor for node with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to convert a vector into a linked list
Node* ConvertArrToLL(vector<int> arr) {
    Node* head = new Node(arr[0]);    // First node
    Node* mover = head;               // Used to build the list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);  // Create new node
        mover->next = temp;             // Link it to the list
        mover = mover->next;            // Move forward
    }
    return head;
}

// Function to find the kth node (1-based index) in the list
Node* findKthNode(Node* head, int k) {
    int cnt = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (cnt == k) return temp;  // Return kth node
        cnt++;
        temp = temp->next;
    }
    return temp; // nullptr if list is shorter than k
}

// Function to rotate linked list to the right by k places
Node* rotate(Node* head, int k) {
    // Base cases: empty list or only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find length of the list and last node (tail)
    Node* tail = head;
    int len = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    // If k is a multiple of length, rotation results in same list
    if (k % len == 0) return head;
    k = k % len;  // Reduce k if it's more than length

    // Make the list circular temporarily
    tail->next = head;

    // Find the new tail: (len - k)th node
    Node* newlastnode = findKthNode(head, len - k);

    // The new head is the node after the new tail
    head = newlastnode->next;

    // Break the circle to finalize the rotation
    newlastnode->next = nullptr;

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};     // Input array
    Node* head = ConvertArrToLL(arr);     // Convert to linked list

    head = rotate(head, 5);               // Rotate list by k = 5 positions

    // Print the final rotated list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
