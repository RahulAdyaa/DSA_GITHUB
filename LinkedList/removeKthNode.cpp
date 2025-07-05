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
Node* removeK(Node* head ,int k){
    if(head == nullptr || k <= 0) {
        return head; // If the list is empty or k is not positive, return the original list
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp); // Delete the first node
        return head; // Return the modified list
    }
    int count = 0;
    Node *temp=head;
    Node *prev = nullptr;
    while(temp!=nullptr){
        count++;
        if(k==count){
            prev->next = prev->next->next; // Remove the k-th node
            free(temp); // Delete the k-th node
            break; // Exit the loop after removing the k-th node
        }
        prev=temp;
        temp=temp->next;
    }
    return head; // Return the modified list
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    int k = 2;
    head = removeK(head, k);

    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}