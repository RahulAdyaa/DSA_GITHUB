#include<iostream>
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

void print(Node* head){
    //print the linkedlist
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next; // Move to the next node
    }
    cout<<endl;
}
Node* InsertAtK(Node* head , int k , int val){
    
    if(k==1){
        Node* newNode=new Node(val);
        newNode->next = head; // If k is 1, insert at the head
        newNode->back = nullptr; // Set the back pointer of the new head to nullptr
        head->back = newNode; // Set the back pointer of the old head to the new head
        return newNode; // Return the new head
        // return Insertbeforehead(head, val); // Insert before the head
    }
    int count = 0 ;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        if(count==k){
            break;
        }
        temp = temp->next; // Move to the next node
    }
    Node* prev = temp->back; // Store the previous node
    Node* newNode=new Node(val, temp, prev); // Create a new node with the value and link it to the current node and previous node
    prev->next = newNode; // Link the previous node to the new node
    temp->back = newNode; // Link the next node to the new node    
    return head; // Return the original head
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertarrtoDLL(arr);
    head=InsertAtK(head,1,44);

    print(head);
    
    
}