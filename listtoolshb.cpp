//
// Created by zpringle on 12/7/2021.
//

#include <iostream>
#include "listtoolshb.h"
using namespace std;
template<class T>
void MyList<T>::insertHead(T theData) {
    head = new Node<T>(theData, head);
}
template <class T>
void MyList<T>:: display() {
    Node<T>*temp=head;
    while(head!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}

template<class T>
T MyList<T>::deleteHead() {
    Node<T> *discard;
    discard = head;
    head = head->getLink();
    delete discard;
}

template<class T>
bool MyList<T>:: search(T& target) {
    Node<T>* here = head;
    if (here == NULL)  {
        return false;
    }
    else {
        while (here->getData( ) != target && here->getLink( ) != NULL)
            here = here->getLink( );
        if (here->getData( ) == target){
            cout << "True";
            return true;
        }
        else{
            cout << "False";
            return false;
        }
    }
}