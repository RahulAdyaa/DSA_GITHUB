#include<iostream>
using namespace std;
class Node{
    public:
    int data; //variable declaration
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
int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);

    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}