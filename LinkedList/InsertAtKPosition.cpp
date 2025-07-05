
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
        mover->next=temp; // mover's next is temp 
        mover=mover->next; //mover moves
    }
    return head;
}
Node* insertAtK(Node* head , int k , int val){
    Node *newNode = new Node(val);
    if(head==nullptr){
        if(k==1){
            return newNode; // If the list is empty and k is 1, return the new node as the head
        }
    }
    if(k==1){
        newNode->next = head; // If k is 1, insert at the head
        return newNode; // Return the new head
    }

    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        count++;
        if(count==k-1){
            newNode->next = temp->next; // Link the new node to the next node
            temp->next = newNode; // Link the previous node to the new node
            break;
        }
        temp = temp->next; // Move to the next node
    }
    return head; // Return the original head
}
int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    
    head=insertAtK(head,2,20);

    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}