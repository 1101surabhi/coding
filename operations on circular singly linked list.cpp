// operations on circular singly linked list

#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node* next ;
    
    Node (int data){
        this->data = data ;
        this->next = NULL ;
    }
} ;

void insertNode(Node* &tail, int element, int data){
    //create node
    Node* newNode = new Node(data) ;
    
    //linked list is empty
    if (tail == NULL){
        newNode -> next = newNode ;
        tail = newNode ;
        return ;
    }
    
    if (tail -> data == element){
        newNode -> next = tail -> next ;
        tail -> next = newNode ;
        return ;
    }
    
    Node* temp = tail ;
    while (temp->data != element){
        temp = temp -> next ;
        if (temp == tail){
            cout << element << " not found in linked list" << endl ;
            return ;
        }
    }
    
    //element found
    newNode -> next = temp -> next  ;
    temp -> next = newNode ;
    return ;
}

void deleteNode(Node* &tail, int element){
    Node* prev = tail ;
    Node* temp = prev -> next ;
    while (temp->data != element){
        prev = temp ;
        temp = temp -> next ;
        if (temp == tail && temp->data != element){
            cout << element << " not found in linked list" << endl ;
            return ;
        }
    }
    
    if (prev == temp){
        tail = NULL ;
        delete temp ;
        return ;
    }
    
    prev -> next = temp -> next ;
    temp -> next = NULL ;
    if (tail == temp){
        tail = prev ;
    }
    delete temp ;
}

void print(Node* &tail){
    if (tail == NULL) {
        cout << "Linked list is empty." << endl ;
        return ;
    }
    Node* temp = tail ;
    do {
        cout << temp -> data << " " ;
        temp = temp -> next ;
    } while (temp != tail) ;
    cout << endl ;
}

int main(){
    Node* tail = NULL ;
    insertNode(tail, 3, 1) ;
    insertNode(tail, 1, 2) ;
    insertNode(tail, 3, 4) ;
    insertNode(tail, 2, 4) ;
    insertNode(tail, 2, 5) ;
    deleteNode(tail, 1) ;
    deleteNode(tail, 4) ;
    deleteNode(tail, 2) ;
    deleteNode(tail, 5) ;
    // cout << "inserted" ;
    cout << "current linked list is : " ;
    print(tail) ;
}
