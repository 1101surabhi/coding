//operations on doubly linked list

#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node* prev ;
    Node* next ;
    
    Node(int data){
        this->data = data ;
        this->prev = NULL ;
        this->next = NULL ;
    }
} ;

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data) ;
    if (!head){
        head = temp ;
        return ;
    }
    temp -> next = head ;
    head -> prev = temp ;
    head = temp ;
}

void insertAtTail(Node* &head, int data){
    Node* temp = new Node(data) ;
    Node* last = head ;
    while (last->next != NULL){
        last = last -> next ;
    }
    temp -> prev = last ;
    last -> next = temp ;
}

void insertAtPos(Node* &head, int data, int pos){
    if (pos == 1){
        insertAtHead(head, data) ;
        return ;
    }
    
    Node* temp = head ;
    while (temp != NULL){
        --pos ;
        if (pos == 1) break ;
        temp = temp -> next ;
    }
    
    if (pos >= 1 && temp == NULL){
        cout << "Linked list is shorter than this position." << endl ;
        return ;
    }
    else if (pos == 1 && temp->next == NULL){
        insertAtTail(head, data) ;
        return ;
    }
    
    Node* newNode = new Node(data) ;
    newNode -> next = temp -> next ;
    newNode -> prev = temp ;
    temp -> next -> prev = newNode ;
    temp -> next = newNode ;
}

void deleteAtHead(Node* &head){
    Node* temp = head ;
    head = head -> next ;
    head -> prev = NULL ;
    delete temp ;
}

void deleteAtTail(Node* &head){
    Node* temp = head ;
    while (temp -> next != NULL){
        temp = temp -> next ;
    }
    temp -> prev -> next = NULL ;
    delete temp ;
}

void deleteAtPos(Node* &head, int pos){
    if (pos == 1){
        deleteAtHead(head) ;
        return ;
    }
    Node* temp = head ;
    while (temp != NULL){
        --pos ;
        if (pos == 1) break ;
        temp = temp -> next ;
    }
    
    //deleting a node whose pos is not in the list
    if (pos >= 1 && temp == NULL){
        cout << "Linked list is shorted than this position" << endl ;
        return ;
    }
    
    //deleting last node of linked list
    if (pos == 1 && temp->next->next == NULL){
        deleteAtTail(head) ;
        return ;
    }
    
    //deleting node present at pos
    Node* delNode = temp -> next ;
    temp -> next = delNode -> next ;
    delNode -> next -> prev = temp ;
    delete delNode ;
}

void print(Node* &head){
    Node* temp = head ;
    while (temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next ;
    }
    cout << endl ;
}

void printReverse(Node* &head){
    Node* temp = head ;
    while (temp->next != NULL){
        temp = temp -> next ;
    }
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> prev ;
    }
    cout << endl ;
}

int getLength(Node* &head){
    int count = 0 ;
    Node* t = head ;
    while (t != NULL){
        ++count ;
        t = t -> next ;
    }
    return count ;
}

int main(){
    // Node* n = new Node(1) ;
    Node* head = NULL ;
    // Node* tail = n ;
    insertAtHead(head, 1) ;
    insertAtHead(head, 2) ;
    insertAtHead(head, 3) ;
    insertAtTail(head, 4) ;
    insertAtTail(head, 5) ;
    insertAtPos(head, 6, 1) ;
    insertAtPos(head, 7, 3) ;
    insertAtPos(head, 8, 6) ;
    // insertAtPos(head, 9, 9) ;
    // insertAtPos(head, 0, 10) ;
    deleteAtHead(head) ;
    deleteAtTail(head) ;
    deleteAtPos(head, 1) ;
    deleteAtPos(head, 5) ;
    deleteAtPos(head, 3) ;
    print(head) ;
    // printReverse(head) ;
    cout << "Length of linked list is : " << getLength(head) << endl ;
}
