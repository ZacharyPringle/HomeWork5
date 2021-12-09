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
    while(temp!=NULL)
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
    return discard->getData();
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
            cout << "Found\n____________________________________________\n" << endl;
            return true;
        }
        else{
            cout << "Not Found"<<endl;
            return false;
        }
    }
}