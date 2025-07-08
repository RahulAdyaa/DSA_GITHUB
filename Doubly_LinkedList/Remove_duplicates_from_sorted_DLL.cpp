#include<iostream>
#include<vector>
using namespace std;

// Definition of a Node in a Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor to initialize a single node
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    // Constructor with next and back pointers
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Converts an array to a Doubly Linked List
Node* convertarrtoDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);   // Create head node
    Node* prev = head;

    // Loop through array and create DLL nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);  // Link back to previous node
        prev->next = temp;  // Set next of previous node
        prev = temp;        // Move previous pointer forward
    }
    return head;  // Return head of the constructed DLL
}

// Prints the elements of the Doubly Linked List
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Removes consecutive duplicate elements from the sorted DLL
Node* NoDuplicates(Node* head) {
    Node* temp = head;

    // If list is empty or has only one node, return as-is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Traverse the list
    while (temp != nullptr) {
        Node* nextNode = temp->next;

        // Delete all nodes with duplicate values
        while (nextNode != nullptr && nextNode->data == temp->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete(duplicate);  // Free memory of duplicate node
        }

        // Update links to bypass duplicates
        temp->next = nextNode;
        if (nextNode != nullptr) {
            nextNode->back = temp;
        }

        temp = temp->next;  // Move to the next distinct node
    }

    return head;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4};  // Input array with duplicates
    Node* head = convertarrtoDLL(arr);       // Convert to DLL
    head = NoDuplicates(head);               // Remove duplicates
    print(head);                             // Print result
}
