#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node *next ;
    
    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }
} ;

void insertAtHead(Node* &head, int data){
    Node *newNode = new Node(data) ;
    newNode -> next = head ;
    head = newNode ;
}

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data) ;
    tail->next = newNode ;
    tail = newNode ;
}

void insertAtPos(Node* &head, Node* &tail, int position, int data){
    //insertion at start
    if (position == 1){
        insertAtHead(head, data);
        return ;
    }
    --position ;
    int i=1 ;
    Node* temp = head ;
    while (i<position){
        temp = temp->next ;
        i++ ;
    }
    
    //insertion at last
    if (temp->next == NULL){
        insertAtTail(tail, data) ;
        return ;
    }
    
    if (temp == NULL){
        cout << "Linked List is shorter than position" << endl ;
        return ;
    }
    Node* newNode = new Node(data) ;
    newNode->next = temp->next ;
    temp->next = newNode ;
}

void deleteAtHead(Node* &head){
    Node* temp = head ;
    head = head->next ;
    delete temp ;
}

void deleteAtTail(Node* &head, Node* &tail){
    Node* temp = head ;
    while (temp->next->next != NULL){
        temp = temp->next ;
    }
    tail = temp ;
    temp = temp->next ;
    tail->next = NULL ;
    // cout << "tail is : " << tail->data << endl ;
    delete temp ; ;
}

void deleteAtPos(Node* &head, Node* &tail, int position){
    if (position == 1){
        deleteAtHead(head) ;
        return ;
    }
    int i=1 ;
    --position ;
    Node* temp = head ;
    while (i<position){
        temp = temp->next ;
        i++ ;
    }
    if (temp->next->next == NULL){
        deleteAtTail(head, tail) ;
        return ; 
    }
    
    Node *temp2 = temp->next ;
    temp->next = temp2->next ;
    delete temp2 ;
}

void print(Node* &head){
    Node* temp = head ;
    while (temp != NULL){
        cout << temp -> data << " " ;
        temp = temp->next ;
    }
    cout << endl ;
}

int main(){
    Node * node1 = new Node(10) ;
    Node* head = node1 ;
    Node* tail = node1 ;
    
    insertAtTail(tail, 20) ;
    print(head) ;
    insertAtHead(head, 30) ;
    print(head) ;
    insertAtPos(head, tail, 4, 36) ;
    print(head) ;
    deleteAtPos(head, tail, 4) ;
    print(head) ;
}