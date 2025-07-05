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

void deleteNode(Node* node) {
        if (node == nullptr || node->next == nullptr) {
        return;
    }
        node->data = node->next->data;           // Copy value from next node
        Node* temp = node->next;           // Save pointer to next node
        node->next = node->next->next;         // Skip over the next node
        delete temp;                           // Delete the next node
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    Node* head=ConvertArrToLL(arr);
    Node* nodeToDelete = head; // Assuming you want to delete the first node
    for (int i = 0; i < 1 && nodeToDelete != nullptr; i++) {
        nodeToDelete = nodeToDelete->next; // Move to the 5th node
    }
    if (nodeToDelete != nullptr) {
         deleteNode(nodeToDelete); // Delete the 5th node
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}