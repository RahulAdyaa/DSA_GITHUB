#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};
Node* ConvertArrToLL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
Node* removeTail(Node*head){
    if(head==nullptr || head->next==nullptr){
        return nullptr; // If the list is empty or has only one node, return nullptr
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next; // Move to the second last node    
    }
    delete current->next; // Delete the last node
    current->next = nullptr; // Set the next of the second last node to nullptr
    return head; // Return the modified list
}
int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    head=removeTail(head);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}