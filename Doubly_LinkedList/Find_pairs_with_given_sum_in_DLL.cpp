#include <iostream>
#include <vector>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor for single node
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    // Constructor with connections
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to convert an array into a Doubly Linked List
Node* convertarrtoDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);       // Create the first node
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        // Create new node with previous node linked
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;               // Link current node to previous
        prev = temp;                     // Move prev to current node
    }
    return head;
}

// Utility function to print the Doubly Linked List from head to tail
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
private:
    // Helper to find the last node (tail) of the DLL
    Node* FindTail(Node* head) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

public:
    // Finds all pairs in the sorted DLL that sum up to a given value
    vector<pair<int, int>> FindPairs(Node* head, int val) {
        vector<pair<int, int>> ds;
        Node* left = head;               // Pointer to start of list
        Node* right = FindTail(head);    // Pointer to end of list

        // Use two-pointer technique to find pairs with target sum
        while (left != nullptr && right != nullptr && left != right && left->data < right->data) {
            int sum = left->data + right->data;

            if (sum == val) {
                ds.push_back({left->data, right->data}); // Valid pair found
                left = left->next;
                right = right->back;
            }
            else if (sum < val) {
                left = left->next;       // Move left to larger value
            }
            else {
                right = right->back;     // Move right to smaller value
            }
        }
        return ds;
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    // Step 1: Convert array to Doubly Linked List
    Node* head = convertarrtoDLL(arr);

    // Step 2: Find all pairs whose sum equals the target
    Solution sol;
    vector<pair<int, int>> pairs = sol.FindPairs(head, 10);

    // Step 3: Print the found pairs
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
