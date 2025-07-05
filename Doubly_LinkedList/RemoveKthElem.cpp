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
Node* deleteHead(Node* head){
    Node* prev=head;
    if(head==nullptr || head->next==nullptr){
        return nullptr; // If the list is empty or has only one node, return nullptr
    }
    head=head->next;
    head->back=nullptr;
    prev->next = nullptr; // Disconnect the old head
    delete prev; // Delete the old head
    return head; // Return the new head

}
Node* DeleteTail(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr; // If the list is empty or has only one node, return nullptr
    }
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next; // Move to the second last node
    }
    Node* nextnode=temp->next; // Store the last node
    temp->next = nullptr; // Set the next of the second last node to nullptr
    nextnode->back = nullptr; // Disconnect the last node from the second last node
    delete nextnode; // Delete the last node

    return head; // Return the modified list
}

Node* removekthelement(Node* head,int k){
    if(head==nullptr){
        return nullptr; // If the list is empty, return nullptr
    }
    int cnt=0;
    Node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp = temp->next; // Move to the next node
    }

    Node* prev = temp->back; // Store the previous node
    Node* front = temp->next; // Store the next node
    if(prev==nullptr && front==nullptr){
        delete temp; // If the node is the only node, delete it
        return nullptr; // Return nullptr
    }
    else if(front==nullptr){
        DeleteTail(head); // If the node is the tail, delete the tail
        return head; // Return the modified list
    }
    else if(prev == nullptr){
    head = deleteHead(head); // assign new head
    return head;
    }

    front->back= prev; 
    prev->next= front;

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

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertarrtoDLL(arr);
    head=removekthelement(head,1);

    print(head);
    
    
}