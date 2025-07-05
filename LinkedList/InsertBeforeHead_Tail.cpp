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
Node *removeHead(Node* head) {
    if (head == nullptr) {
        return nullptr; // If the list is empty, return nullptr
    }
    Node* newHead = head->next; // Store the next node
    delete head; // Delete the current head
    return newHead; // Return the new head
}
void deleteNode(Node* node) {
        node->data = node->next->data;           // Copy value from next node
        Node* temp = node->next;           // Save pointer to next node
        node->next = node->next->next;         // Skip over the next node
        delete temp;                           // Delete the next node
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

Node *insertAtHead(Node *head , int data){
    Node *temp=new Node(data);
    temp->next=head; // Point the new node to the current head
    return temp; // Return the new head
}

Node *InsertAtTail(Node *head ,int val){
    Node *temp=head;
    Node *newNode=new Node(val);
    if(head==nullptr){
        return temp; // If the list is empty, return the new node as the head
    }
    while(temp->next!=nullptr){
        temp = temp->next; // Move to the end of the list
    }
    temp->next = newNode; // Link the new node at the end of the list
    return head; // Return the original head
}



int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* head = ConvertArrToLL(arr);

   
    // Insert a new node at the head of the linked list
    head = insertAtHead(head, 0);

    // Insert a new node at the tail of the linked list
    head = InsertAtTail(head, 0);

   
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout<<endl;
    
    
}

