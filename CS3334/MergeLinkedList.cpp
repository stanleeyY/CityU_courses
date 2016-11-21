#include <iostream>
#include "Node.h"
#include "Node.cpp"
using namespace std;

Node* merge(Node* A, Node* B) {
    Node *C = NULL;
    while (A != NULL && B != NULL) {
        if (A->getData() < B->getData()) {
            //list.add(*A)
            if (C == NULL)
                C = new Node(A->getData(), NULL);
            else {
                Node *temp = new Node(A->getData(), C);
                Node *oldc=C;
                C = temp;
                C->setNext(oldc);
            }
            //A.headErase()
            Node *temp = A;
            A = temp->getNext();
            Node *tail = A;
            while (tail->getNext() != temp)
                tail = tail->getNext();
            if (A == temp)
                A = NULL;
            tail->setNext(A);
            delete temp;
        } else {
            //list.add(*B)
            if (C == NULL)
                C = new Node(B->getData(), NULL);
            else {
                Node *temp = new Node(B->getData(), C);
                Node *oldc=C;
                C = temp;
                C->setNext(oldc);
            }
            //B.headErase()
            Node *temp = B;
            B = temp->getNext();
            Node *tail = B;
            while (tail->getNext() != temp)
                tail = tail->getNext();
            if (B == temp)
                B = NULL;
            tail->setNext(B);
            delete temp;
        }
    }
    if (A == NULL) {
        while (B != NULL) {
            //list.add(*B)
            if (C == NULL)
                C = new Node(B->getData(), NULL);
            else {
                Node *temp = new Node(B->getData(), C);
                Node *oldc=C;
                C = temp;
                C->setNext(oldc);
            }
            //B.headErase()
            Node *temp = B;
            B = temp->getNext();
            Node *tail = B;
            while (tail->getNext() != temp)
                tail = tail->getNext();
            if (B == temp)
                B = NULL;
            tail->setNext(B);
            delete temp;
        }
    } else {//B==NULL
        while (A != NULL) {
            //list.add(*A)
            if (C == NULL)
                C = new Node(A->getData(), NULL);
            else {
                Node *temp = new Node(A->getData(), C);
                Node *oldc=C;
                C = temp;
                C->setNext(oldc);
            }
            //A.headErase()
            Node *temp = A;
            A = temp->getNext();
            Node *tail = A;
            while (tail->getNext() != temp)
                tail = tail->getNext();
            if (A == temp)
                A = NULL;
            tail->setNext(A);
            delete temp;
        }
    }
    //setDummyHead
    Node* p=C;
    while(p->getNext()!=NULL)
        p=p->getNext();
    p->setNext(C);
    return C;
}

void printList(Node* A){
    if(A==NULL){
        printf("Empty List\n");
        return;
    }
    Node* p;
    for(p=A;p->getNext()!=A;p=p->getNext())
        printf("%d ", p->getData());
    printf("%d\n",p->getData());
}

int main(){
    Node* A=NULL;
    printList(A);

    Node* B=new Node(2,NULL);
    B->setNext(B);
    printList(B);

    Node* C=merge(A,B);
    printList(C);
    return 0;
}