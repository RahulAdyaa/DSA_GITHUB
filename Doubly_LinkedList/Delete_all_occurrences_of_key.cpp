#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* convertarrtoDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteOccurrences(Node* head, int val) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            Node* prevNode = temp->back;
            Node* nextNode = temp->next;

            if (prevNode) prevNode->next = nextNode;
            else head = nextNode;  // deleting the head and moving it forward

            if (nextNode) nextNode->back = prevNode;

            Node* toDelete = temp;
            temp = nextNode;
            delete toDelete;  // Correct deallocation
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {1, 1, 1, 1, 2, 3, 1, 2};
    Node* head = convertarrtoDLL(arr);
    head = deleteOccurrences(head, 1);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
