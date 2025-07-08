#include<iostream>
#include<vector>
using namespace std;

// Definition of a singly linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor for creating a node with data only
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    // Constructor for creating a node with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to convert a vector of integers into a singly linked list
Node* convertarrtoLL(vector<int> arr) {
    Node* head = new Node(arr[0]);  // Create the head node
    Node* mover = head;

    // Traverse the array and link each new node to the list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;  // Return the head of the linked list
}

// Function to sort a linked list containing only 0s, 1s, and 2s
Node* sort012(Node* head) {
    // Edge case: if the list is empty or has one element
    if (head == nullptr || head->next == nullptr) return head;

    // Create dummy heads for three separate lists: 0s, 1s, and 2s
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);

    // These pointers will move as we append nodes to respective lists
    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;

    Node* temp = head;  // Iterator for traversing the original list

    // Traverse and distribute nodes into 0s, 1s, and 2s lists
    while (temp != nullptr) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else { // temp->data == 2
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Connect the 0s list to 1s list if present, else to 2s
    zero->next = (onehead->next) ? onehead->next : twohead->next;

    // Connect 1s list to 2s list
    one->next = twohead->next;

    // End the final list with null
    two->next = nullptr;

    // Return the merged list starting after dummy node
    return zerohead->next;
}

int main() {
    // Input array containing 0s, 1s, and 2s
    vector<int> arr = {0, 0, 1, 2, 0, 2, 0, 1, 1};

    // Convert array to linked list
    Node* head = convertarrtoLL(arr);

    // Sort the linked list (0s, then 1s, then 2s)
    head = sort012(head);

    // Print the sorted linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}
