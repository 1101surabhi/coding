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

//insertion in circular linked list
void insertNode(Node* &tail, int element, int data){
    if (tail == NULL){
        Node* newNode = new Node(data) ;
        tail = newNode ;
        newNode -> next = newNode ;
    }
    else {
        Node* curr = tail ;
        while (curr->data != element){
            curr = curr -> next ;
            if (curr == tail){
                cout << "element not found." << endl ;
                return ;
            }
        }
        Node* newNode = new Node(data) ;
        newNode->next = curr->next ;
        curr->next = newNode ;
    }
}

//deletion in circular linked list
void deleteNode(Node* &tail, int element){
    if (tail == NULL){
        cout << "linked list is empty" << endl ;
        return ;
    }
    if (tail->next == tail){
        delete tail ;
        tail = NULL ;
        return ;
    }
    Node* prev = tail ;
    Node* curr = prev->next ;
    while (curr->data != element){
        prev = curr ;
        curr = curr -> next ;
    }
    prev->next = curr->next ;
    if (tail == curr){
        tail = curr->next ;
    }
    curr -> next = NULL ;
    delete curr ;
}

void print(Node* &tail){
    if (tail == NULL){
        cout << "linked list is empty" << endl ;
        return ;
    }
    Node* temp = tail ;
    do {
        cout << temp->data << " " ;
        temp = temp->next ;
    } while (temp != tail) ;
    cout << endl ;
}

int main(){
    Node* tail = NULL ;
    insertNode(tail, 5, 3) ;
    // print(tail) ;
    insertNode(tail, 3, 1) ;
    insertNode(tail, 1, 10) ;
    insertNode(tail, 1, 4) ;
    insertNode(tail, 10, 5) ;
    insertNode(tail, 3, 2) ;
    insertNode(tail, 4, 9) ;
    insertNode(tail, 2, 2) ;
    deleteNode(tail, 3) ;
    deleteNode(tail, 1) ;
    deleteNode(tail, 10) ;
    deleteNode(tail, 2) ;
    deleteNode(tail, 4) ;
    deleteNode(tail, 2) ;
    deleteNode(tail, 9) ;
    deleteNode(tail, 5) ;
    print(tail) ;
}