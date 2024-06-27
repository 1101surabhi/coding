#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node* next ;
    Node* prev ;

    Node(int data){
        this->data = data ;
        this->next = NULL ;
        this->prev = NULL ;
    }
} ;

//insertion at Beginning in doubly linked list
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data) ;
    if (head == NULL){
        head = newNode ;
        return ;
    }
    head->prev = newNode ;
    newNode->next = head ;
    head = newNode ;
}

//insertion at End in doubly linked list
void insertAtEnd(Node* &head, int data){
    Node* newNode = new Node(data) ;

    Node* temp = head ;
    while (temp->next != NULL){
        temp = temp->next ;
    }
    newNode->prev = temp ;
    temp->next = newNode ;
}

//insertion at given position in double linked list
void insertAtPos(Node* &head, int position, int data){
    if (position == 1){
        insertAtHead(head, data) ;
        return ;
    }

    --position ;
    int i=1 ;
    Node* temp = head ;
    while(i < position){
        temp = temp->next ;
        i++ ;
    }
    //inserting at last position
    if (temp->next == NULL){
        insertAtEnd(head, data) ;
        return ;
    }

    if (temp == NULL){
        cout << "Linked list is shorter than position" << endl ;
        return ;
    }
    Node* newNode = new Node(data) ;
    newNode->prev = temp ;
    newNode->next = temp->next ;
    temp->next->prev = newNode ;
    temp->next = newNode ;
}

void deleteAtHead(Node* &head){
    Node* temp = head ;
    head->next->prev = NULL ;
    head = head->next ;
    temp->next = NULL ;
    delete temp ;
}

void deleteAtEnd(Node *head){
    Node * temp = head ;
    while (temp->next != NULL){
        temp = temp->next ;
    }
    temp->prev->next = NULL ;
    delete temp ;
}

void deleteAtPos(Node* &head, int pos){
    if (pos == 1){
        deleteAtHead(head) ;
        return ;
    }
    Node* temp = head ;
    int i=1; 
    while (i < pos){
        temp = temp->next ;
        i++ ;
    }
    if (temp->next == NULL){
        deleteAtEnd(head) ;
        return ;
    }
    temp->prev->next = temp->next ;
    temp->next->prev = temp->prev ;
    delete temp ;
}

//traversing doubly linked list
void print(Node* &head){
    if (head == NULL){
        cout << "Linked List is empty" << endl ;
        return ;
    }
    Node* temp = head ;
    while (temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next ;
    }
    cout << endl ;
}

//get length of linked list
int getLength(Node* &head){
    int len = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        len++ ;
        temp = temp->next ;
    }
    return len ;
}

int main(){
    Node* head = NULL ;
    print(head) ;
    cout << getLength(head) << endl ;

    insertAtHead(head, 11) ;
    print(head) ;
    insertAtHead(head, 74) ;
    insertAtEnd(head, 72) ;
    insertAtEnd(head, 27) ;
    insertAtPos(head, 5, 25) ;
    insertAtPos(head, 6, 22) ;
    deleteAtHead(head) ;
    deleteAtEnd(head) ;
    deleteAtPos(head, 1) ;
    print(head) ;
}