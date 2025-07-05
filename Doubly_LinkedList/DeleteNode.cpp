#include<iostream>

            // very important
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};
Node* convertarrtoDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next = temp; // Link the previous node to the new node
        prev = temp; // Move to the new node

    }
    return head; // Return the head of the doubly linked list
}

Node* deleteNode(Node* head,Node* temp){
        Node* prev=temp->back;
    Node* front=temp->next;
    if (temp == nullptr) return head;

   
    // Case 1: Node is the only node
    if (temp->back == nullptr && temp->next == nullptr) {
        delete temp;
        return head ;
    }
    // Case 2: Node is the head
    if (temp->back == nullptr) {
        head = head->next;
        head->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    if(front==nullptr){
        prev->next=nullptr;
        temp->back = nullptr; 
        delete temp; 
        return head;
    }

    prev->next = front; 
    front->back = prev; 
    temp->next = nullptr; 
    temp->back = nullptr; 
    delete temp; 
    return head;
   
}

void print(Node* head){
    //print the linkedlist
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next; // Move to the next node
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertarrtoDLL(arr);

    cout << "Original list:\n";
    print(head);

    // Delete the 1st node (head)
    head=deleteNode(head, head);

    cout << "After deleting head:\n";
    print(head);

    // Delete the new 4th node
    Node* temp = head;
    for (int i = 1; i < 4; i++) {
        temp = temp->next;
    }
    head=deleteNode(head, temp);

    cout << "After deleting 4th node:\n";
    print(head);
}