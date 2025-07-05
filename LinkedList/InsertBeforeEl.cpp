
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
Node* insertBeforeEl(Node* head, int el, int val){
    Node* newNode=new Node(val);
    if(head==nullptr){
        return nullptr; // If the list is empty, return nullptr
    }    
    if(head->data==val){
        newNode->next=head;
        return newNode; // If the element to insert before is the head, return the new node as the new head
    }
    Node* temp = head;
    
    while(temp->next!=nullptr){
       
        
        if(temp->next->data ==el){
            newNode->next=temp->next;
            temp->next = newNode; // Link the previous node to the new node
            break; // Exit the loop after inserting the new node
        }
        temp = temp->next; // Move to the next node

    }
    return head; // Return the original head
}
int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);

    // Insert a new node before a specific element (for example, before 3)
    head=insertBeforeEl(head,3,20);

    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}