//Insert node at head of linked list and print linked list.

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
    insertAtHead(head, 30) ;
    print(head) ;
}
