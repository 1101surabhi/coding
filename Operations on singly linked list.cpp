#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node* next ;
    
    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }
} ;

void insertAtHead(Node* &head, int data){
    Node* n = new Node(data) ;
    n->next = head ;
    head = n ;
}

void insertAtTail(Node* &head, int data){
    Node* n = new Node(data) ;
    Node* temp = head ;
    while (temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = n ;
}

void insertAtPos(Node* &head, int data, int pos){
    if (pos == 1){
        insertAtHead(head, data) ;
        return ;
    }
    int cnt = 1 ;
    Node* temp = head ;
    while (cnt < pos-1){
        temp = temp -> next ;
        cnt++ ;
        if (temp == NULL){
            cout << "Linked list is shorted than this" << endl ;
            return ;
        }
    }
    Node* newNode = new Node(data) ;
    newNode -> next = temp -> next ;
    temp -> next = newNode ;
}

void deleteAtPos(Node* &head, int pos){
    int count = 1 ;
    Node* temp = head ;
    if (pos == 1){
        head = temp -> next ;
        delete temp ;
        return ;
    }
    while (count < pos-1 && temp != NULL){
        temp = temp -> next ;
        count++ ;
    }
    if (temp == NULL || temp -> next == NULL){
        cout << "Linked list is shorter than this position." << endl;
        return;
    }
    Node* delNode = temp -> next ;
    temp -> next = temp -> next -> next ;
    delete delNode ;
}

void print(Node* &head){
    Node* temp = head ;
    while (temp != NULL){
        cout << temp->data << " " ;
        temp = temp -> next ;
    }
}

int main(){
    Node* n = new Node(10) ;
    Node* head = n ;
    insertAtHead(head, 22) ;
    print(head) ;
    cout << endl ;
    insertAtTail(head, 30) ;
    print(head) ;
    cout << endl ;
    insertAtTail(head, 40) ;
    print(head) ;
    cout << endl ;
    insertAtPos(head, 50, 3) ;
    print(head) ;
    cout << endl ;
    insertAtPos(head, 1, 1) ;
    print(head) ;
    cout << endl ;
    insertAtPos(head, 60, 7) ;
    print(head) ;
    cout << endl ;
    insertAtPos(head, 70, 8) ;
    print(head) ;
    cout << endl ;
    deleteAtPos(head, 1) ;
    print(head) ;
    cout << endl ;
    deleteAtPos(head, 2) ;
    print(head) ;
    cout << endl ;
    deleteAtPos(head, 6) ;
    print(head) ;
    cout << endl ;
    deleteAtPos(head, 6) ;
    print(head) ;
    cout << endl ;
}
