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
Node* InsertBeforeTail(Node*head , int val){
    Node* newNode = new Node(val);
    Node* temp=head;
    if(head->next==nullptr){
        //this is a tail as well
        newNode->next=head;
        newNode->back = nullptr; 
        head->back =newNode;
        return newNode;
    }
    while(temp->next!=nullptr){
        temp = temp->next; 
    }
    Node* prev=temp->back;
    newNode->next=temp;
    newNode->back=prev;
    prev->next = newNode; // Link the previous node to the new node
    temp->back = newNode; // Link the new node to the last node
    return head; // Return the modified list
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertarrtoDLL(arr);
    head=InsertBeforeTail(head,90);

    print(head);
    
    
}