#include<iostream>
using namespace std;

// Definition of singly linked list node
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

// Converts a vector of integers to a linked list and returns the head
Node* ConvertArrToLL(vector<int> arr) {
    Node* head = new Node(arr[0]);     // Initialize head with first element
    Node* mover = head;                // Pointer to build the list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create new node
        mover->next = temp;            // Link new node
        mover = mover->next;           // Move to new node
    }
    return head;
}

// Reverses a linked list and returns the new head
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* temp = head;
    while (temp != nullptr) {
        Node* front = temp->next;  // Store next node
        temp->next = prev;         // Reverse the link
        prev = temp;               // Move prev forward
        temp = front;              // Move temp forward
    }
    return prev;                   // New head of reversed list
}

// Returns the kth node from the current node (1-based index)
Node* getKthNode(Node* temp, int k) {
    k = k - 1; // We already count the current node as the first
    while (temp != nullptr && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp; // Returns nullptr if less than k nodes left
}

// Reverses nodes in groups of k in the linked list
Node* reverseKNodes(Node* head, int k) {
    Node* temp = head;         // Pointer to traverse the list
    Node* prevNode = nullptr;  // End of the previous processed group

    while (temp != nullptr) {
        Node* kthNode = getKthNode(temp, k); // Find the kth node
        if (kthNode == nullptr) {
            // If fewer than k nodes remain, leave them as-is
            if (prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = kthNode->next; // Store the next group's start
        kthNode->next = nullptr;        // Temporarily break the link

        reverse(temp);                  // Reverse the current group

        // Connect previous group to the new head of reversed group
        if (temp == head) {
            head = kthNode;             // Update head for the first group
        } else {
            prevNode->next = kthNode;
        }

        prevNode = temp;                // `temp` is now the tail of reversed group
        temp = nextNode;                // Move to next group
    }

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};          // Input array
    Node* head = ConvertArrToLL(arr);          // Convert array to linked list

    head = reverseKNodes(head, 2);             // Reverse in groups of k=2

    Node* temp = head;
    while (temp != nullptr) {                  // Print the modified list
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
