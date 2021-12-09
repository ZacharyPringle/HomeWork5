//
// Created by zpringle on 12/7/2021.
//

#include <iostream>
#include "listtoolshb.h"
using namespace std;

//inserts a data into a new head pointer that points to the old head pointer
template<class T>
void MyList<T>::insertHead(T theData) {
    head = new Node<T>(theData, head);
}

//displays the contents of the list by searching temp till it hits the last link which is NULL
template <class T>
void MyList<T>:: display() {
    Node<T>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}

//deletes the head pointer and sets the new head to the link the head was pointing to
template<class T>
T MyList<T>::deleteHead() {
    Node<T> *discard;
    discard = head;
    head = head->getLink();
    return discard->getData();
}

//searches the list till it finds either the target data or NULL if data is there it returns true
// if not it returns false
template<class T>
bool MyList<T>:: search(T& target) {
    Node<T>* here = head;
    if (here == NULL)  {
        cout << "Not Found\n____________________________________________\n" << endl;
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
            cout << "Not Found\n____________________________________________\n"<<endl;
            return false;
        }
    }
}