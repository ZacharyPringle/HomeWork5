//
// Created by zpringle on 12/7/2021.
//

#include <iostream>
#include "listtoolshb.h"
using namespace std;
template<class T>
void MyList<T>::insertHead(T theData, Node<T>* head) {
    head = new Node<T>(theData);
}
template <class T>
void MyList<T>:: display(Node<T>*head) {
    Node<T>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}
template<class T>
void MyList<T>::insert(Node<T>* afterMe, const T& theData) {
    afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
}
template<class T>
void MyList<T>::deleteNode(Node<T>* before) {
    Node<T> *discard;
    discard = before->getLink( );
    before->setLink(discard->getLink( ));
    delete discard;
}
template<class T>
void MyList<T>::deleteFirstNode(Node<T>*& head) {
    Node<T> *discard;
    discard = head;
    head = head->getLink( );
    delete discard;
}

template<class T>
Node<T>* search(Node<T>* head, const T& target) {
    Node<T>* here = head;
    if (here == NULL)  {
        return NULL;
    }
    else {
        while (here->getData( ) != target && here->getLink( ) != NULL)
            here = here->getLink( );
        if (here->getData( ) == target)
            return here;
        else
            return NULL;
    }
}